#pragma once
#include "planet.h"
#include <stdlib.h>
#define MAX_SIZE 128

typedef struct {
	Planet planets[MAX_SIZE];
	int length;
}Container;

typedef struct{
	Container data;
}Repository;

// here is where I write the specifications
Repository* createRepository();
int addPlanet(Repository *repo, Planet p);
int hasPlanet(Repository *repo, Planet p);
Container getAll(Repository *repo);
void dauCuBarosu(Repository* repo);