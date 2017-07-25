#include <iostream>
#include <string>
#include <vector>
#include <time.h>
#include <Windows.h>

#include "renderer.h"
#include "star.h"
#include "clocks.h"
#include "inputStream.h"
#include "player.h"
#include "text.h"

//KEEP IN MIND USING PRAGMA ON MAP.H, CLOCKS.H, AND INPUTSTREAM.H

int main()
{
	begin:
	long int ti = static_cast<long int>(time(NULL));
	int last_frame = 0;
	int timeofesc = 0;
	int limiter = 0;
	clocks mainClock;
	clocks playerInterval(2);

	inputStream i;

	map map1(94, 20, 15, ' ');
	renderer r(&map1, &mainClock);
	star s(&map1, &mainClock);
	player player1(&map1, &i, &playerInterval, map1.centerX, map1.centerY);
	text t(&map1);

	t.addLabel(4, 16, "TUTORIAL", 207, 100);//move to apropriate class when availabale
	t.addLabel(4, 17, "-You're always moving", 207, 100);//move to apropriate class when availabale

	while(true)
	{
		t.addLabel(0, 0, std::to_string(map1.fps) + "fps" + " gear " + 
			std::to_string(player1.gear), map1.bgColor, 1); //move to HUD.cpp
		if (static_cast<long int>(time(NULL)) > ti)
		{
			map1.fps = mainClock.frameCount - last_frame;
			last_frame = mainClock.frameCount;
			ti = static_cast<long int>(time(NULL));
		}

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

		if (i.inputStr.find("l ") != std::string::npos && i.inputStr.find("shift ") == std::string::npos && limiter < 50 &&
			i.inputStr.find("ctrl ") == std::string::npos)
			limiter++;
		else if (i.inputStr.find("l ") != std::string::npos && i.inputStr.find("shift ") != std::string::npos && limiter > 0)
			limiter--;

		Sleep(limiter);//move to RENDERER.cpp
		system("cls");//move to RENDERER.cpp
		mainClock.increment();
		playerInterval.increment();
		i.listen();

		s.step();
		player1.step();
		t.print();
		r.render();
	}
}