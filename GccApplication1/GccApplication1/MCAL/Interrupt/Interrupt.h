/*
 * Interrupt.h
 *
 * Created: 1/8/2023 9:34:55 PM
 *  Author: mehob
 */ 


#ifndef INTERRUPT_H_
#define INTERRUPT_H_
#include "../../utilites/types.h"
#include "../../utilites/register.h"
#include "../../utilites/pinmacros.h"

//##################################################################
//*************interrupt driver macro
//macros defined for interrupts
//enable global interrupt
# define sei()  __asm__ __volatile__ ("sei" ::: "memory")
//disable global interrupt
# define cli()  __asm__ __volatile__ ("cli" ::: "memory")
//********
//External intrupt names
#define EInt0 0
#define EInt1 1
#define EInt2 2
//External interrupt modes
typedef enum InterMode_t{
	lowlevel,Anylogic,FallingEdge,RisingEdge
	}InterMode_t;
//***INTRUPT REQUESTS
//External Interrupt requests 0
#define EXTRINT0	__vector_1
//External Interrupt requests 1
#define EXTRINT1   __vector_2
//External Interrupt requests 2
#define EXTRINT2  __vector_3
//timer2 comp match Intrupt Request 
#define Timer2CompINT __vector_4
//timer 2 over flow intrupt request 
#define Timer2OvfINT __vector_5
//timer 0 comp match intrupt request
#define Timer0CompINT __vector_10 
//timer 0 over flow intrupt request 
#define  Timer0OvfINT __vector_11
/*Macro defines the isr()*/
#  define __INTR_ATTRS used
#  define ISR(vector, ...)            \
void vector (void) __attribute__ ((signal,__INTR_ATTRS)) __VA_ARGS__; \
void vector (void)
//###############################################################################

//all functions prototypes
//interrupt global enable
//input: void
//output :enum for function error state
//function:it enable the global interrupts for the atemage32
EN_functionstate_t Intrupt_GlobalEnable(); //sei()
//interrupt global disable
//input:void
//output :enum for function error state
//function:it disable the global interrupts for the ATmega32
EN_functionstate_t Intrupt_globalDisabled(); //cli()
//intrupt external sense
//input:External intrupt name ,Intrupt required mode
//output :enum for function error state
//function :it define the sense of the external intrupts
EN_functionstate_t Intrupt_ExternalSense(uint8_t EXTintruptnum,InterMode_t Intruptmode);
//intrupt enable external 
//input: required intrupt to enable
//output :enum for function error state
//function:it enable the required external intrupt
EN_functionstate_t Intrupt_EnableExternal(uint8_t EXTintruptnum);
//intrupt disable external
//input: required intrupt to disable
//output :enum for function error state
//function:it disable the required external intrupt
EN_functionstate_t Intrupt_DisableExternal(uint8_t EXTintruptnum);
//intrupt external flag read
//input :name of the intrupt required to read and adrress of a variable to save the flag in 
//output :enum for function error state
//function:read the intrupt flag and save it in the provided address of a variable
EN_functionstate_t Intrupt_ExtFlagRead(uint8_t EXTintruptnum,uint8_t *value);

//intrupt function test
//input:void
//output:enum for driver error state
//function :calls all the apis of the intrupt driver and returns the state of the driver
EN_Driverstate_t Intrupt_test();



#endif /* INTERRUPT_H_ */