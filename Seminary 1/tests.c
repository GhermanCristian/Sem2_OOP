#include "planet.h"
#include <assert.h>
#include <string.h>
#include "tests.h"
#include "repository.h"

void testPlanet1() {
	Planet p = createPlanet("Costinesti", "Plina de betivi", 5);
	assert(strcmp(getName(&p), "Costinesti") == 0);
	assert(getDistance(&p) == 5);
}

void testRepo1() {
	Repository* repo = createRepository();
	Planet p = createPlanet("Vama Veche", "Iarba", 5);
	addPlanet(repo, p);

	Container data = getAll(repo);
	assert(strcmp(getName(&data.planets[0]), "Vama Veche"), 0);

	dauCuBarosu(repo);
}