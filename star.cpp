#include <string>
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include <algorithm>

using namespace std;

#include "star.h"

static map *m;
static clocks *c;

static int wait;

star::star(map *mapPointer, clocks *C)
{
	m = mapPointer;
	c = C;

	wait = c->frameCount + (rand() % 14 - m->starSpeed + 1);

	srand (time(NULL));
}

void star::step()
{
	if(m->starSpeed < 0)
		m->starSpeed = 0;

	vector<vector<char>> mapCopy = m->getCopy();
	vector<vector<int>> mapColorCopy = m->getColorCopy();

	moveStars(mapCopy, mapColorCopy);
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
					if(mapCopy[y][x+1] == '*' && mapColorCopy[y][x+1] == 15)
						m->set(x + 1, y, m->bgChar, m->bgColor);
				}
				int dif = (rand() % 4 + m->starSpeed) + 1;
				if (dif > x)
					dif = x;
				m->move(x, y, x - dif, y);
				if(mapCopy[y][x+1] == '*' && mapColorCopy[y][x+1] == 15)
					m->move(x + 1, y, x - dif + 1, y);
			}
			if(mapCopy[y][x] == '*' && mapColorCopy[y][x] == 15 && mapCopy[y][x - 1] != '*' && mapColorCopy[y][x - 1] != '14')
				m->set(x, y, m->bgChar, m->bgColor);
		}
	}
}

void star::createStars(vector<vector<char>> mapCopy, vector<vector<int>> mapColorCopy)
{
	if (c->frameCount >= wait)
	{
		for (int y = 0; y < m->height; y++)
		{
			if (rand() % 5 + 1 == 2)
			{
				m->set(m->width - 2, y, '*', 14);
				m->set(m->width - 1, y, '*', 15);
			}
		}
		wait = c->frameCount + (rand() % 14 - m->starSpeed + 1);
	}
}