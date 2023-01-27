/*
 * Pededstrian_Mode.c
 *
 * Created: 1/8/2023 9:46:51 PM
 *  Author: mehob
 */ 
#include "Pededstrian Mode.h"
//pedestrian mode function
//input: adress for the variable of the current stage and adress of the overflow counter
//output:enum function represent error state
//function makes the traffic lights work in the pedestrian mode
EN_functionstate_t Pedestrian_mode(uint8_t *currentStage,uint8_t *overflowscounter ,uint8_t *Timer0Reset,uint8_t *Pedestrianflag){
	
	if (*currentStage==0|*currentStage==1|*currentStage==3)
	{  *currentStage=1;
		CarYellow_PedstrianYellow(currentStage,overflowscounter,Timer0Reset,Pedestrianflag);		
		CarRed_PedstrianGreen(currentStage,overflowscounter,Timer0Reset,Pedestrianflag);
		*Pedestrianflag=1;	
		return Function_ok;
	}
	else if (*currentStage==2)
	{
		*currentStage=2;
		CarRed_PedstrianGreen(currentStage,overflowscounter,Timer0Reset,Pedestrianflag);
		CarRed_PedstrianGreen(currentStage,overflowscounter,Timer0Reset,Pedestrianflag);
		CarYellow_PedstrianYellow(currentStage,overflowscounter,Timer0Reset,Pedestrianflag);
         *Pedestrianflag=1;
		return Function_ok;
	} 
	else
	{
		return Function_Error;
	}

}