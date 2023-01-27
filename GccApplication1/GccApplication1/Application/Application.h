/*
 * Application.h
 *
 * Created: 1/4/2023 10:21:29 AM
 *  Author: mehob
 */ 


#ifndef APPLICATION_H_
#define APPLICATION_H_
#include "../System Modes/Normal Mode/Normal Mode.h"
#include "../System Modes/Pededstrian Mode/Pededstrian Mode.h"

 typedef struct currentstate{
	volatile uint8_t stage;
	volatile uint8_t overflowtime;
	}st_clickstate;
//the application function 
//input:void
//output:void
//function:it inatialize the whole project
void Application();



#endif /* APPLICATION_H_ */