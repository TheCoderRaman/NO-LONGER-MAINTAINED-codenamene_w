#include <vector>

#include "map.h"
#include "clocks.h"

class star
{
	public:
		star(map *mapPointer, clocks *C);
		void step();
	private:
		void moveStars(std::vector<std::vector<char>> mapCopy, std::vector<std::vector<int>> mapColorCopy);
		void movePlanet(std::vector<std::vector<char>> mapCopy, std::vector<std::vector<int>> mapColorCopy);
		void createStars(std::vector<std::vector<char>> mapCopy, std::vector<std::vector<int>> mapColorCopy);
};