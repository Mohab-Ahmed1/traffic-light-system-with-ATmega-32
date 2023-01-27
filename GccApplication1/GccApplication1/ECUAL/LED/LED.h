/*
 * LED.h
 *
 * Created: 1/4/2023 10:04:11 AM
 *  Author: mehob
 */ 


#ifndef LED_H_
#define LED_H_
//include drivers
#include "../../MCAL/DIO driver/DIO.h"
#include "../../MCAL/Timer/Timer.h"
#include "../../MCAL/Interrupt/Interrupt.h"

//led intialize
//input:led port and led pins
//output: void
//function:this function intalize the pin to be output 
void LED_int (uint8_t ledport ,uint8_t ledpin);
//led on
//input led port and led pin 
//output:void
//function :this function writes high on that pin
void LED_on (uint8_t ledport ,uint8_t ledpin);
//led off 
//input:led port and led pins
//output: void
//function :this function writes low on that pin
void LED_off (uint8_t ledport ,uint8_t ledpin);
//led toogle
//input:led port and led pins
//output: void
//function :this function toggles that pin
void LED_toogle (uint8_t ledport ,uint8_t ledpin);



#endif /* LED_H_ */