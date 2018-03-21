#ifndef _STATUS_H_
#define _STATUS_H_


//used to keep track of all systems states, might not be needed
struct status_set {
  bool liftoff;
  bool burnout;
  bool apogee;
  bool emergency;
  bool IMU_connected;
  bool TFR_connected;
  bool TFC_1_connected;
  bool TFC_2_connected;
};


//perform status check and update flags, will disbale control and trigger landing loop code when apogee has been reached, will activate emergency dump valve if given signal by ground, etc.
void check_status();

#endif
