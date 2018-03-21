#include <Arduino.h>

#include "definitions.h"
#include <status.h>
#include <IMU.h>
#include <control.h>


struct status_set status; //the struct holding the status of all systems
struct IMU_data data;


//loop that runs until launch
void setup() {

  while(!status.liftoff) {  //if liftoff = true, loop() starts

  }

}


void loop() {

    //IMU_control_data(); //called to get data needed for control algorithm
    IMU_all_data(); //called to get all IMU data points to send to the TFR
    check_status(); //check status struct and perform any needed actions

}
/*
//functions that need to be called somewhere in the main loop
IMU_control_data(); //called to get data needed for control algorithm
IMU_all_data(); //called to get all IMU data points to send to the TFR
check_status(); //check status struct and perform any needed actions
*/
