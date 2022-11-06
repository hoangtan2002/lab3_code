/*
 * 7seg.h
 *
 *  Created on: Oct 30, 2022
 *      Author: tan
 */

#ifndef INC_7SEG_H_
#define INC_7SEG_H_

#include"main.h"
#include"global.h"
#include"software_timer.h"

extern int ledBuffer[4];
extern int segCounter;
extern int countDownTime1;
extern int countDownTime2;

void update7SEG(int n);
void display7SEG(int n);
void updateClock1(int num);
void updateClock2(int num);
void segLEDScan();
void selectSEG(int n);
void setCountDown1(int n);
void setCountDown2(int n);
void countDown1();
void disableCountDown();

#endif /* INC_7SEG_H_ */
