/*
 * led.h
 *
 *  Created on: Oct 30, 2022
 *      Author: tan
 */

#ifndef INC_LED_H_
#define INC_LED_H_

#include"main.h"
#include"global.h"
#include"software_timer.h"

void turn_LED1_on(int n);
void turn_LED2_on(int n);
void blinkLED(int n);
void init_LED_array();

#endif /* INC_LED_H_ */
