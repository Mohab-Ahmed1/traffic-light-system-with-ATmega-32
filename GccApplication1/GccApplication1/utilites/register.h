/*
 * register.h
 *
 * Created: 1/4/2023 7:41:30 AM
 *  Author: mehob
 */ 


#ifndef REGISTER_H_
#define REGISTER_H_
#include "types.h"


//macros for port A
#define PORTA *((volatile uint8_t*)0x3B) //8 bit register to write data
#define DDRA *((volatile uint8_t*)0x3A) //8 bit register to set the pin direction
#define PINA *((volatile uint8_t*)0x39) //8 bit register to read the pin status

//macros for port b
#define PORTB *((volatile uint8_t*)0x38) //8 bit register to write data
#define DDRB *((volatile uint8_t*)0x37) //8 bit register to set the pin direction
#define PINB *((volatile uint8_t*)0x36) //8 bit register to read the pin status

//macros for port c
#define PORTC *((volatile uint8_t*)0x35) //8 bit register to write data
#define DDRC *((volatile uint8_t*)0x34) //8 bit register to set the pin direction
#define PINC *((volatile uint8_t*)0x33) //8 bit register to read the pin status

//macros for port d
#define PORTD *((volatile uint8_t*)0x32) //8 bit register to write data
#define DDRD *((volatile uint8_t*)0x31) //8 bit register to set the pin direction
#define PIND *((volatile uint8_t*)0x30) //8 bit register to read the pin status

//***timer registers
//timer 0
#define TCCR0 *((volatile uint8_t*)0x53) //8 bit register define timer status (mode +prescaler_that starts the timer when defined _)
#define TCNT0 *((volatile uint8_t*)0x52) //8 bit register to define the intial value of the timer
#define TIFR *((volatile uint8_t*)0x58) //8 bit register to read the flags of the timer OCIE0 ,TOIE0
#define TIMSK *((volatile uint8_t*)0x59) //8 bit register to enable the intrupt TOIE0 (over flow ) & OCF0 (compare intrupt )
#define  OCR0 *((volatile uint8_t*)0x5C) //8bit register that contain the value we compare with current value to allow the compare flag

//timer 2
#define TCCR2 *((volatile uint8_t*)0x45) //8 bit register define timer status (mode +prescaler_that starts the timer when defined _)
#define TCNT2 *((volatile uint8_t*)0x44) //8 bit register to define the intial value of the timer
#define TIFR *((volatile uint8_t*)0x58) //8 bit register to read the flags of the timer intrups OCIE2 ,TOIE2
#define TIMSK *((volatile uint8_t*)0x59) //8 bit register to enable the intrupt TOIE2 (over flow ) & OCF2 (compare intrupt )
#define  OCR2 *((volatile uint8_t*)0x43) //8bit register that contain the value we compare with current value to allow the compare flag
#define  ASSR *((volatile uint8_t*)0x42) //8bit register that contain the value we compare with current value to allow the compare flag

//*******External intrupt registers
#define MCUCR *((volatile uint8_t*)0x55) //8 bit register define the intrupt sense of INT0 ,INT1
#define MCUCSR *((volatile uint8_t*)0x54) //8 bit register define the intrupt sense of INT2
#define GIFR *((volatile uint8_t*)0x5A) //8 bit register define the intrupt enable for INT0 ,INT1 ,INT2
#define GICR *((volatile uint8_t*)0x5B) //8 bit register define  the intrupt general flag of INT0 ,INT1 ,INT2



#endif /* REGISTER_H_ */