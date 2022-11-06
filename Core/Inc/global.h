/*
 * global.h
 *
 *  Created on: Nov 2, 2022
 *      Author: tan
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

#define INIT 1
#define AUTO_RED 2
#define AUTO_GREEN 3
#define AUTO_YELLOW 4

#define ON 0
#define OFF 1

extern int status1;
extern int status2;
extern int ledRedTime;
extern int ledYellowTime;
extern int ledGreenTime;
extern int mode;

void reinitStatus();

#endif /* INC_GLOBAL_H_ */
