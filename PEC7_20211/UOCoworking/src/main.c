/*
* File: main.c
* Author: Eugenio Moya
* Course: 20211
* Descripción: PEC7 2021 1
*/

/* System header files */
#include "coworkingcenter.h"

/* main code */
int main(int argc, char **argv){
	tCoworkingCenter center1;
	tCoworkingCenter center2;
	tCoworkingCenter winCenter;
		
	readCenter(&center1);
	readCenter(&center2);
	winCenter = cmpPointsCenter(center1,center2);
	printf("RESULT\n");
	printf("THE BEST CHOICE IS:\n");
	writeCenter(winCenter);

	return 0;
	
}