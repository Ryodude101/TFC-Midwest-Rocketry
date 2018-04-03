#include "Definitions.h"

struct status_set status; //the struct holding the status of all systems
struct IMU_data data;


//loop that runs until launch
void setup() {

    while(!status.liftoff) {  //if liftoff = true, loop() starts
        TFR_transmit();
    }

//launch has occured, do stuff here to prep for launch loop

//do these when two seconds after burnout is reached
    T_sincePulsed = Control_period;
    T_sinceHold = 0;
    T_currentTime = 0;
    T_lastTime = 0;
}



void loop() {
    IMU_control_data(); //called to get data needed for control algorithm

    TFR_transmit();

    control();

    digitalWrite(cw_valve, !(T_sincePulsed <= Control_period*cw_pwm_Duty));
	digitalWrite(ccw_valve, !(T_sincePulsed <= Control_period*ccw_pwm_Duty));
}


/*
check_status(); //check status struct and perform any needed actions
*/

/*
//functions that need to be called somewhere in the main loop
IMU_control_data(); //called to get data needed for control algorithm
IMU_all_data(); //called to get all IMU data points to send to the TFR
check_status(); //check status struct and perform any needed actions
*/


//Perform the neccessary control functions:
//                                       navigate to the desired point or control roll
//                                       hold current position
//                                       iterate to the next command when conditions met
void control() {
    if (T_sincePulsed >= Control_period) {
        if (data.Error <= Allowed_error) {
            if (T_sinceHold <= commands[current_command].Hold_time) { //hold if we have not yet held for one second
                control_hold(&data);
                T_sincePulsed = T_sincePulsed - Control_period;
            }
            else { //iterate to the next command and reset the timing variables
                //T_sincePulsed = Control_period;
                T_sinceHold = 0;
                current_command++;
            }
        }
        else {
            control_actuate(&data);
            T_sincePulsed = T_sincePulsed - Control_period;
            T_sinceHold = 0;
        }
    }
}


void TFR_transmit() {
    if (T_sinceTFR >= Record_period) {
        IMU_all_data(); //called to get all IMU data points to send to the TFR
        //do the transmission stuff
        T_sinceTFR = 0;
    }
}
