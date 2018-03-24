#include "Control.h"

void control_hold() {}
void control_actuate() {}
  /*
  //Control Systems Section

      sampleTime = current Time

      // Setting goal
      If step < 4 Delay = 1                //sets delay
  Else if step < 8 Delay = 0.75
  Else if step < 12 Delay = 0.5
  Else Delay = 0.25
      if at commands.direction[current_command] AND
                                  (current time - atStart >= delay)        //moves to next step
          Increment current_command
  Setpoint = commands.direction[current_command]      //gives setpoint
  Error = setpoint - current_reading              //uses IMU data to calculate error
  If (error < actuate_hold_limit) AND command.is_done[current_command] = false   //if low error, starts delay
      commands.is_done[current_command] = true
  atStart = current time


  //Actual controls portion
  If commands.is_done[current_command] = false
      e_Derivative = (error - last_error)/(sampleTime - lastTime)
      PWM_duty = Pgain_actuate*error + Dgain_actuate*e_derivative
  Else
      e_Integral += 0.5*(error + last_error)*(sampleTime - last Time)
      PWM_duty = Pgain_hold*error + Igain_hold*e_integral

  if PWM_duty > 0.05                    //this condition may need to change
      Write LOW to CW valve
      If current time - startTime<PWM period*PWM duty
          Write HIGH to CCW valve
      Else
          Write LOW to CCW valve
  If PWM_duty < -0.05                    //this condition may need to change
      Write LOW to CCW valve
      If current time - startTime<PWM period*PWM duty
          Write HIGH to CW valve
      Else
          Write LOW to CW valve

  If current time - startTime >= 0.2 //resets at end of PWM period
      startTime = currentTime

      Last time = sample time
      Last error = error
  */
