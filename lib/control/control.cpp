#include "Control.h"


void control_hold(IMU_data* data) {
    if(data->Error < 0) {												//Calculate derivative_error from gyroscope reading
        //TODO check types, float or int
		float derivative_error = -data->omega_Reading;
	} else {
		float derivative_error = data->omega_Reading;
	}

	//Hold mode, use hold gains
	float pwm_Duty = ((Kp_hold) * (data->Error)) + ((Kd_hold) * (derivative_error)) + ((Ki_hold) * (data->integral_Error));

	if(abs(pwm_Duty) < pwm_Limit_hold)
        pwm_Duty = 0; //limit pwm to avoid jitter (probably 5%-20%)

	if(pwm_Duty >= 0) { 					//If > 0, write to cw valve
        //TODO what is the point of this if statement
		if(pwm_Duty>1)
            pwm_Duty = 1; 			//cap pwm at 100%
		float cw_pwm_Duty = pwm_Duty;
		float ccw_pwm_Duty = 0;
    } else { 						//If < 0, write to ccw valve
        //TODO what is the point of this if statement
		if(pwm_Duty<-1)
            pwm_Duty = -1; 			//cap pwm at -100%
		float cw_pwm_Duty = 0;
		float ccw_pwm_Duty = -pwm_Duty;
	}
}


void control_actuate(IMU_data* data) {

    if(data->Error < 0) {												//Calculate derivative error from gyroscope reading
		float derivative_error = -data->omega_Reading;
	} else {
		float derivative_error = data->omega_Reading;
	}

	//Actuate mode, use actuate gains
    //TODO should this be an int
	float pwm_Duty = ((Kp_actuate) * (data->Error)) + ((Kd_actuate) * (derivative_error)) + ((Ki_actuate) * (data->integral_Error));

	if(abs(pwm_Duty) < pwm_Limit_actuate)
        pwm_Duty = 0;	//limit pwm to avoid jitter (probably 0)

	if(pwm_Duty >= 0) { 					//If > 0, write to cw valve
        //TODO what is the point of this if statement
		if(pwm_Duty>1)
            pwm_Duty = 1; 			//cap pwm at 100%
		float cw_pwm_Duty = pwm_Duty;
		float ccw_pwm_Duty = 0;
	} else { 						//If < 0, write to ccw valve
        //TODO what is the point of this if statement
		if(pwm_Duty<-1)
            pwm_Duty = -1; 			//cap pwm at -100%
		float cw_pwm_Duty = 0;
		float ccw_pwm_Duty = -pwm_Duty;
	}
}
