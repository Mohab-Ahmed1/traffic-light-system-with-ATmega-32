/*
 * CG_PR.c
 *
 * Created: 1/8/2023 9:40:52 PM
 *  Author: mehob
 */ 
#include "CG_PR.h"
volatile uint8_t ResetTimer;
//car green & pedestrian red function
//input :address for the global variable controling the stages ,address for general ovf counter , address for Timer0 reset counter
//output:enum function represent error state
//function: 1-turn off all other leds
//			2-intalize the green leds for the cars and the Red led for the pedestrians
//			3-turns ON the green led for cars and RED led for the pedestrians
//			4-waits for 5 sec
//			5-turns OFF the green led for cars and RED led for the pedestrians
//			6-send the state for the next stage
EN_functionstate_t CarGreen_PedstrianRED(uint8_t *Cstage,uint8_t *OFcounter,uint8_t *ResetTimer,uint8_t *Pedestrianflag){
		*OFcounter=0;
		*ResetTimer=0;
		LED_off(PORT_A,1);
		LED_off(PORT_A,2);
		LED_off(PORT_B,0);
		LED_off(PORT_B,1);
		
		LED_int(PORT_A,0);
		LED_int(PORT_B,2);
		
		//LED_on( PORT_A,0);
	//	LED_on(PORT_B,2);
		
		if(*Cstage==0){
		Intrupt_GlobalEnable();
		Timer0_intiate_reset();
		
		Timer0_start();
		while (*OFcounter<19)
		{
			LED_on( PORT_A,0);
			LED_on(PORT_B,2);
			if (*ResetTimer==1)
			{
				*ResetTimer=0;
				*OFcounter=*OFcounter+1;
				Timer0_stop();
				Timer0_intiate_reset();
				Timer0_start();
			}
		}
		LED_off(PORT_A,0);
		LED_off(PORT_B,2);
		}
	if( *Pedestrianflag==1){
		*Pedestrianflag=0;
	}else{
		*Cstage=1;
		}
		return Function_ok;
	}

