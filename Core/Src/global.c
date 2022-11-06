/*
 * global.c
 *
 *  Created on: Nov 2, 2022
 *      Author: tan
 */

#include"global.h"

int mode = 1;

int status1 = INIT;
int status2 = INIT;
int ledRedTime = 5;
int ledYellowTime = 2;
int ledGreenTime = 3;

void reinitStatus(){
	status1 = INIT;
	status2 = INIT;
}
