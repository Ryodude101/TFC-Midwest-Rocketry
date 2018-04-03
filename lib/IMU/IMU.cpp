#include "IMU.h"



//set last = current and then get new current for integral and derivative parts
//inst_avg_error



//This is based on Wesley's code

void IMU_control_data() {};


void IMU_all_data() {};



/*
void imu_read() {
	this_time = micros()/1000000;
	error = setpoint – this_angle_reading;					//Calculate current error
	inst_avg_error = (error + last_error)/2;
	integral_error += inst_avg_error*(this_time - last_time);			//Calculate integral error
	last_error = error;
	last_time = this_time;
}
*/
