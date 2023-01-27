/*
 * pinmacros.h
 *
 * Created: 1/4/2023 10:17:10 AM
 *  Author: mehob
 */ 


#ifndef PINMACROS_H_
#define PINMACROS_H_
//**all pin driver macros
//ports macros
#define PORT_A 'A'
#define PORT_B 'B'
#define PORT_C 'C'
#define PORT_D 'D'

//direction macros
#define IN 0
#define OUT 1

//value macros
#define LOW 0
#define HIGH 1

//test enum 
typedef enum EN_functionstate_t{
	Function_ok,
	Function_Error
	}EN_functionstate_t;

typedef enum EN_Driverstate_t{
	Driver_ok,
	Driver_Error
}EN_Driverstate_t;

#endif /* PINMACROS_H_ */