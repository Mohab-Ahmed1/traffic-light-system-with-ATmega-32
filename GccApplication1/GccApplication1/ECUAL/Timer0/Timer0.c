/*
 * Timer0.c
 *
 * Created: 1/8/2023 9:38:19 PM
 *  Author: mehob
 */ 

#include "Timer0.h"

//timero iniate and Reset
//input:void
//output:void
//function:this function inatiate timer 0 to
//  		mode: timer 0  , Normal mode ,  (0) normalport operation
//  Inatialvalue: timer0   ,(0x0c)int value
//    compareval: timer0   , (0) comp value
//intrupt enable: timer0   ,  TOIE
EN_functionstate_t Timer0_intiate_reset(){
	
	if (Timer_mode(Timer_0,Normal,0)!=Function_ok)
	{
		return Function_Error;
	} 
	else if (Timer_InatialVal(Timer_0,0x0c)!=Function_ok)
	{	return Function_Error;
		
	}else if (Timer_intruptEnable(Timer_0,TOIE)!=Function_ok)
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
//prescaler value : timer0 , clkI/O (5)
EN_functionstate_t Timer0_start(){
	if (Timer_StartPRESCalerValue(Timer_0,5)!=Function_ok)
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
//function: this function stops timer 0
//prescaler value : timer0 , no clock source (0)

EN_functionstate_t Timer0_stop(){
	if (Timer_StartPRESCalerValue(Timer_0,0)!=Function_ok)
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
//function : this function tests the timer 0 driver
EN_Driverstate_t Timer0_Test(){
	
	if (Timer0_intiate_reset()!=Function_ok)
	{
		return Driver_Error;
	}else if (Timer0_start()!=Function_ok)
	{
		return Driver_Error;
	}else if (Timer0_stop()!=Function_ok)
	{
		return Driver_Error;
	}else {
		return Driver_ok ;
	}
	
}