#pragma once

typedef struct{
	char name[50];
	char type[50];
	double distFromEarth;
} Planet;

Planet createPlanet(char name[], char type[], double distFromEarth);
char* getName(Planet *p);
double getDistance(Planet *p);