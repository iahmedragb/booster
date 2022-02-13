#include "motor.h"

void MOTOR_init(void){
    PWM_init();
    TIMERS_init();
}
void MOTOR_set_direction_speed(void){
    /*speed b : direction backward and speed 30%
      speed 0 :     speed 0%
      speed 1 : direction forward and speed 30%
      speed 2 : direction forward and speed 60%
      speed 3 : direction forward and speed 90%
      */}
void MOTOR_get_direction_speed(void){
    ///static global value
}
void MOTOR_update(void){
    /*speed b : start timer and pwm 30%
      speed 0 :     stop timer and pwm 0%
      speed 1 : start timer and pwm 30%
      speed 2 : start timer and pwm 60%
      speed 3 : start timer and pwm 90%
      */
      TIMERS_get_state();

}
