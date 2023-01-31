/*
* Autonomous Car.c
*
* Created: 1/29/2023 4:38:16 AM
* Author : MohamedKhedr
*/


#include "Motion.h"

void motion_init(void)
{

	DDRC  |= ( 1<<PINC3) ;
	DDRC  |= ( 1<<PINC4) ;
	DDRC  |= ( 1<<PINC5) ;
	DDRC  |= ( 1<<PINC6) ;
	
}

void forward()
{
	PORTC  |=   (1<<PINC3) ;
	PORTC  &= ~ (1<<PINC4) ;
	PORTC  |=   (1<<PINC5) ;
	PORTC  &= ~ (1<<PINC6) ;
}

void Xturn(void)
{
	PORTC  |=   (1<<PINC3) ;
	PORTC  &= ~ (1<<PINC4) ;
	PORTC  &= ~ (1<<PINC5) ;
	PORTC  |=   (1<<PINC6) ;
}

void right(void)
{
	PORTC  |=   (1<<PINC3) ;
	PORTC  &= ~ (1<<PINC4) ;
	PORTC  &= ~ (1<<PINC5) ;
	PORTC  |=   (1<<PINC6) ;
}

void left(void)
{
	PORTC  &= ~ (1<<PINC3) ;
	PORTC  |=   (1<<PINC4) ;
	PORTC  |=   (1<<PINC5) ;
	PORTC  &= ~ (1<<PINC6) ;
}

void stop(void)
{
	PORTC  &= ~ (1<<PINC3) ;
	PORTC  &= ~ (1<<PINC4) ;
	PORTC  &= ~ (1<<PINC5) ;
	PORTC  &= ~ (1<<PINC6) ;
}