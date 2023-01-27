/*
 * Timer2.c
 *
 * Created: 1/10/2023 7:07:56 PM
 *  Author: mehob
 */ 
#include "Timer2.h"

//timer2 iniate and Reset
//input:void
//output:void
//function:this function inatiate timer 2 to
//  		mode: timer 2  , Normal mode ,  (0) normalport operation
//  Inatialvalue: timer2   ,(0x06)int value
//    compareval: timer2   , (0) comp value
//intrupt enable: timer2   ,  TOIE
EN_functionstate_t Timer2_intiate_reset(){
	
	//if (Timer_mode(Timer_2,Normal,0)!=Function_ok)
	
	 if (Timer_InatialVal(Timer_2,0x06)!=Function_ok)
	{	return Function_Error;
		
	}else if (Timer_intruptEnable(Timer_2,TOIE)!=Function_ok)
	{
		return Function_Error;
		}else {
		return Function_ok;
	}
	
	
	//	Timer_CompareVal(Timer_0,0xFF);
	
	
}

//timer start
//input: void
//output: void
//function: this function start timer 0
//prescaler value : timer2 , clkI/O (5)
EN_functionstate_t Timer2_start(){
	if (Timer_StartPRESCalerValue(Timer_2,1)!=Function_ok)
	{
		return Function_Error ;
	}
	else
	{
		return Function_ok;
	}
}

//timer stop
//input: void
//output: void
//function: this function stops timer 2
//prescaler value : timer2 , no clock source (0)

EN_functionstate_t Timer2_stop(){
	if (Timer_StartPRESCalerValue(Timer_2,0)!=Function_ok)
	{
		return Function_Error ;
	}
	else
	{
		return Function_ok;
	}
	
}

//timer test
//input:void
//output:void
//function : this function tests the timer 2 driver

EN_Driverstate_t Timer2_Test(){
	
	if (Timer2_intiate_reset()!=Function_ok)
	{
		return Driver_Error;
	}else if (Timer2_start()!=Function_ok)
	{
		return Driver_Error;
	}else if (Timer2_stop()!=Function_ok)
	{
		return Driver_Error;
		}else {
		return Driver_ok ;
	}
	
}