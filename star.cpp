#include <string>
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>

using namespace std;

#include "star.h"

static map *m;
static clocks *c;

/*
make speed slower when nothing based on spee
*/

int speed;

star::star(map *mapPointer, clocks *C)
{
	m = mapPointer;
	c = C;

	srand (time(NULL));
}

void star::step()
{
	vector<vector<char>> mapCopy = m->getCopy();
	vector<vector<int>> mapColorCopy = m->getColorCopy();

	moveStars(mapCopy, mapColorCopy);
	//movePlanet(mapCopy, mapColorCopy); maybe planets are good repurposed as enemies
	createStars(mapCopy, mapColorCopy);
}

void star::movePlanet(vector<vector<char>> mapCopy, vector<vector<int>> mapColorCopy)
{
	for (int y = 0; y < m->height; y++)
	{
		for (int x = 0; x < m->width; x++)
		{
			if (mapCopy[y][x] == ' ' && mapColorCopy[y][x] == 153)
			{
				if (x == 0)
				{
					m->set(x, y, m->bgChar, m->bgColor);
					m->set(x + 1, y, m->bgChar, m->bgColor);
				}

				m->move(x, y, x - 1, y);
			}
		}
	}
}

void star::moveStars(vector<vector<char>> mapCopy, vector<vector<int>> mapColorCopy)
{
	for (int y = 0; y < m->height; y++)
	{
		for (int x = 0; x < m->width; x++)
		{
			if (mapCopy[y][x] == '*' && mapColorCopy[y][x] == 14)
			{
				if (x == 0)
				{
					m->set(x, y, m->bgChar, m->bgColor);
					m->set(x + 1, y, m->bgChar, m->bgColor);
				}
				int dif = (rand() % 8 + 1);
				if (dif > x)
				{
					dif = x;
				}
				m->move(x, y, x - dif, y);
				m->move(x + 1, y, x - dif + 1, y);
			}
		}
	}
}

void star::createStars(vector<vector<char>> mapCopy, vector<vector<int>> mapColorCopy)
{
	if (c->frameCount == 0)
	{
		for (int y = 0; y < m->height; y++)
		{
			if (rand() % 5 + 1 == 2)
			{
				m->set(m->width - 2, y, '*', 14);
				m->set(m->width - 1, y, '*', 15);
			}
		}
	}
}