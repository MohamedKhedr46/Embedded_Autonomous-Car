/*
* Autonomous Car.c
*
* Created: 1/29/2023 4:38:16 AM
* Author : MohamedKhedr
*/


#include "Lcd.h"

void LCD_Command (char cmd)							
{
	LCD_Data_Port = cmd;							
	LCD_Command_Port &= ~((1<<RS)|(1<<RW));			
	LCD_Command_Port |= (1<<EN);					
	_delay_us(1);
	LCD_Command_Port &= ~(1<<EN);
	_delay_ms(3);									
}

void LCD_Char (char char_data)						
{
	LCD_Data_Port = char_data;						
	LCD_Command_Port &= ~(1<<RW);					
	LCD_Command_Port |= (1<<EN)|(1<<RS);			
	_delay_us(1);
	LCD_Command_Port &= ~(1<<EN);
	_delay_ms(1);									
}

void LCD_Init (void)								
{
	LCD_Command_Dir |= (1<<RS)|(1<<RW)|(1<<EN);		
	LCD_Data_Dir = 0xFF;							
	
	_delay_ms(20);									
	LCD_Command (0x38);								
	LCD_Command (0x0C);								
	LCD_Command (0x06);								
	LCD_Command (0x01);								
	LCD_Command (0x80);								
}

void LCD_String (char *str)							
{
	int i;
	for(i=0;str[i]!=0;i++)							
	{
		LCD_Char (str[i]);							
	}
}

void LCD_String_xy (char row, char pos, char *str)	
{
	if (row == 1)
	LCD_Command((pos & 0x0F)|0x80);				
	else if (row == 2)
	LCD_Command((pos & 0x0F)|0xC0);				
	LCD_String(str);								
}

void LCD_Clear (void)								
{
	LCD_Command (0x01);								
	LCD_Command (0x80);								
}


void LCD_Forward(void)
{
	LCD_Clear();
	LCD_String_xy(1,0,"MOVING");
	LCD_String_xy(2,5,"FORWARD");
}

void LCD_Right(void)
{
	LCD_Clear();
	LCD_String_xy(1,0,"MOVING");
	LCD_String_xy(2,5,"RIGHT");
}

void LCD_Left(void)
{
	LCD_Clear();
	LCD_String_xy(1,0,"MOVING");
	LCD_String_xy(2,5,"LEFT");
}

void LCD_Xturn(void)
{
	LCD_Clear();
	LCD_String_xy(1,0,"MOVING");
	LCD_String_xy(2,5,"XTURN");
}

void LCD_STOPPED(void)
{
	LCD_Clear();
	LCD_String_xy(1,4,"STOPPED");
}