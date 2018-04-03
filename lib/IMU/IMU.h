#ifndef _IMU_H_
#define _IMU_H_


//struct containing all IMU data points, may need to be modified when using multiple Teenies
struct IMU_data {
    int IMU_direction; //this is the magnetic bearing in degrees
    int IMU_altitude;
    int IMU_pressure;
    int IMU_roll;
    int IMU_pitch;
    int IMU_yaw;

    //IMU calculations that will be used by the control function
    int Error;
    int last_Error;
    int integral_Error;
    int omega_Reading;
};


//get the current position and rate of roll from the IMU
void IMU_control_data();

//get all six data points from the IMU to send to the TFR
void IMU_all_data();


#endif
