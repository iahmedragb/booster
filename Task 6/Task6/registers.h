/*
 * registers.h
 *
 * Created: 19/01/2022 10:23:01 ص
 *  Author: Ahmed
 */ 


#ifndef REGISTERS_H_
#define REGISTERS_H_

#define PORTA_DIR *((volatile unsigned char*)(0x3A))
#define PORTA_DATA *((volatile unsigned char*)(0x3B))

#define PORTC_STATUS *((volatile unsigned char*)(0x33))
#define PORTC_DIR *((volatile unsigned char*)(0x34))
#define PORTC_DATA *((volatile unsigned char*)(0x35))


#endif /* REGISTERS_H_ */