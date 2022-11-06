/*
 * 7seg.c
 *
 *  Created on: Oct 30, 2022
 *      Author: tan
 */

#include"7seg.h"

int ledBuffer[4] = {0,0,0,0};
int segCounter = 0;
int countDownTime1 = 0;
int countDownTime2 = 0;

void update7SEG ( int index ) {
	switch ( index ) {
	case 0:
		//Display the first 7 SEG with led_buffer [0]
		selectSEG(0);
		display7SEG(ledBuffer[index]);
		break ;
	case 1:
		//Display the second 7 SEG with led_buffer [1]
		selectSEG(1);
		display7SEG(ledBuffer[index]);
		break ;
	case 2:
		//Display the third 7 SEG with led_buffer [2]
		selectSEG(2);
		display7SEG(ledBuffer[index]);
		break ;
	case 3:
		//Display the forth 7 SEG with led_buffer [3]
		selectSEG(3);
		display7SEG(ledBuffer[index]);
		break ;
	default :
		break ;
	}

 }

void selectSEG(int n){
	int selectSEGArray[4][4] = {
		{ON,OFF,OFF,OFF},
		{OFF,ON,OFF,OFF},
		{OFF,OFF,ON,OFF},
		{OFF,OFF,OFF,ON}
	};
	HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, selectSEGArray[n][0]);
	HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, selectSEGArray[n][1]);
	HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, selectSEGArray[n][2]);
	HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, selectSEGArray[n][3]);
}

void display7SEG(int n){
	int a[10][7] = {
			{ON,ON,ON,ON,ON,ON,OFF}, //0
			{OFF,ON,ON,OFF,OFF,OFF,OFF}, //1
			{ON,ON,OFF,ON,ON,OFF,ON}, //2
			{ON,ON,ON,ON,OFF,OFF,ON}, //3
			{OFF,ON,ON,OFF,OFF,ON,ON}, //4
			{ON,OFF,ON,ON,OFF,ON,ON}, //5
			{ON,OFF,ON,ON,ON,ON,ON}, //6
			{ON,ON,ON,OFF,OFF,OFF,OFF}, //7
			{ON,ON,ON,ON,ON,ON,ON}, //8
			{ON,ON,ON,ON,OFF,ON,ON}, //9
	};
	HAL_GPIO_WritePin(SEG0_GPIO_Port, SEG0_Pin, a[n][0]);
	HAL_GPIO_WritePin(SEG1_GPIO_Port, SEG1_Pin, a[n][1]);
	HAL_GPIO_WritePin(SEG2_GPIO_Port, SEG2_Pin, a[n][2]);
	HAL_GPIO_WritePin(SEG3_GPIO_Port, SEG3_Pin, a[n][3]);
	HAL_GPIO_WritePin(SEG4_GPIO_Port, SEG4_Pin, a[n][4]);
	HAL_GPIO_WritePin(SEG5_GPIO_Port, SEG5_Pin, a[n][5]);
	HAL_GPIO_WritePin(SEG6_GPIO_Port, SEG6_Pin, a[n][6]);
}

void updateClock1(int num){
	ledBuffer[0] = num/10;
	ledBuffer[1] = num%10;

}

void updateClock2(int num){
	ledBuffer[2] = num/10;
	ledBuffer[3] = num%10;
}

void segLEDScan(){
	if(isTimerFlagRaised(3)==1){
		if(segCounter >= 4){
			segCounter = 0;
		}
		update7SEG(segCounter++);
		setTimer3(250);
	}
}

void setCountDown1(int n){
	countDownTime1 = n;
}

void setCountDown2(int n){
	countDownTime2 = n;
}

void countDown1(){
	if(countDownTime1 == 0 && countDownTime2 == 0){
		return;
	}
	else if(isTimerFlagRaised(4)==1){
		if(countDownTime1 > 0){
			updateClock1(countDownTime1--);
		}
		if(countDownTime2 > 0){
			updateClock2(countDownTime2--);
		}
		setTimer4(1000);
	}
}

void disableCountDown(){
	countDownTime1 = 0;
	countDownTime2 = 0;
}
