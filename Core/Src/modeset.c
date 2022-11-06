/*
 * modeset.c
 *
 *  Created on: Nov 2, 2022
 *      Author: tan
 */

#include"modeset.h"

void modeset(){
	if(isButton1Pressed()==1){
		mode++;
		if(mode==4){
			mode = 1;
		}
	}
}


