#include "map.h"
#include "clocks.h"

class renderer
{	
	public:
		renderer(map *mapPointer, clocks *C);
		~renderer();
		void render();
		void simpleRender();
	private:
};