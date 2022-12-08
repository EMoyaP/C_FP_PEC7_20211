/* Header files */
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

/* Global constants */
#define CATEGORY1 1   				//Category 1 id
#define CATEGORY2 2   				//Category 2 id
#define CATEGORY3 3   				//Category 3 id
#define MAX_CHAR_LEN 15+1			//Max. char len
#define POINTS_FACILITIES 5.0     //Points for facilities
#define OPTIMAL_WORKSPACES 3    	//Optimal amount of workspaces       
#define ZERO 0
#define A_HUNDRED 100.0

/* User defined types */
typedef enum {STARTUPS, FREELANCERS, RURAL, SPECIALIZED, GENERALIST} tCoworkingType;

/* User defined Struct */
typedef struct {
    char name[MAX_CHAR_LEN];
    char city[MAX_CHAR_LEN];
    int category;
    tCoworkingType centerType;
	int numSpaces;
    float price;
    float distanceFromCityCenter;
	bool hasMeetingRooms;
	bool hasAuditorium;
} tCoworkingCenter;

/* Predeclaration of functions / actions */
void readCenter (tCoworkingCenter *center);
void writeCenter (tCoworkingCenter center);
void copyCenter (tCoworkingCenter centerSrc, tCoworkingCenter *centerDst);
float pointsCenter (tCoworkingCenter center, float price, float distance);
tCoworkingCenter cmpPointsCenter (tCoworkingCenter center1, tCoworkingCenter center2);
