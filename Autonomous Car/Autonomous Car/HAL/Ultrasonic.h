/*
* Autonomous Car.c
*
* Created: 1/29/2023 4:38:16 AM
* Author : MohamedKhedr
*/



#ifndef ULTRASONIC_H_
#define ULTRASONIC_H_


#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#define  Trigger_pin	PA0	

void ultrasonic_init(void);
void ultrasonic_triger(void);

long int distance;


#endif /* ULTRASONIC_H_ */