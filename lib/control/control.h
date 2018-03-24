#ifndef _CONTROL_H_
#define _CONTROL_H_


//declarations for control used in main loop
#define Allowed_error 0.2
#define Hold_time 1000
#define Control_period 200


//declarations for the control algorithm
#define Actuate_hold_limit 5 //in degrees
#define PWM_period 0.2
#define Pgain_actuate 0
#define Pgain_hold 0
#define Dgain_actuate 0
#define Igain_actuate 0



//controls the rocket by performing algorithmic calculations and sending a signal to the solenoids
void control_hold();
void control_actuate();


#endif
