/*
 * Timer0.h
 *
 * Created: 1/8/2023 9:37:59 PM
 *  Author: mehob
 */ 


#ifndef TIMER0_H_
#define TIMER0_H_
#include "../../MCAL/DIO driver/DIO.h"
#include "../../MCAL/Timer/Timer.h"
#include "../../MCAL/Interrupt/Interrupt.h"

//#########################################################
//******this driver makes timer0 counts every 5secnds for stages switch 
//#########################################################
//timero iniate and Reset
//input:void
//output:void
//function:this function inatiate timer 0 to 
//  		mode: timer 0  , Normal mode ,  (0) normalport operation
//  Inatialvalue: timer0   ,(0x0c)int value
//    compareval: timer0   , (0) comp value
//intrupt enable: timer0   ,  TOIE 
EN_functionstate_t Timer0_intiate_reset();

//timer start
//input: void
//output: void
//function: this function start timer 0
//prescaler value : timer0 , clkI/O (5)
EN_functionstate_t Timer0_start();

//timer stop
//input: void
//output: void
//function: this function stops timer 0
//prescaler value : timer0 , no clock source (0)

EN_functionstate_t Timer0_stop();

//timer test
//input:void
//output:void
//function : this function tests the timer 0 driver
EN_Driverstate_t Timer0_Test();

//interrupt routine for timer0 for overflow
//dont forget the #######	Intrupt_GlobalEnable();########
/*ISR(Timer0OvfINT){
	j++;
	Timer0_stop();
	Timer0_intiate_reset();
	Timer0_start();
		}*/
	
//interrupt routine for timer0 for comp match
//ISR(Timer0CompINT){	}

#endif /* TIMER0_H_ */