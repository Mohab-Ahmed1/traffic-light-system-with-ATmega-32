/*
 * Pededstrian_Mode.h
 *
 * Created: 1/8/2023 9:46:14 PM
 *  Author: mehob
 */ 


#ifndef PEDEDSTRIAN MODE_H_
#define PEDEDSTRIAN MODE_H_
#include "../../Sub System Modes/CR_PG/CR_PG.h"
#include "../../Sub System Modes/CG_PR/CG_PR.h"
#include "../../Sub System Modes/CY_PY/CY_PY.h"
//pedestrian mode function
//input: adress for the variable of the current stage and adress of the overflow counter
//output:enum function represent error state
//function makes the traffic lights work in the pedestrian mode
EN_functionstate_t Pedestrian_mode(uint8_t *currentStage,uint8_t *overflowscounter ,uint8_t *Timer0Reset ,uint8_t *Pedestrianflag);



#endif /* PEDEDSTRIAN MODE_H_ */