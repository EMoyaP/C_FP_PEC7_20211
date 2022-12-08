/* Header files */
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "coworkingcenter.h"

/* implementation of functions / actions */
void readCenter (tCoworkingCenter *center) {
	int intToBool;
	printf("NAME (A STRING) >>\n");
	scanf("%s",center->name);
	printf("CITY? (A STRING)>>\n");
	scanf("%s",center->city);
	printf("CATEGORY? (1-CATEGORY1, 2-CATEGORY2, 3-CATEGORY3) >>\n");
	scanf("%d",&center->category);
	printf("CENTER TYPE? (1-STARTUPS, 2-FREELANCERS, 3-RURAL, 4-SPECIALIZED, 5-GENERALIST) >>\n");
	scanf("%u",&center->centerType);
	printf("NUM. SPACES? (AN INTEGER) >>\n");
	scanf("%d",&center->numSpaces);
	printf("PRICE (A REAL) >>\n");
	scanf("%f",&center->price);
	printf("DISTANCE TO CITY CENTER IN KM (A REAL) >>\n");
	scanf("%f",&center->distanceFromCityCenter);
	printf("HAS MEETING ROOMS (0-FALSE, 1-TRUE)? >>\n");
	scanf("%d",&intToBool);
	center->hasMeetingRooms = (bool)intToBool;
	printf("HAS AUDITORIUM (0-FALSE, 1-TRUE)? >>\n");
	scanf("%d",&intToBool);
	center->hasAuditorium = (bool)intToBool;
}

void writeCenter (tCoworkingCenter center){
	printf("CENTER'S DATA:\n");
	printf("NAME: %s\n",center.name);
	printf("CITY: %s\n",center.city);	
	printf("CATEGORY (1-CATEGORY1, 2-CATEGORY2, 3-CATEGORY3): %d\n",center.category);
	printf("CENTER TYPE (1-STARTUPS, 2-FREELANCERS, 3-RURAL, 4-SPECIALIZED, 5-GENERALIST): %u\n",center.centerType);	
	printf("NUM. SPACES: %d\n",center.numSpaces);
	printf("PRICE: %.2f\n",center.price);
	printf("DISTANCE TO CITY CENTER IN KM: %.2f\n",center.distanceFromCityCenter);
	printf("HAS MEETING ROOMS (0-FALSE, 1-TRUE): %d\n",center.hasMeetingRooms);	  
	printf("HAS AUDITORIUM (0-FALSE, 1-TRUE): %d\n",center.hasAuditorium);
}

void copyCenter (tCoworkingCenter centerSrc, tCoworkingCenter *centerDst){
    
	strcpy(centerDst->name, centerSrc.name);
    strcpy(centerDst->city, centerSrc.city);
    centerDst->category = centerSrc.category;
    centerDst->centerType = centerSrc.centerType;
    centerDst->numSpaces = centerSrc.numSpaces;
    centerDst->price = centerSrc.price;
    centerDst->distanceFromCityCenter = centerSrc.distanceFromCityCenter;
    centerDst->hasMeetingRooms = centerSrc.hasMeetingRooms;
    centerDst->hasAuditorium = centerSrc.hasAuditorium;
}


float pointsCenter(tCoworkingCenter center, float price, float distance){

	float totalCenterScore;
    float hasRooms;
    float optimalQuantity;
    float extraPricePoints;
    float extraDistancePoints;
        
	if((center.hasMeetingRooms) || (center.hasAuditorium)) {
		hasRooms = POINTS_FACILITIES;
	}else{
		hasRooms = ZERO;
    }

	if(center.numSpaces >= OPTIMAL_WORKSPACES){
		optimalQuantity = POINTS_FACILITIES;
	}else{
            optimalQuantity = ZERO;
	}

	extraPricePoints = A_HUNDRED * (price - center.price) / price;
        
	extraDistancePoints = A_HUNDRED * (distance - center.distanceFromCityCenter) / distance;

	totalCenterScore = hasRooms + optimalQuantity + extraPricePoints + extraDistancePoints;

	return totalCenterScore;

}

tCoworkingCenter cmpPointsCenter (tCoworkingCenter center1, tCoworkingCenter center2){
	float pointsCenter1;
    float pointsCenter2;
    float price;
    float distance;
	tCoworkingCenter winCenter;
        

	/* Read from the standard input channel the price and distance that seem acceptable to us */
    printf("OPTIMAL DISTANCE [KM]? (A REAL) >>\n"); 
    scanf("%f",&distance); 
	printf("OPTIMAL PRICE [EUR]? (A REAL) >>\n"); 
    scanf("%f",&price);
     
	/* Calculate the number of points */
    if ((pointsCenter1 = pointsCenter(center1, price, distance)) >= (pointsCenter2 = pointsCenter(center2, price, distance))) {
        copyCenter(center1,&winCenter); 
    }else{
        copyCenter(center2,&winCenter); 
    }
	return winCenter;
}

