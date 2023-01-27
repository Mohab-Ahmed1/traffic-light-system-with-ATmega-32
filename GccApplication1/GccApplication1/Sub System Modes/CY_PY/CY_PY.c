/*
 * CY_PY.c
 *
 * Created: 1/8/2023 9:41:27 PM
 *  Author: mehob
 */ 
#include "CY_PY.h"
volatile uint8_t Timer2Reset; 
volatile uint8_t x;
//car yellow & pedestrian yellow function
//input :address for the global variable controling the stages ,address for general ovf counter , address for Timer0 reset counter
//output:enum function represent error state
//function: 1-turn off all other leds
//			2-intalize the yellow leds for the cars and the yellow led for the pedestrians
//			3-turns ON and blink the yellow led for cars and yellow led for the pedestrians
//			4-waits for 5 sec
//			5-turns OFF the green led for cars and RED led for the pedestrians
//			6-send the state for the next stage


EN_functionstate_t CarYellow_PedstrianYellow(uint8_t *Cstage,uint8_t *OFcounter,uint8_t *ResetTimer,uint8_t *Pedestrianflag){
	*OFcounter=0;
	*ResetTimer=0;
	Timer2Reset=0;
	
	volatile uint8_t ofcounter2;
	LED_off(PORT_A,0);
	LED_off(PORT_A,2);
	LED_off(PORT_B,0);
	LED_off(PORT_B,2);
	
	LED_int(PORT_A,1);
	LED_int(PORT_B,1);
	
	LED_on( PORT_A,1);
	LED_on(PORT_B,1);
	
	if(*Cstage==1|*Cstage==3){
		Intrupt_GlobalEnable();
		Timer0_intiate_reset();
	//	Timer2_intiate_reset();
		Timer0_start();
		//Timer2_start();
		
		while (*OFcounter<19)
		{
			
			if (*ResetTimer==1)
			{
				*ResetTimer=0;
				*OFcounter=*OFcounter+1;
				Timer0_stop();
				Timer0_intiate_reset();
				Timer0_start();
				
			}
			
		
		Timer_mode(Timer_2,Normal,0);	
		Timer_InatialVal(Timer_2,0x00);
		Timer_StartPRESCalerValue(Timer_2,2);
			do
			{
				Timer2Reset=0;
				Timer_ReadFlag(Timer_2,OCF,&x);
				if(*Pedestrianflag==1){
					break;
				}
				
			} while (x!=1);
			LED_toogle(PORT_A,1);
			LED_toogle(PORT_B,1);
			Timer_StartPRESCalerValue(Timer_2,0);
			
			
		}
		LED_off(PORT_A,1);
		LED_off(PORT_B,1);
	}
	if( *Pedestrianflag==1){
		*Pedestrianflag=0;
		}else{
		if(*Cstage==1){
			*Cstage=2;
			}else{
			*Cstage=0;
		}
	}
	return Function_ok;
}
/*
ISR(Timer2OvfINT){
	Timer2Reset=1;
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
