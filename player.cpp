/*
notes
11 default
9 speed up

3 damaged
1 damaged speed up

flash 75 slowy when partly damaged
flash 203 fast when very damaged

trail of > behind, color 3
*/
#include "player.h"

int lastX, lastY;
map *m;
inputStream *i;
clocks *c;

player::player(map *mapPointer, inputStream *input, clocks *C, int initX, int initY)
{
	m = mapPointer;
	i = input;
	c = C;

	m->playerX = initX;
	m->playerY = initY;
	lastX = initX; 
	lastY = initY;

	m->set(m->centerX, m->centerY, '>', 11);
	m->set(m->centerX - 1, m->centerY, 'x', 11);
}

void player::step()
{
	if(i->inputStr.find("up ") == std::string::npos && m->playerX > 10)
		m->playerX--;

	if(c->frameCount == 0)
		trail();

	if(lastX != m->playerX || lastY != m->playerY)
	{
		m->move(lastX - 1, lastY, m->playerX - 1, m->playerY);
		m->move(lastX, lastY, m->playerX, m->playerY);

		lastX = m->playerX;
		lastY = m->playerY;

	}

	if(m->get(m->playerX, m->playerY) != '>' || m->getColor(m->playerX, m->playerY) != 11)
		m->set(m->playerX, m->playerY, '>', 11);
	if(m->get(m->playerX - 1, m->playerY) != '#' || m->getColor(m->playerX - 1, m->playerY) != 11)
		m->set(m->playerX - 1, m->playerY, '#', 11);
}

void player::trail()
{
	if(i->inputStr.find("up ") != std::string::npos 
		&& m->get(m->playerX - 2, m->playerY) != '>' && m->getColor(m->playerX - 2, m->playerY) != 3)
		m->set(m->playerX - 2, m->playerY, '>', 3);
	else if (i->inputStr.find("up ") != std::string::npos 
		&& m->get(m->playerX - 3, m->playerY) != '>' && m->getColor(m->playerX - 3, m->playerY) != 3)
		m->set(m->playerX - 3, m->playerY, '>', 3);
	else if (i->inputStr.find("up ") != std::string::npos 
		&& m->get(m->playerX - 4, m->playerY) != '>' && m->getColor(m->playerX - 4, m->playerY) != 259)
		m->set(m->playerX - 4, m->playerY, '>', 259);
	else if (i->inputStr.find("up ") != std::string::npos 
		&& m->get(m->playerX - 5, m->playerY) != '>' && m->getColor(m->playerX - 5, m->playerY) != 259)
		m->set(m->playerX - 5, m->playerY, '>', 259);
	else if (i->inputStr.find("up ") != std::string::npos 
		&& m->get(m->playerX - 6, m->playerY) != '>' && m->getColor(m->playerX - 6, m->playerY) != 259)
		m->set(m->playerX - 6, m->playerY, '>', 259);
}
