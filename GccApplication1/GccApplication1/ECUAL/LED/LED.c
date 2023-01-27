/*
 * LED.c
 *
 * Created: 1/4/2023 10:04:29 AM
 *  Author: mehob
 */ 
#include "LED.h"

//led intialize
//input:led port and led pins
//output: void
//function:this function intalize the pin to be output
void LED_int (uint8_t ledport ,uint8_t ledpin){
	DIO_init(ledport,ledpin,HIGH);
}
//led on
//input led port and led pin
//output:void
//function :this function writes high on that pin
void LED_on (uint8_t ledport ,uint8_t ledpin){
	DIO_write(ledport,ledpin,HIGH);
}
//led off
//input:led port and led pins
//output: void
//function :this function writes low on that pin
void LED_off (uint8_t ledport ,uint8_t ledpin){
	DIO_write(ledport,ledpin,LOW);
}
//led toogle
//input:led port and led pins
//output: void
//function :this function toggles that pin
void LED_toogle (uint8_t ledport ,uint8_t ledpin){
	DIO_toogle(ledport,ledpin);
}