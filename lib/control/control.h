#ifndef _CONTROL_H_
#define _CONTROL_H_

#include <Arduino.h>
#include "IMU.h"


//global, used in both the main loop and the control function
extern float cw_pwm_Duty;
extern float ccw_pwm_Duty;
extern float derivative_error;


//declarations for control used in main loop
#define Allowed_error 0.2
#define Control_period 1000000*2


/*
//declarations for the control algorithm
#define Actuate_hold_limit 5 //in degrees
#define PWM_period 0.2
#define Pgain_actuate 0
#define Pgain_hold 0
#define Dgain_actuate 0
#define Igain_actuate 0
*/

#define Kp_actuate 0
#define Kp_hold 0
#define Kd_actuate 0
#define Kd_hold 0
#define Ki_actuate 0
#define Ki_hold 0
#define pwm_Limit_actuate 0
#define pwm_Limit_hold 0



//controls the rocket by performing algorithmic calculations and sending a signal to the solenoids
void control_hold(IMU_data* data);
void control_actuate(IMU_data* data);


#endif
