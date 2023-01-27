/*
 * DIO.h
 *
 * Created: 1/4/2023 8:30:40 AM
 *  Author: mehob
 */ 


#ifndef DIO_H_
#define DIO_H_
//**all Includes
#include "../../utilites/types.h"
#include "../../utilites/register.h"
#include "../../utilites/pinmacros.h"
//all functions prototypes
//input: port number ,pinnumber,direction
//output: enum error state EN_functionstate_t
//function:intalize the direction of pins
EN_functionstate_t DIO_init(uint8_t portnumber ,uint8_t pinnumber,uint8_t direction);
//input: port number ,pinnumber,value
//output: enum error state EN_functionstate_t
//function:write data on dio pin
EN_functionstate_t DIO_write(uint8_t portnumber ,uint8_t pinnumber,uint8_t value);
 //input: port number ,pinnumber
 //output: enum error state EN_functionstate_t
 //function:toggle data on dio pin
EN_functionstate_t DIO_toogle(uint8_t portnumber ,uint8_t pinnumber); 
//input: port number ,pinnumber,address to value
//output: enum error state EN_functionstate_t
//function: read data on dio pin
EN_functionstate_t DIO_read (uint8_t portnumber ,uint8_t pinnumber,uint8_t *value);

//test  DIO_functions
//input: void
//output: enum error state EN_Driverstate_t
//function: it calls all the apis of the driver and return the driver state 
EN_Driverstate_t DIO_Test(void);



#endif /* DIO_H_ */