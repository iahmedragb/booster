/*
 * BUTTON.c
 *
 * Created: 19/01/2022 10:26:18 ص
 *  Author: Ahmed
 */ 
#include "BUTTON.h"
#include "registers.h"


void BUTTON_init(void){
	PORTC_DIR=0x00;		//PC0 is input
	PORTC_DATA=0x01; //PC internal pull-up is activated
}
unsigned char BUTTON_read(unsigned char pinC){
	return PORTC_STATUS &(1<<pinC);		//read the status register of a specific pin for port C
}

void BUTTON_toggle(void){
	if(BUTTON_read(0) !=0)	//if the button is pushed turn off the led
	PORTA_DATA = 0x00;
	if(BUTTON_read(0) !=1)	//if the button is pulled turn on the led
	PORTA_DATA = 0x01;
}