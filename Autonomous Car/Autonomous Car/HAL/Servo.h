/*
* Autonomous Car.c
*
* Created: 1/29/2023 4:38:16 AM
* Author : MohamedKhedr
*/

#ifndef SERVO__H_
#define SERVO__H_

#include <avr/io.h>
#include <util/delay.h>


void servo_init(void);
void Servo_Front(void);
void Servo_Right(void);
void Servo_Left(void);

#endif 
