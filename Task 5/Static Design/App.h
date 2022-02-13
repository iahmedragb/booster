#ifndef APP_H_INCLUDED
#define APP_H_INCLUDED
#include "buttons.h"
#include "motor.h"

/**
*   APP_init : This function initialize the buttons module and the motor module
*/
void APP_init(void);
/**
*   APP_update : This function update the motor state based on the  buttons state
*/
void APP_update(void);


#endif // APP_H_INCLUDED
