/*
 * Task6.c
 *
 * Created: 19/01/2022 10:22:09 ص
 * Author : Ahmed Ragab
 */ 

#include "registers.h"


int main(void)
{	//initialize PA0 as output for led with initial value high
	LED_init();
	//initialize PC0 (for button)
	BUTTON_init();
    while (1) 
    {
		BUTTON_toggle();		//Check status register of PC0 
    }
}

