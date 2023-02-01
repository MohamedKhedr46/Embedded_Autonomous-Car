/*
* Autonomous Car.c
*
* Created: 1/29/2023 4:38:16 AM
* Author : MohamedKhedr
*/

#include "..\\HAL\\Servo.h"
#include "..\\HAL\\Ultrasonic.h"
#include "..\\HAL\\Motion.h"
#include "..\\HAL\\Lcd.h"


int main(void)
{
	
	motion_init();
	servo_init();
	LCD_Init();
	ultrasonic_init();
	

	_delay_ms(1000);
	
	while(1)
	{
		
		
		ultrasonic_triger();
		_delay_ms(15);
		
		if (distance>15)
		{			
			forward();
			LCD_Forward();
			
		}

		if(distance < 15)
		{
			stop();
			LCD_STOPPED();
			
			Servo_Left();
			_delay_ms(4500);
			
			ultrasonic_triger();
			_delay_ms(15);
			
			if(distance > 15)
			{
				Servo_Right();
				_delay_ms(4500);
				
				Servo_Front();
				
				left();
				LCD_Left();
				_delay_ms(3500);
				
			}
			
			else if(distance < 15)
			{
				Servo_Right();
				_delay_ms(4500);
				
				ultrasonic_triger();
				_delay_ms(15);
				
				if (distance < 15)
				{
					Servo_Front();
					Xturn();
					LCD_Xturn();
					_delay_ms(7000);
					
				}
				
				else if (distance > 15)
				{
					Servo_Front();
					right();
					LCD_Right();
					_delay_ms(3500);
					
				}
			}


		}
		

	}


}

