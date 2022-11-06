/*
 * led.c
 *
 *  Created on: Oct 3ON, 2ON22
 *      Author: tan
 */

#include"led.h"

void turn_LED1_on(int n){ //2 cho red, 3 cho green, 4 cho yellow
	n = n-2;
	int led_array[3][3] = {
		{ON,OFF,OFF}, //RED
		{OFF,ON,OFF}, //GREEN
		{OFF,OFF,ON}, //YELLOW
	};
	HAL_GPIO_WritePin(RED1_GPIO_Port, RED1_Pin, led_array[n][0]);
	HAL_GPIO_WritePin(GREEN1_GPIO_Port, GREEN1_Pin, led_array[n][1]);
	HAL_GPIO_WritePin(YELLOW1_GPIO_Port, YELLOW1_Pin, led_array[n][2]);
}

void turn_LED2_on(int n){ //2 cho red, 3 cho green, 4 cho yellow
	n = n-2;
	int led_array[3][3] = {
		{ON,OFF,OFF}, //RED
		{OFF,ON,OFF}, //GREEN
		{OFF,OFF,ON}, //YELLOW
	};
	HAL_GPIO_WritePin(RED2_GPIO_Port, RED2_Pin, led_array[n][0]);
	HAL_GPIO_WritePin(GREEN2_GPIO_Port, GREEN2_Pin, led_array[n][1]);
	HAL_GPIO_WritePin(YELLOW2_GPIO_Port, YELLOW2_Pin, led_array[n][2]);
}

void turnREDoff(){
	HAL_GPIO_WritePin(RED1_GPIO_Port, RED1_Pin, OFF);
	HAL_GPIO_WritePin(RED2_GPIO_Port, RED2_Pin, OFF);
}

void turnYELLOWoff(){
	HAL_GPIO_WritePin(YELLOW1_GPIO_Port, YELLOW1_Pin, OFF);
	HAL_GPIO_WritePin(YELLOW2_GPIO_Port, YELLOW2_Pin, OFF);
}

void turnGREENoff(){
	HAL_GPIO_WritePin(GREEN1_GPIO_Port, GREEN1_Pin, OFF);
	HAL_GPIO_WritePin(GREEN2_GPIO_Port, GREEN2_Pin, OFF);
}

void toggleGREEN(){
	HAL_GPIO_TogglePin(GREEN1_GPIO_Port, GREEN1_Pin);
	HAL_GPIO_TogglePin(GREEN2_GPIO_Port, GREEN2_Pin);
}

void toggleYELLOW(){
	HAL_GPIO_TogglePin(YELLOW1_GPIO_Port, YELLOW1_Pin);
	HAL_GPIO_TogglePin(YELLOW2_GPIO_Port, YELLOW2_Pin);
}

void blinkLED(int n){
	n = n-2;
	if(timer5_flag==ON){
		return;
	}
	switch(n){
	case 1:
		turnREDoff();
		turnYELLOWoff();
		toggleGREEN();
		break;
	case 2:
		turnREDoff();
		turnGREENoff();
		toggleYELLOW();
		break;
	}
	setTimer5(250);
}

void init_LED_array(){
	HAL_GPIO_WritePin(RED1_GPIO_Port, RED1_Pin, OFF);
	HAL_GPIO_WritePin(GREEN1_GPIO_Port, GREEN1_Pin, OFF);
	HAL_GPIO_WritePin(YELLOW1_GPIO_Port, YELLOW1_Pin, OFF);
	HAL_GPIO_WritePin(RED2_GPIO_Port, RED2_Pin, OFF);
	HAL_GPIO_WritePin(GREEN2_GPIO_Port, GREEN2_Pin, OFF);
	HAL_GPIO_WritePin(YELLOW2_GPIO_Port, YELLOW2_Pin, OFF);
}
