/*
 * Timer2.h
 *
 * Created: 1/10/2023 7:07:39 PM
 *  Author: mehob
 */ 


#ifndef TIMER2_H_
#define TIMER2_H_
#include "../../MCAL/DIO driver/DIO.h"
#include "../../MCAL/Timer/Timer.h"
#include "../../MCAL/Interrupt/Interrupt.h"

//#########################################################
//******this driver makes timer2 counts every 100msec for yellow blinks 
//#########################################################
//timer2 iniate and Reset
//input:void
//output:void
//function:this function inatiate timer 2 to 
//  		mode: timer 2  , Normal mode ,  (0) normalport operation
//  Inatialvalue: timer2   ,(0x06)int value
//    compareval: timer2   , (0) comp value
//intrupt enable: timer2   ,  TOIE 
EN_functionstate_t Timer2_intiate_reset();

//timer start
//input: void
//output: void
//function: this function start timer 0
//prescaler value : timer2 , clkI/O (5)
EN_functionstate_t Timer2_start();

//timer stop
//input: void
//output: void
//function: this function stops timer 2
//prescaler value : timer2 , no clock source (0)
 
EN_functionstate_t Timer2_stop();

//timer test
//input:void
//output:void
//function : this function tests the timer 2 driver
EN_Driverstate_t Timer2_Test();

//interrupt routine for timer0 for overflow
//dont forget the #######	Intrupt_GlobalEnable();########
/*ISR(Timer2OvfINT){
	j++;
	Timer2_stop();
	Timer2_intiate_reset();
	Timer2_start();
		}*/
	
//interrupt routine for timer0 for comp match
//ISR(Timer2CompINT){	}





#endif /* TIMER2_H_ */