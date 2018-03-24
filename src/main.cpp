#include <Arduino.h>

#include "Definitions.h"
#include <Status.h>
#include <IMU.h>
#include <Control.h>
#include <Time.h>


struct status_set status; //the struct holding the status of all systems
struct IMU_data data;


//loop that runs until launch
void setup() {

  while(!status.liftoff) {  //if liftoff = true, loop() starts
  IMU_all_data(); //called to get all IMU data points to send to the TFR

  }

//launch has occured, do stuff here to prep for launch loop

}


void loop() {












//Perform the neccessary control functions:
//                                       navigate to the desired point/control roll
//                                       hold current position
//                                       iterate to the next command
  if( (Error <= Allowed_error)) //check if within the error bounds
  {
      if( T_sinceHold <= Hold_time) //hold if we have not yet held for one second
          control_hold();
      else //iterate to the next command and reset the timing variables
      {
          T_sinceControl = Control_period;
          T_sinceHold = 0;
          current_command++;
      }
  }
  else
  {
      if (T_sinceControl >= Control_period) //actuate if its time for another PWM signal to be sent
      {
          T_sinceControl = T_sinceControl - Control_period;
          control_actuate();
          T_sinceHold = 0;
      }
  }

}
/*
IMU_control_data(); //called to get data needed for control algorithm
IMU_all_data(); //called to get all IMU data points to send to the TFR
check_status(); //check status struct and perform any needed actions
*/

/*
//functions that need to be called somewhere in the main loop
IMU_control_data(); //called to get data needed for control algorithm
IMU_all_data(); //called to get all IMU data points to send to the TFR
check_status(); //check status struct and perform any needed actions
*/
