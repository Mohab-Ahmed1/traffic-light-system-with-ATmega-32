/*
 * GccApplication1.c
 *
 * Created: 1/2/2023 5:37:15 PM
 * Author : mehob
 */ 

//#include <avr/io.h>
//#include <avr/interrupt.h>
//#include <stdio.h>

//#include <util/delay.h>//for functions of the delay
/*
#include "utilites/register.h"
#include "MCAL/DIO driver/DIO.h"
#include "MCAL/Timer/Timer.h"
#include "MCAL/Interrupt/Interrupt.h"

#include "ECUAL/LED/LED.h"
#include "ECUAL/Button/button.h"
#include "ECUAL/Timer0/Timer0.h"
#include "ECUAL/Timer2/Timer2.h"
*/
/*
#include "Sub System Modes/CR_PG/CR_PG.h"
#include "Sub System Modes/CG_PR/CG_PR.h"
#include "Sub System Modes/CY_PY/CY_PY.h"
*/



#include "Application/Application.h"
int main (void){
	Application();
}








/*
int main(void){
	volatile uint8_t x;
	LED_int(PORT_A,0);
	while(1){
			//Timer_mode(Timer_2,Normal,0); dont use with timer 2 in normal mode
			Timer_InatialVal(Timer_2,0x00);
			Timer_StartPRESCalerValue(Timer_2,5);
			x=0;
			
			do
			{
				Timer_ReadFlag(Timer_2,OCF,&x);
				
			} while (x!=1);
			LED_toogle(PORT_A,0);
			Timer_StartPRESCalerValue(Timer_2,0);
	}
}
*/


/*
#include "System Modes/Normal Mode/Normal Mode.h"
#include "System Modes/Pededstrian Mode/Pededstrian Mode.h"
volatile uint8_t Timer0Reset=0;
int main (void){
	
	volatile uint8_t currentStage=2;
	volatile uint8_t overflowscounter=0;
	Normal_mode(&currentStage,&overflowscounter,&Timer0Reset);
	Pedestrian_mode(&currentStage,&overflowscounter,&Timer0Reset);
}

ISR(Timer0OvfINT){
	Timer0Reset=1;
}*/




/*
volatile uint8_t Timer0Reset=0;
int main(void){
	volatile uint8_t currentStage=0;
	volatile uint8_t overflowscounter=0;
	while(1){
	switch (currentStage)
	{
	case 0:
		CarRed_PedstrianGreen(&currentStage,&overflowscounter,&Timer0Reset);
		break;
	case 1:
		CarYellow_PedstrianYellow(&currentStage,&overflowscounter,&Timer0Reset);
	break;
	case 2:
		CarGreen_PedstrianRED(&currentStage,&overflowscounter,&Timer0Reset);
	break;
	case 3:
		CarYellow_PedstrianYellow(&currentStage,&overflowscounter,&Timer0Reset);
	break;
	}
	}	
}

ISR(Timer0OvfINT){
	Timer0Reset=1;
}
*/



/*
int main(void){
	volatile EN_Driverstate_t DriverState;
	while(1){
		DriverState=Timer2_Test();
		
	}
}
*/





/*
volatile uint8_t j;
int main(void){
	Intrupt_GlobalEnable();
	LED_int(PORT_A,0);
	while(1){
		j=0;
		
		Timer2_intiate_reset();
		//Timer_intruptDisable(Timer_0,TOIE);
		LED_toogle(PORT_A,0);
		Timer2_start();
		
		while(1){
			if (j>2)
			{
				LED_toogle(PORT_A,0);
				j=0;
			}
		}
	}
}
ISR(Timer2OvfINT){
	j++;
	Timer2_stop();
	Timer2_intiate_reset();
	Timer2_start();
}

*/

/*
int main(void){
	volatile EN_Driverstate_t DriverState;
	while(1){
		DriverState=Timer0_Test();
		
	}
}
*/

/*
volatile uint8_t j;
int main(void){
	Intrupt_GlobalEnable();
	LED_int(PORT_A,0);	
	while(1){
		j=0;	
		Timer0_intiate_reset();
		//Timer_intruptDisable(Timer_0,TOIE);
		LED_toogle(PORT_A,0);
		Timer0_start();	
			
		while(1){
			if (j>19)
			{
				LED_toogle(PORT_A,0);
				j=0;
			}		
		}		
	}
}
ISR(Timer0OvfINT){
	j++;
	Timer0_stop();
	Timer0_intiate_reset();
	Timer0_start();
}
*/

/*
int main(void){
	volatile EN_Driverstate_t DriverState;
	while(1){
	DriverState=Intrupt_test();
		
	}
}*/


/*
int main(void){
	volatile EN_Driverstate_t x;
	LED_int(PORT_A,0);
	BUTTON_init(PORT_D,2);
	//while(1){
		Intrupt_GlobalEnable();
		Intrupt_ExternalSense(EInt0,RisingEdge);
		Intrupt_EnableExternal(EInt0);
	//}
	while(1){}
}

ISR(EXTRINT0){
	LED_toogle(PORT_A,0);
}
*/
/*
int main(void){
	volatile EN_Driverstate_t x;
	while(1){
		x=Timer_Test();
		
	}
}*/












//***************************will help in timer 2
/*
int main(void){
	volatile uint8_t x;
	LED_int(PORT_A,0);
	while(1){
		//Timer_mode(Timer_2,Normal,0); dont use with timer 2 in normal mode
		Timer_InatialVal(Timer_2,0x00);
		
	//	Timer_CompareVal(Timer_0,0xFF);
		//Timer_intruptEnable(Timer_0,TOIE);
		//Timer_intruptDisable(Timer_0,TOIE);
		Timer_StartPRESCalerValue(Timer_2,5);
		x=0;
		
		do 
		{
			Timer_ReadFlag(Timer_2,OCF,&x);
			
		} while (x!=1);
		LED_toogle(PORT_A,0);
		Timer_StartPRESCalerValue(Timer_2,0);
	}
}
*/
/********************will help in timer0 
*
int main(void){
volatile uint8_t x;
LED_int(PORT_A,0);
while(1){
Timer_mode(Timer_0,Normal,0);
Timer_InatialVal(Timer_0,0xE0);
//	Timer_CompareVal(Timer_0,0xFF);
//Timer_intruptEnable(Timer_0,TOIE);
//Timer_intruptDisable(Timer_0,TOIE);
Timer_StartPRESCalerValue(Timer_0,2);
x=0;

do
{
Timer_ReadFlag(Timer_0,OCF,&x);

} while (x!=1);
LED_toogle(PORT_A,0);
Timer_StartPRESCalerValue(Timer_0,0);
}
}
*/
//***************************************
/*
int main(void){
volatile EN_Driverstate_t x;
while(1){	
	x=DIO_Test();
	
}
	}
*/
/*int main(void)
{
    
	//1. set direction of pins
	DIO_init( PORT_A ,4,OUT);
	DIO_init( PORT_B ,0,OUT);
    
while (1) 
    {
		LED_int(PORT_A,4);
		LED_on(PORT_A,4);
		//2.toggle pin 3 port b
	DIO_write(PORT_A,4,HIGH);
		DIO_write(PORT_B,0,LOW);
		
		//delay with 300ms	
		//_delay_ms(300);
    }

uint8_t Buttonstate;
	BUTTON_init(PORT_C,1);
	LED_int(PORT_A,4);
while(1){

	BUTTON_read(PORT_C,1,&Buttonstate);
	if (Buttonstate==HIGH)
	{
		LED_on(PORT_A,4);
	} 
	else
	{
		LED_off(PORT_A,4);
	}
}

int overflows=0;
LED_int(PORT_A,4);
TCCR0=0x00;//normal mode
//timer intial value
TCNT0=0x00;
//timer start _set the prescaler
TCCR0|=(1<<0);
while(1){
	//led toggle
	LED_toogle(PORT_A,4); //call and return -->time
	
	//timer start _set the prescaler
	TCCR0|=(1<<0);
	
while (overflows<2000){		
	while ((TIFR &(1<<0))==0); //wait for the flag to rise
	TIFR |=(1<<0);//reste the flag
	overflows++;
	}
	
overflows=0;
TCCR0=0x00;//stop the timer
}


}*/

