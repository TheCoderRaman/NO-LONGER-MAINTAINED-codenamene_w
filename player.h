#include "map.h"
#include "inputStream.h"
#include "clocks.h"

class player
{
	public:
		player(map *mapPointer, inputStream *input, clocks *C, int initX, int initY);
		void step();
		void trail();
};