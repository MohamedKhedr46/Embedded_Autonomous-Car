/*
* Autonomous Car.c
*
* Created: 1/29/2023 4:38:16 AM
* Author : MohamedKhedr
*/



#ifndef MOTION_H_
#define MOTION_H_

#include <avr/io.h>


void motion_init(void);
void forward(void);
void Xturn(void);
void right(void);
void left(void);
void stop(void);




#endif /* MOTION_H_ */