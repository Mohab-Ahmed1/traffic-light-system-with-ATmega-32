/*
 * CR_PG.c
 *
 * Created: 1/8/2023 9:42:47 PM
 *  Author: mehob
 */ 
#include "CR_PG.h"
//volatile uint8_t ResetTimer;
//car Red &pedestrian Green function
//input :address for the global variable controling the stages ,address for general ovf counter , address for Timer0 reset counter
//output:enum function represent error state
//function: 1-turn off all other leds
//			2-intalize the Red leds for the cars and the green led for the pedestrians
//			3-turns ON the red led for cars and green led for the pedestrians
//			4-waits for 5 sec
//			5-turns OFF the red led for the cars and green lede for pedstrians
//			6-send the state for the next stage
EN_functionstate_t CarRed_PedstrianGreen(uint8_t *Cstate,uint8_t *OFcounter,uint8_t *ResetTimer,uint8_t *Pedestrianflag){
	*OFcounter=0;
	*ResetTimer=0;
	LED_off(PORT_A,1);
	LED_off(PORT_B,1);
	LED_off(PORT_A,0);
	LED_off(PORT_B,2);
	
	LED_int(PORT_A,2);
	LED_int(PORT_B,0);

	//LED_on( PORT_A,2);
	//LED_on(PORT_B,0);
	
	if(*Cstate==2){
	Intrupt_GlobalEnable();
	Timer0_intiate_reset();
		
	Timer0_start();
		while (*OFcounter<19)
		{
			LED_on( PORT_A,2);
			LED_on(PORT_B,0);
			if (*ResetTimer==1)
			{
				*ResetTimer=0;
				*OFcounter=*OFcounter+1;
				Timer0_stop();
				Timer0_intiate_reset();
				Timer0_start();
			}
		}	
		LED_off(PORT_A,2);
		LED_off(PORT_B,0);	
		}
	if( *Pedestrianflag==1){
		*Pedestrianflag=0;
		}else{
		*Cstate=3;	
			}
	return Function_ok;
}



/*
int main(void){
	Intrupt_GlobalEnable();
	LED_int(PORT_A,0);
	while(1){
		j=0;
		Timer0_intiate_reset();
		//Timer_intruptDisable(Timer_0,TOIE);
		LED_toogle(PORT_A,0);
		Timer0_start();
		
		
	}
}
ISR(Timer0OvfINT){
	j++;
	Timer0_stop();
	Timer0_intiate_reset();
	Timer0_start();
}
*/