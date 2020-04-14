#include "planet.h"
#include <string.h>

Planet createPlanet(char name[], char type[], double distFromEarth) {
	Planet newPlanet;
	strcpy(newPlanet.name, name);
	strcpy(newPlanet.type, type);
	newPlanet.distFromEarth = distFromEarth;

	return newPlanet;
}

char *getName(Planet *p) {
	return p->name;
}

double getDistance(Planet *p) {
	return p->distFromEarth;
}