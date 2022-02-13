#ifndef BUTTONS_H_INCLUDED
#define BUTTONS_H_INCLUDED
#include "DIO.h"
/**
*   BUTTONS_init : This function initialize the DIO
*/
void BUTTONS_init(void);
/**
*   BUTTONS_update : This function reads DIO
*/
void BUTTONS_update(void);
/**
*   BUTTONS_get_state : This function update the buttons state to control motor direction and speed
*/
void BUTTONS_get_state(void);

#endif // BUTTONS_H_INCLUDED
