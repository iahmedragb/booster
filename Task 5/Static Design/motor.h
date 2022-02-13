#ifndef MOTOR_H_INCLUDED
#define MOTOR_H_INCLUDED
#include "PWM.h"
#include "TIMERS.h"
/**
*   MOTOR_init : This function initialize the PWM module and TIMER module

*/
void MOTOR_init(void);
/**
*   MOTOR_update : This function reads DIO registers
*/
void MOTOR_update(void);
/**
*   MOTOR_set_direction_speed : This function set the motor direction and speed based on timer and pwm
*/
void MOTOR_set_direction_speed(void);
/**
*   MOTOR_set_direction_speed : This function reads the state of motor direction and speed based on timer and pwm
*/
void MOTOR_get_direction_speed(void);

#endif // MOTOR_H_INCLUDED
