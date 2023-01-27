/*
 * CR_PG.h
 *
 * Created: 1/8/2023 9:42:25 PM
 *  Author: mehob
 */ 


#ifndef CR_PG_H_
#define CR_PG_H_
#include "../../ECUAL/Button/button.h"
#include "../../ECUAL/LED/LED.h"
#include "../../ECUAL/Timer0/Timer0.h"
#include "../../ECUAL/Timer2/Timer2.h"

//car Red &pedestrian Green function
//input :address for the global variable controling the stages ,address for general of counter , address for Timer0 reset counter
//output:enum function represent error state
//function: 1-turn off all other leds
//			2-intalize the Red leds for the cars and the green led for the pedestrians
//			3-turns ON the red led for cars and green led for the pedestrians
//			4-waits for 5 sec
//			5-turns OFF the red led for the cars and green lede for pedstrians
//			6-send the state for the next stage
EN_functionstate_t CarRed_PedstrianGreen(uint8_t *Cstage,uint8_t *OFcounter,uint8_t *ResetTimer,uint8_t *Pedestrianflag);



#endif /* CR_PG_H_ */