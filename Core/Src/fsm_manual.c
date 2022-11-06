/*
 * fsm_manual.c
 *
 *  Created on: Nov 2, 2022
 *      Author: tan
 */

#include"fsm_manual.h"

void fsm_manual_state2(){
	if(mode!=2){
		return;
	}
	disableCountDown();
	blinkLED(AUTO_GREEN);
	updateClock1(ledGreenTime);
	updateClock2(mode);
	if(isButton2Pressed()){
		ledGreenTime++;
		if(ledGreenTime == 100){
			ledGreenTime = 1;
		}
	}
	if(isButton3Pressed()){
		ledRedTime = ledGreenTime + ledYellowTime;
		reinitStatus();
	}
}

void fsm_manual_state3(){
	if(mode!=3){
		return;
	}
	disableCountDown();
	blinkLED(AUTO_YELLOW);
	updateClock1(ledYellowTime);
	updateClock2(mode);
	if(isButton2Pressed()){
		ledYellowTime++;
		if(ledYellowTime == 100){
			ledYellowTime = 1;
		}

	}
	if(isButton3Pressed()){
		ledRedTime = ledGreenTime + ledYellowTime;
		reinitStatus();
	}
}


