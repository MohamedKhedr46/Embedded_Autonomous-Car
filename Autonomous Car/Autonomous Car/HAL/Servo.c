/*
* Autonomous Car.c
*
* Created: 1/29/2023 4:38:16 AM
* Author : MohamedKhedr
*/

#include "Servo.h"



void servo_init (void)
{
	
	DDRD  |= ( 1<<PIND7) ;

}


void Servo_Front(void)
{
	PORTD  |=  ( 1<<PIND7) ;
	_delay_us(7400);
	PORTD  &= ~( 1<<PIND7) ;
}

void Servo_Right(void)
{
	
	PORTD  |=  ( 1<<PIND7) ;
	_delay_us(1600);
	PORTD  &= ~( 1<<PIND7) ;

}

void Servo_Left(void)
{
	PORTD  |=  ( 1<<PIND7) ;
	_delay_us(9700);
	PORTD  &= ~( 1<<PIND7) ;
}