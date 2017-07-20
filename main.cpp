#include <iostream>
#include <string>

#include "renderer.h"
#include "star.h"
#include "clocks.h"
#include "inputStream.h"
#include "player.h"

//KEEP IN MIND USING PRAGMA ON MAP.H, CLOCKS.H, AND INPUTSTREAM.H

int main()
{
	begin:
	int timeofesc = 0;
	clocks mainClock;
	clocks shortInterval(10);

	inputStream i;

	map map1(94, 20, 15, ' ');
	renderer r(&map1, &mainClock);
	star s(&map1, &shortInterval);
	player player1(&map1, &i, &shortInterval, map1.centerX, map1.centerY);

	while(true)
	{
		if (i.inputStr.find("esc ") != std::string::npos)
		{
			if(timeofesc == 0)
				timeofesc = mainClock.frameCount;
			else if (mainClock.frameCount >= timeofesc + 20)
				return 0;
			else if (mainClock.frameCount >= timeofesc + 5)
				std::cout << ""; //menu
		}
		else if (timeofesc != 0)
			timeofesc = 0;

		if (i.inputStr.find("r ") != std::string::npos)
			goto begin;
		system("cls");
		mainClock.increment();
		shortInterval.increment();
		i.listen();

		r.render();
		s.step();
		player1.step();
	}
}