/*
 * Normal_Mode.c
 *
 * Created: 1/8/2023 9:45:08 PM
 *  Author: mehob
 */ 
#include "Normal Mode.h"

EN_functionstate_t Normal_mode(uint8_t *currentStage,uint8_t *overflowscounter ,uint8_t *Timer0Reset,uint8_t *Pedestrianflag){

	while(1){
			switch (*currentStage)
			{
				case 0:
				CarGreen_PedstrianRED(currentStage,overflowscounter,Timer0Reset,Pedestrianflag);
				break;
				case 1:
				CarYellow_PedstrianYellow(currentStage,overflowscounter,Timer0Reset,Pedestrianflag);
				break;
				case 2:
				CarRed_PedstrianGreen(currentStage,overflowscounter,Timer0Reset,Pedestrianflag);
				break;
				case 3:
				CarYellow_PedstrianYellow(currentStage,overflowscounter,Timer0Reset,Pedestrianflag);
				break;
				default:
				return Function_Error;
			}
		}
		
}
	

