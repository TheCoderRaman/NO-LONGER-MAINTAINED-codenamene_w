#include "map.h"
#include "inputStream.h"
#include "clocks.h"

class player
{
	public:
		player(map *mapPointer, inputStream *input, clocks *C, int initX, int initY);
		void step();

		int gear;
	private:
		void move();
		void goToGear(int g);
		void trail();
		void trailDecay();
};