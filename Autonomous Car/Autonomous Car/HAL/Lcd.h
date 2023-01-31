/*
* Autonomous Car.c
*
* Created: 1/29/2023 4:38:16 AM
* Author : MohamedKhedr
*/



#ifndef LCD_H_
#define LCD_H_


#include <avr/io.h>
#include <util/delay.h>

#define LCD_Data_Dir DDRB				
#define LCD_Command_Dir DDRC			
#define LCD_Data_Port PORTB
#define LCD_Command_Port PORTC
#define RS PC0							
#define RW PC1
#define EN PC2

void LCD_Command (char);
void LCD_Char (char);
void LCD_Init (void);
void LCD_String (char*);
void LCD_String_xy (char,char,char*);	 
void LCD_Clear (void);


void LCD_Forward(void);
void LCD_Right(void);
void LCD_Left(void);
void LCD_Xturn(void);
void LCD_STOPPED(void);


#endif /* LCD_H_ */