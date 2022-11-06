/*
 * fsm_auto.c
 *
 *  Created on: Oct 30, 2022
 *      Author: tan
 */
#include "fsm_auto.h"

int convertToMilSecs(int n){
	return 1000*n;
}

void fsm_auto_state1(){
	if(mode!=1){
		return;
	}
  	switch(status1){
  	case INIT:
  		status1 = AUTO_RED;
  		setTimer1(convertToMilSecs(ledRedTime));
  		setCountDown1(ledRedTime);
  		turn_LED1_on(AUTO_RED);
  		break;
  	case AUTO_RED:
  		if(isTimerFlagRaised(1)){
  			status1 = AUTO_GREEN;
  			turn_LED1_on(AUTO_GREEN);
  	  		setCountDown1(ledGreenTime);
  			setTimer1(convertToMilSecs(ledGreenTime));
  		}
	break;
  	case AUTO_GREEN:
  		if(isTimerFlagRaised(1)){
  			status1 = AUTO_YELLOW;
  			turn_LED1_on(AUTO_YELLOW);
  			setTimer1(convertToMilSecs(ledYellowTime));
  	  		setCountDown1(ledYellowTime);
  		}
	break;
  	case AUTO_YELLOW:
  		if(isTimerFlagRaised(1)){
  			status1 = AUTO_RED;
  			turn_LED1_on(AUTO_RED);
  			setTimer1(convertToMilSecs(ledRedTime));
  	  		setCountDown1(ledRedTime);
  		}
  		break;
  	}
  	switch(status2){
  	case INIT:
  		status2 = AUTO_GREEN;
  		setTimer2(convertToMilSecs(ledGreenTime));
  		setCountDown2(ledGreenTime);
  		turn_LED2_on(AUTO_GREEN);
  		break;
  	case AUTO_GREEN:
  		if(isTimerFlagRaised(2)){
  			status2 = AUTO_YELLOW;
  			turn_LED2_on(AUTO_YELLOW);
  	  		setCountDown2(ledYellowTime);
  			setTimer2(convertToMilSecs(ledYellowTime));
  		}
	break;
  	case AUTO_YELLOW:
  		if(isTimerFlagRaised(2)){
  			status2 = AUTO_RED;
  			turn_LED2_on(AUTO_RED);
  			setTimer2(convertToMilSecs(ledRedTime));
  	  		setCountDown2(ledRedTime);
  		}
	break;
  	case AUTO_RED:
  		if(isTimerFlagRaised(2)){
  			status2 = AUTO_GREEN;
  			turn_LED2_on(AUTO_GREEN);
  			setTimer2(convertToMilSecs(ledGreenTime));
  	  		setCountDown2(ledGreenTime);
  		}
  		break;
  	}
}
