#pragma once

#include "repository.h"
typedef struct {
	Repository* repo;
}Service;

// the ui will contain a pointer to the service
Service* createService(Repository* repo);
void destroyService(Service* service);
int addPlanetService(Service* service, char name[], char type[], double distFromEarth);