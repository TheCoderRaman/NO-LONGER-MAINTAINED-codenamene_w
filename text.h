#include <string>
#include <vector>

#include "map.h"

class text
{
	public:
		text(map *mapPointer);
		void addLabel(int x, int y, std::string txt, int color, int frames);
		void print();
};