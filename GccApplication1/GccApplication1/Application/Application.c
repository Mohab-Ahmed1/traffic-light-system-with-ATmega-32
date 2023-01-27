/*
 * Application.c
 *
 * Created: 1/4/2023 10:21:47 AM
 *  Author: mehob
 */ 
#include "Application.h"
volatile uint8_t Timer0Reset=0;
//the application function
//input:void
//output:void
//function:it inatialize the whole project
//        1-it will intalize thebutton intrupt:
//		  2-it will enter the system in the normal mode function
//        3-it will set the intrupt routine for timer 0 and for the external INT0

volatile uint8_t currentStage=0;
volatile uint8_t overflowscounter=0;
volatile uint8_t Pedestrianflag=0;
volatile uint8_t buttonstate;
st_clickstate presstime;
st_clickstate releasetime;
volatile uint8_t clicktime;
void Application(){
	BUTTON_init(PORT_D ,2);
	buttonstate=0;
	Intrupt_GlobalEnable();
	Intrupt_ExternalSense(EInt0,RisingEdge);
	Intrupt_EnableExternal(EInt0);	
	LED_int(PORT_D,4);	
	
	Normal_mode(&currentStage,&overflowscounter,&Timer0Reset,&Pedestrianflag);
	
}

ISR(Timer0OvfINT){
	Timer0Reset=1;
}
ISR(EXTRINT0){
	if(buttonstate==0){
		Intrupt_DisableExternal(EInt0);
		buttonstate=1;
		presstime.stage=currentStage;
		presstime.overflowtime=overflowscounter;		
		Intrupt_ExternalSense(EInt0,FallingEdge);
		Intrupt_EnableExternal(EInt0);
	}
	else if(buttonstate==1)
	{
		Intrupt_DisableExternal(EInt0);
		buttonstate=0;
		releasetime.stage=currentStage;
		releasetime.overflowtime=overflowscounter;
		
		if(presstime.stage>releasetime.stage){
		releasetime.stage=releasetime.stage+4;
		}
		
		if (presstime.stage==releasetime.stage)
		{
			clicktime=releasetime.overflowtime-presstime.overflowtime;
		}else if(presstime.stage<releasetime.stage){
			clicktime= ((releasetime.stage-presstime.stage)*19+releasetime.overflowtime)-presstime.overflowtime;
		}
	if (clicktime<3){
		LED_toogle(PORT_D,4);
		Pedestrian_mode(&currentStage,&overflowscounter,&Timer0Reset,&Pedestrianflag);
		LED_toogle(PORT_D,4);
	}
		
		Intrupt_ExternalSense(EInt0,RisingEdge);
		Intrupt_EnableExternal(EInt0);
		
	}
		
}
