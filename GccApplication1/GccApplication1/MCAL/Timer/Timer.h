/*
 * Timer.h
 *
 * Created: 1/8/2023 9:33:05 PM
 *  Author: mehob
 */ 


#ifndef TIMER_H_
#define TIMER_H_
//**all Includes
#include "../../utilites/types.h"
#include "../../utilites/register.h"
#include "../../utilites/pinmacros.h"
//###########################
//************timer driver
//all macros for the timer drier
#define Timer_0 0
#define Timer_2 1
typedef enum Timermode_t{
	Normal,Ctc,pwm,fastpwm
}Timermode_t;
// timer intrupt modes
#define TOIE 0
#define OCIE 1
//timer reading flags
#define TOV 0
#define OCF 1
//####################################


//***ALL functions prototype
//Timer mode function
//input:timer number,timer mode number,timer compare out mode number
//output :enum for function error state
//function :this function sets for the required timer ,its mode &compare out mode
EN_functionstate_t Timer_mode(uint8_t timernumber,Timermode_t mode,uint8_t compareoutmode);
//timer inatial value function
//input:timer number & inatial value required to set
//output :enum for function error state
//function :this function sets for the required timer the inatial value to start counting from
EN_functionstate_t Timer_InatialVal(uint8_t timernumber,uint8_t intvalue);
//timer set compare value
//input:timer number & compare value required to set
//output :enum for function error state
//function:this function sets the compare value for the specified timer
EN_functionstate_t Timer_CompareVal(uint8_t timernumber,uint8_t compvalue);
//timer intrupt enable
//input:timer number ,intrupt mode required to set
//output :enum for function error state
//function: it enable the required intrupt mode for the specified timer
EN_functionstate_t Timer_intruptEnable(uint8_t timernumber,uint8_t Intruptmodee);
//timer intrupt disable
//input:timer number ,intrupt mode required to set
//output :enum for function error state
//function:it disable the required intrupt mode for the specified timer
EN_functionstate_t Timer_intruptDisable(uint8_t timernumber,uint8_t Intruptmodee);
//timer start & setingprescale value
//input:timer number & prescalemode
//output :enum for function error state
//function:it sets the prescaler value for therequired timer letting it to start
EN_functionstate_t Timer_StartPRESCalerValue(uint8_t timernumber,uint8_t prescalermodes);
//timer read a flag
//input:timernumber ,timer flag ,address for the variable to save the flag
//output :enum for function error state
//function:it reads the required flag from a specific timer and returns it to an address
EN_functionstate_t Timer_ReadFlag(uint8_t timernumber,uint8_t timerflag,uint8_t *read);

//timer clear flags
//input:timernumber ,timer flag 
//output: enum for function error state
//function: this function erases the required flag from its register 
EN_functionstate_t Timer_EraseFlag(uint8_t timernumber,uint8_t timerflag);
//timer test function
//input:void
//output :enum for driver error state
//function: it calls all the apis of the drivers and returns driiver_ok if all the apis functioned ok 
EN_Driverstate_t Timer_Test();
#endif /* TIMER_H_ */