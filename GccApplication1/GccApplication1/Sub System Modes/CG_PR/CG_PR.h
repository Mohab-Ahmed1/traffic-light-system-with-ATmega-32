/*
 * CG_PR.h
 *
 * Created: 1/8/2023 9:40:42 PM
 *  Author: mehob
 */ 


#ifndef CG_PR_H_
#define CG_PR_H_
#include "../../ECUAL/Button/button.h"
#include "../../ECUAL/LED/LED.h"
#include "../../ECUAL/Timer0/Timer0.h"
#include "../../ECUAL/Timer2/Timer2.h"
//car green & pedestrian red function
//input :address for the global variable controling the stages ,address for general ovf counter , address for Timer0 reset counter
//output:enum function represent error state
//function: 1-turn off all other leds
//			2-intalize the green leds for the cars and the Red led for the pedestrians
//			3-turns ON the green led for cars and RED led for the pedestrians
//			4-waits for 5 sec
//			5-turns OFF the green led for cars and RED led for the pedestrians
//			6-send the state for the next stage
EN_functionstate_t CarGreen_PedstrianRED(uint8_t *Cstage,uint8_t *OFcounter,uint8_t *ResetTimer,uint8_t *Pedestrianflag);



#endif /* CG_PR_H_ */