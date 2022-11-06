/*
 * buttons.c
 *
 *  Created on: Oct 30, 2022
 *      Author: tan
 */

#include "buttons.h"

int KeyReg0 = NORMAL_STATE;
int KeyReg1 = NORMAL_STATE;
int KeyReg2 = NORMAL_STATE;
int KeyReg3 = NORMAL_STATE;

int TimeOutForKeyPress =  500;
int button1_flag = 0;
int button2_flag = 0;
int button3_flag = 0;
int button_pressed = 0;

int isButton1Pressed(){
	if(button1_flag == 1){
		button1_flag = 0;
		return 1;
	}
	return 0;
}

int isButton2Pressed(){
	if(button2_flag == 1){
		button2_flag = 0;
		return 1;
	}
	return 0;
}

int isButton3Pressed(){
	if(button3_flag == 1){
		button3_flag = 0;
		return 1;
	}
	return 0;
}

void subKeyProcess(int n){
	switch(n){
		case 1:
			button1_flag = 1;
			break;
		case 2:
			button2_flag = 1;
			break;
		case 3:
			button3_flag = 1;
			break;
		default:
			break;
	}
}

void getKeyInput1(){
  KeyReg2 = KeyReg1;
  KeyReg1 = KeyReg0;
  if(HAL_GPIO_ReadPin(BUTTON1_GPIO_Port, BUTTON1_Pin)==PRESSED_STATE){
	  KeyReg0 = PRESSED_STATE;
	  button_pressed = 1;
  }
  else if(HAL_GPIO_ReadPin(BUTTON2_GPIO_Port, BUTTON2_Pin)==PRESSED_STATE){
	  KeyReg0 = PRESSED_STATE;
	  button_pressed = 2;
  }
  else if(HAL_GPIO_ReadPin(BUTTON3_GPIO_Port, BUTTON3_Pin)==PRESSED_STATE){
	  KeyReg0 = PRESSED_STATE;
	  button_pressed = 3;
  }
  else{
	  KeyReg0 = NORMAL_STATE;
  }
  if ((KeyReg1 == KeyReg0) && (KeyReg1 == KeyReg2)){
    if (KeyReg2 != KeyReg3){
      KeyReg3 = KeyReg2;
      if (KeyReg3 == PRESSED_STATE){
        TimeOutForKeyPress = 100;
        subKeyProcess(button_pressed);
      }
    }
    else{
       TimeOutForKeyPress --;
        if (TimeOutForKeyPress == 0){
          KeyReg3 = NORMAL_STATE;
        }
    }
  }
}

