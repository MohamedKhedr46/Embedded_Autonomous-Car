/*
* Autonomous Car.c
*
* Created: 1/29/2023 4:38:16 AM
* Author : MohamedKhedr
*/


#include "Ultrasonic.h"


long count;
int TimerOverflow = 0;

void ultrasonic_init(void)
{

	
	DDRA = 0x01;		
	PORTD = 0xFF;		
	sei();
	TIMSK = (1 << TOIE1);	
	TCCR1A = 0;		

}

void ultrasonic_triger(void){



	PORTA |= (1 << Trigger_pin);
	_delay_us(10);
	PORTA &= (~(1 << Trigger_pin));
	
	TCNT1 = 0;
	TCCR1B = 0x41;
	TIFR = 1<<ICF1;	
	TIFR = 1<<TOV1;	

	
	
	while ((TIFR & (1 << ICF1)) == 0);
	TCNT1 = 0;	
	TCCR1B = 0x01;	
	TIFR = 1<<ICF1;	
	TIFR = 1<<TOV1;	
	TimerOverflow = 0;

	while ((TIFR & (1 << ICF1)) == 0);
	count = ICR1 + (65535 * TimerOverflow);	
	
	distance = (double)count / 466.47;
	_delay_ms(200);
	
}

ISR(TIMER1_OVF_vect)
{
	TimerOverflow++;	
}