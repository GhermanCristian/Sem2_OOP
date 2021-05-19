#include <vector>
#include "domain.h"

const std::string STARS_FILE_PATH = "stars.txt";
const std::string ASTRONOMERS_FILE_PATH = "astronomers.txt";

class Repository{
	private:
		std::vector <Star> stars;
		std::vector <Astronomer> astronomers;

	public:
		Repository();
		std::vector <Star> getAllStars();
		std::vector <Astronomer> getAllAstronomers();
		void loadStarsFromFile();
		void loadAstronomersFromFile();
		void addStar(Star newStar);
		/*
			Adds a new star to the star list (if the star is valid)
			Input:
				- The star that we want to add
			Output:
				- Throws exception if the star's name is empty, if its diameter is <= 0, or if there already is a star
				with that name
				- Otherwise, the star is added to the list
		*/
		~Repository();
};

