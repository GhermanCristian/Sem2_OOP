#include "repository.h"

Repository* createRepository() {
	Repository* repo = (Repository*)malloc(sizeof(Repository));
	if (repo == NULL) {
		return NULL;
	}

	repo->data.length = 0;
	return repo;
}

int hasPlanet(Repository* repo, Planet p) {
	for (int i = 0; i < repo->data.length; i++) {
		if (strcmp(&repo->data.planets[i].name) == 0) {
			return 1;
		}
	}
	return 0;
}

int addPlanet(Repository* repo, Planet p) {
	if (!hasPlanet(repo, p)) {
		return -1;
	}

	repo->data.planets[++repo->data.length] = p;
	return 0;
}

Container getAll(Repository *repo) {
	return repo->data;
}

void dauCuBarosu(Repository* repo) {
	free(repo);
}