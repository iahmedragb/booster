/*
 * LED.c
 *
 * Created: 19/01/2022 10:26:02 ص
 *  Author: Ahmed
 */ 
#include "registers.h"
#include "LED.h"


void LED_init(void){
	PORTA_DIR=0x01;		//PA0 is output
	PORTA_DATA =0x01;	//PA0 data register is initialized with 1
}

