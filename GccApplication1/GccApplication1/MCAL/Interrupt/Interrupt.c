/*
 * Interrupt.c
 *
 * Created: 1/8/2023 9:35:09 PM
 *  Author: mehob
 */ 
#include "Interrupt.h"
//intrupt global enable
//input: void
//output :enum for function error state
//function:it enable the global intrrubts for the atemage32
EN_functionstate_t Intrupt_GlobalEnable(){
	sei();
	return Function_ok;

}
//intrupt global disable
//input:void
//output :enum for function error state
//function:it disable the global intrupts for the ATmega32
EN_functionstate_t Intrupt_globalDisabled(){
	cli();
	return Function_ok;
	}
//intrupt external sense
//input:External intrupt name ,Intrupt required mode
//output :enum for function error state
//function :it define the sense of the external intrupts
EN_functionstate_t Intrupt_ExternalSense(uint8_t EXTintruptnum,InterMode_t Intruptmode){
	switch (EXTintruptnum)
	{
		case EInt0:
			switch (Intruptmode)
			{
			case lowlevel:
				MCUCR &=~(0x03);		
				break;
			case Anylogic :
				MCUCR &=~(1<<1);
				MCUCR |=(1<<0);
				break;
			case FallingEdge:
				MCUCR &=~(1<<0);
				MCUCR |=(1<<1);
				break;
			case RisingEdge:
				MCUCR |=(0x03);;
				break;
			default:
				return Function_Error;	
			}
			return Function_ok;
			break;
		case EInt1:
			switch (Intruptmode)
			{
				case lowlevel:
				MCUCR &=~(0x0c);
				break;
				case Anylogic :
				MCUCR &=~(1<<3);
				MCUCR |=(1<<2);
				break;
				case FallingEdge:
				MCUCR &=~(1<<2);
				MCUCR |=(1<<3);
				break;
				case RisingEdge:
				MCUCR |=(0x0c);;
				break;
				default:
				return Function_Error;
			}
			return Function_ok;
			break;
		case EInt2:
			switch (Intruptmode)
			{
				case FallingEdge:
				MCUCSR &=~(1<<6);
				break;
				case RisingEdge:
				MCUCSR |=(1<<6);;
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
//intrupt enable external
//input: required intrupt to enable
//output :enum for function error state
//function:it enable the required external intrupt
EN_functionstate_t Intrupt_EnableExternal(uint8_t EXTintruptnum){
	switch (EXTintruptnum)
	{
	case EInt0:
		GICR |=(1<<6);
		break;
	case EInt1:
		GICR |=(1<<7);
		break;
	case EInt2:
		GICR |=(1<<5);
		break;
	default:
		return Function_Error;
	}
	return Function_ok;
}
//intrupt disable external
//input: required intrupt to disable
//output :enum for function error state
//function:it disable the required external intrupt
EN_functionstate_t Intrupt_DisableExternal(uint8_t EXTintruptnum){
	switch (EXTintruptnum)
	{
		case EInt0:
		GICR &=~(1<<6);
		break;
		case EInt1:
		GICR &=~(1<<7);
		break;
		case EInt2:
		GICR &=~(1<<5);
		break;
		default:
		return Function_Error;
	}
	return Function_ok;
}
//intrupt external flag read
//input :name of the intrupt required to read and adrress of a variable to save the flag in
//output :enum for function error state
//function:read the intrupt flag and save it in the provided address of a variable
EN_functionstate_t Intrupt_ExtFlagRead(uint8_t EXTintruptnum,uint8_t *value){
	switch (EXTintruptnum)
	{
	case EInt0 :
		*value=(GIFR &(1<<6))>>6;
		GIFR|=(1<<6);
		break;
	case EInt1:
		*value=(GIFR &(1<<7))>>7;
		GIFR|=(1<<7);
		break;
	case EInt2:
		*value=(GIFR &(1<<5))>>5;
		GIFR|=(1<<5);
		break;
	default:
		return Function_Error;
	}
	return Function_ok;
}

//intrupt function test
//input:void
//output:enum for driver error state
//function :calls all the apis of the intrupt driver and returns the state of the driver
EN_Driverstate_t Intrupt_test(){
	#define EXTINTNO EInt0
	#define INTRUPTMDE RisingEdge
	volatile uint8_t fg;
	if ( Intrupt_GlobalEnable()!= Function_ok)
	{
		return Driver_Error;
	} 
	else if ( Intrupt_GlobalEnable()!= Function_ok)
	{
		return Driver_Error;

	}else if (Intrupt_ExternalSense(EXTINTNO,INTRUPTMDE)!= Function_ok)
	{
		return Driver_Error;

	}else if ( Intrupt_EnableExternal(EXTINTNO)!= Function_ok)
	{
		return Driver_Error;
	}else if (Intrupt_ExtFlagRead(EXTINTNO,&fg)!= Function_ok)
	{
		return Driver_Error;

	}else if ( Intrupt_DisableExternal(EXTINTNO)!= Function_ok)
	{
		return Driver_Error;

	}else if ( Intrupt_globalDisabled()!= Function_ok)
	{
		return Driver_Error;
	} 
	else
	{
		return Driver_ok;
	}
		
}
	
	 
	
	 
	 
	
