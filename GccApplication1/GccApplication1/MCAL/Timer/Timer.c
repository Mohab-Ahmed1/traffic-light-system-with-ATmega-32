/*
 * Timer.c
 *
 * Created: 1/8/2023 9:33:29 PM
 *  Author: mehob
 */ 
#include "Timer.h"
//Timer mode function
//input:timer number,timer mode number,timer compare out mode number
//output :enum for function error state
//function :this function sets for the required timer ,its mode &compare out mode
EN_functionstate_t Timer_mode(uint8_t timernumber,Timermode_t mode,uint8_t compareoutmode){
	switch(timernumber){
		case Timer_0:
			if(mode==Normal)
			{
				TCCR0&=~(0x48);
			}else if (mode==Ctc)
			{
				TCCR0&=~(1<<3);
				TCCR0|=(1<<6);
			}else if (mode==pwm)
			{
				TCCR0&=~(1<<6);
				TCCR0|=(1<<3);
			}else if(mode== fastpwm)
			{
				TCCR0|=(0x48);
			}else{
				return Function_Error;
			}
			///***********compareoutmode
			if (compareoutmode==0)
			{
				TCCR0&=~(0x30);
			}else if(compareoutmode==1)
			{
				TCCR0|=(1<<4);
				TCCR0&=~(1<<5);
			}else if(compareoutmode==2)
			{
				TCCR0|=(1<<5);
				TCCR0&=~(1<<4);
				
			}else if (compareoutmode==3)
			{
				TCCR0|=(0x30);
			}else{
				return Function_Error; 
			}
			return Function_ok;
		break;
	//********timer2	
		case Timer_2:
			if(mode==Normal)
			{
				TCCR2&=~(0x48);
			}else if (mode==Ctc)
			{
				TCCR2&=~(1<<3);
				TCCR2|=(1<<6);
			}else if (mode==pwm)
			{
				TCCR2&=~(1<<6);
				TCCR2|=(1<<3);
			}else if(mode== fastpwm)
			{
				TCCR2|=(0x48);
			}else{
				return Function_Error;
			}
			ASSR=0x08;//make the timer clocked from the crystal
			///***********compareoutmode
			if (compareoutmode==0)
			{
				TCCR2&=~(0x30);
			}else if(compareoutmode==1)
			{
				TCCR2|=(1<<4);
				TCCR2&=~(1<<5);
			}else if(compareoutmode==2)
			{
				TCCR2|=(1<<5);
				TCCR2&=~(1<<4);
				
			}else if (compareoutmode==3)
			{
				TCCR2|=(0x30);
			}else{
				return Function_Error; 
			}
			return Function_ok;
			break;
		default:
			return Function_Error;
			}
}
//timer inatial value function
//input:timer number & inatial value required to set
//output :enum for function error state
//function :this function sets for the required timer the inatial value to start counting from
EN_functionstate_t Timer_InatialVal(uint8_t timernumber,uint8_t intvalue){
	switch(timernumber){
	case Timer_0:
	TCNT0=intvalue;
	return Function_ok;
	break;
	case Timer_2:
	TCNT2=intvalue;
	return Function_ok;
	break;
	default:
	return Function_Error;
}
}
//timer set compare value
//input:timer number & compare value required to set
//output :enum for function error state
//function:this function sets the compare value for the specified timer
EN_functionstate_t Timer_CompareVal(uint8_t timernumber,uint8_t compvalue){
	switch(timernumber){
	case Timer_0:
	OCR0=compvalue;
	return Function_ok;
	break;
	case Timer_2:
	OCR2=compvalue;
	return Function_ok;
	break;
	default:
	return Function_Error;
}
}
//timer intrupt enable
//input:timer number ,intrupt mode required to set
//output :enum for function error state
//function: it enable the required intrupt mode for the specified timer
EN_functionstate_t Timer_intruptEnable(uint8_t timernumber,uint8_t Intruptmodee){
	switch(timernumber){
	case Timer_0:
		if (Intruptmodee==TOIE)
		{
			TIMSK|=(1<<0);
		} 
		else if(Intruptmodee== OCIE)
		{
				TIMSK|=(1<<1);
		}else{
			return Function_Error;
		}
	return Function_ok;
	break;
	case Timer_2:
			if (Intruptmodee==TOIE)
			{
				TIMSK|=(1<<6);
			}
			else if(Intruptmodee== OCIE)
			{
				TIMSK|=(1<<7);
			}else{
				return Function_Error;
			}
	return Function_ok;
	break;
	default:
	return Function_Error;
}
}
//timer intrupt disable
//input:timer number ,intrupt mode required to set
//output :enum for function error state
//function:it disable the required intrupt mode for the specified timer
EN_functionstate_t Timer_intruptDisable(uint8_t timernumber,uint8_t Intruptmodee){
	switch(timernumber){
	case Timer_0:
		if (Intruptmodee==TOIE)
		{
			TIMSK&=~(1<<0);
		}
		else if(Intruptmodee== OCIE)
		{
			TIMSK&=~(1<<1);
		}else{
			return Function_Error;
		}
	return Function_ok;
	break;
	case Timer_2:
		if (Intruptmodee==TOIE)
		{
			TIMSK&=~(1<<6);
		}
		else if(Intruptmodee== OCIE)
		{
			TIMSK&=~(1<<7);
		}else{
			return Function_Error;
		}
	return Function_ok;
	break;
	default:
	return Function_Error;
}
}
//timer start & setingprescale value
//input:timer number & prescalemode
//output :enum for function error state
//function:it sets the prescaler value for therequired timer letting it to start
EN_functionstate_t Timer_StartPRESCalerValue(uint8_t timernumber,uint8_t prescalermodes){
	switch(timernumber){
		case Timer_0:
			switch(prescalermodes){
				case 0:
				TCCR0 &=~(0x07);
				break;
				case 1:
				TCCR0 &=~(0x06);
				TCCR0|=(1<<0);
				break;
				case 2:
				TCCR0 &=~(0x05);
				TCCR0|=(1<<1);
				break;
				case 3:
				TCCR0 &=~(1<<2);
				TCCR0|=(0x03);
				break;
				case 4:
				TCCR0 &=~(0x03);
				TCCR0|=(1<<2);
				break;
				case 5:
				TCCR0 &=~(1<<1);
				TCCR0|=(0x05);
				break;
				case 6:
				TCCR0 &=~(1<<0);
				TCCR0|=(0x06);
				break;
				case 7:
				TCCR0|=(0x07);
				break;
				default:
				return Function_Error;
			}
		return Function_ok;
		break;
		//***********timer 2
		case Timer_2:
			switch(prescalermodes){
				case 0:
				TCCR2 &=~(0x07);
				break;
				case 1:
				TCCR2 &=~(0x06);
				TCCR2|=(1<<0);
				break;
				case 2:
				TCCR2 &=~(0x05);
				TCCR2|=(1<<1);
				break;
				case 3:
				TCCR2 &=~(1<<2);
				TCCR2|=(0x03);
				break;
				case 4:
				TCCR2 &=~(0x03);
				TCCR2|=(1<<2);
				break;
				case 5:
				TCCR2 &=~(1<<1);
				TCCR2|=(0x05);
				break;
				case 6:
				TCCR2 &=~(1<<0);
				TCCR2|=(0x06);
				break;
				case 7:
				TCCR2|=(0x07);
				break;
				default:
				return Function_Error;
			}
		return Function_ok;
		break;
		default:
		return Function_Error;
	}
}
//timer read a flag
//input:timernumber ,timer flag ,address for the variable to save the flag
//output :enum for function error state
//function:it reads the required flag from a specific timer and returns it to an address
EN_functionstate_t Timer_ReadFlag(uint8_t timernumber,uint8_t timerflag,uint8_t *read){
	switch(timernumber){
		case Timer_0:
			if (timerflag==TOV)
			{
				*read=(TIFR &(1<<0))>>0;
				TIFR|=(1<<0);
			}
			else if (timerflag==OCF)
			{
				*read=(TIFR &(1<<1))>>1;
				TIFR|=(1<<1);
			}
			else
			{
				return Function_Error;
			}
		return Function_ok;
		break;
		//********timer2
		case Timer_2:
			if (timerflag==TOV)
			{
				*read=(TIFR &(1<<6))>>6;
				TIFR|=(1<<6);
			}
			else if (timerflag==OCF)
			{
				*read=(TIFR &(1<<7))>>7;
				TIFR|=(1<<7);
			}
			else
			{
				return Function_Error;
			}
		return Function_ok;
		break;
		default:
		return Function_Error;
	}
}

//timer clear flags
//input:timernumber ,timer flag
//output: enum for function error state
//function: this function erases the required flag from its register
EN_functionstate_t Timer_EraseFlag(uint8_t timernumber,uint8_t timerflag){
	switch(timernumber){
		case Timer_0:
			if (timerflag==TOV)
			{			
				TIFR|=(1<<0);
			}
			else if (timerflag==OCF)
			{			
				TIFR|=(1<<1);
			}
			else
			{
				return Function_Error;
			}
		return Function_ok;
		break;
		//********timer2
		case Timer_2:
			if (timerflag==TOV)
			{			
				TIFR|=(1<<6);
			}
			else if (timerflag==OCF)
			{
				TIFR|=(1<<7);
			}
			else
			{
				return Function_Error;
			}
		return Function_ok;
		break;
		default:
		return Function_Error;
	}
}
//timer test function
//input:void
//output :enum for driver error state
//function: it calls all the apis of the drivers and returns driiver_ok if all the apis functioned ok
EN_Driverstate_t Timer_Test(){
	#define timerNO Timer_0
	#define mod Normal
	#define compmod 0
	#define intval 0x30
	#define cmpval 0xF3
	#define Intermod TOIE
	#define presmode 1
	volatile uint8_t state;
	#define timeflg OCF
	
	if (Timer_mode(timerNO, mod, compmod)!=Function_ok)
	{
		return Driver_Error;
	} 
	else if(Timer_InatialVal(timerNO,intval )!=Function_ok)
	{
		return Driver_Error;

	}else if (Timer_CompareVal(timerNO, cmpval)!=Function_ok)
	{
		return Driver_Error;

	}else if (Timer_intruptEnable(timerNO,Intermod )!=Function_ok)
	{
		return Driver_Error;

	}else if (Timer_intruptDisable(timerNO, Intermod)!=Function_ok)
	{	
		return Driver_Error;

	}else if (Timer_StartPRESCalerValue(timerNO, presmode)!=Function_ok)
	{
		return Driver_Error;

	}else if (Timer_ReadFlag(timerNO, timeflg, &state)!=Function_ok)
	{
		return Driver_Error;

	}else if (Timer_EraseFlag( timerNO, timeflg)!=Function_ok)
	{
	}else{
		return Driver_ok;
	}
}
