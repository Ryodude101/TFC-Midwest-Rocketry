#ifndef _DEFINITIONS_H_
#define _DEFINITIONS_H_

#include <Arduino.h>
#include <Status.h>
#include <IMU.h>
#include <Control.h>
#include <Time.h>

void control();
void TFR_transmit();


#define Record_period 1000000/10
#define cw_valve 0
#define ccw_valve 0


elapsedMicros T_sincePulsed;
elapsedMicros T_sinceHold;
elapsedMicros T_sinceTFR;
elapsedMicros T_lastTime;
elapsedMicros T_currentTime;


//will be more useful when programming specific directions to point to
enum cardinal_direction {
    north = 0,
    south = 180,
    east = 90,
    west = -90
}; //TODO::change numbers for control algorithm


#define MAX_NUM_COMMANDS 20 //max number of commands
int current_command = 0; //array index number, incremented in control algorithm when the commans objectives have been reached

struct command {
    cardinal_direction setpoint;
    unsigned int Hold_time;       //unsigned to make sure that time in microseconds fits
    //bool roll_direction;   //not needed yet
    bool is_done; //marked off if the command has been executed
}commands[MAX_NUM_COMMANDS]; //use array called commands to access current command from list of them


#endif
