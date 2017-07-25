/*
notes
11 default
9 speed up

3 damaged
1 damaged speed up

flash 75 slowy when partly damaged
flash 203 fast when very damaged

trail of > behind, color 3

//redo trail with all different codes
//redo speed
//intigrate speed into stars
*/
#include "player.h"

int lastX, lastY;
int playerX, playerY;
int maxX;
double gear;
static map *m;
inputStream *i;
clocks *c;

player::player(map *mapPointer, inputStream *input, clocks *C, int initX, int initY)
{
	m = mapPointer;
	i = input;
	c = C;

	playerX = initX;
	playerY = initY;
	lastX = initX; 
	lastY = initY;
	maxX = 10;
	gear = 1;

	m->set(m->centerX, m->centerY, '>', 11);
	m->set(m->centerX - 1, m->centerY, 'x', 11);
}

void player::step()
{	
	move();

	if(c->frameCount == 0)
		trailDecay();
		trail();

	if(lastX != playerX || lastY != playerY)
	{
		m->move(lastX - 1, lastY, playerX - 1, playerY);
		m->move(lastX, lastY, playerX, playerY);

		lastX = playerX;
		lastY = playerY;
	}

	if(m->get(playerX, playerY) != '>' || m->getColor(playerX, playerY) != 11)
		m->set(playerX, playerY, '>', 11);
	if(m->get(playerX - 1, playerY) != '#' || m->getColor(playerX - 1, playerY) != 11)
		m->set(playerX - 1, playerY, '#', 11);
}

void player::move()
{
	if(playerX == maxX)
	{
		if(i->inputStr.find("up ") != std::string::npos && gear < 6)
			goToGear(++gear);
		else if (i->inputStr.find("down ") != std::string::npos && gear > 1)
			goToGear(--gear);
	}
	else if (playerX == maxX && m->starSpeed == gear - 1.05)
	{
		if(i->inputStr.find("up ") != std::string::npos)
			goToGear(++gear);
		else if (i->inputStr.find("down ") != std::string::npos)
			goToGear(--gear);
	}	

	if(playerX < maxX)
		playerX++;
	else if(playerX > maxX)
		playerX--;

	if(m->starSpeed < gear - 1.0)
		m->starSpeed+=0.1;
	else if(m->starSpeed > gear - 1.0)
		m->starSpeed-=0.1;
}

void player::goToGear(int g)
{
	switch(g)
	{
		case 1:
			//still moving
			maxX = 10;
			break;
		case 2:
			maxX = 15;
			break;
		case 3:
			maxX = 25;
			break;
		case 4:
			maxX = 35;
			break;
		case 5:
			maxX = 45;
			break;
		case 6:
			maxX = 50;
			break;
	}
}

void player::trail()
{
	if (m->get(playerX - 2, playerY) != '>' && m->getColor(playerX - 2, playerY) != 3)
		m->set(playerX - 2, playerY, '>', 3);
	else if (m->get(playerX - 3, playerY) != '>' && m->getColor(playerX - 3, playerY) != 3)
		m->set(playerX - 3, playerY, '>', 3);
	else if (m->get(playerX - 4, playerY) != '>' && m->getColor(playerX - 4, playerY) != 3)
		m->set(playerX - 4, playerY, '>', 259);
	else if (m->get(playerX - 5, playerY) != '>' && m->getColor(playerX - 5, playerY) != 259)
		m->set(playerX - 5, playerY, '>', 259);
	else if (m->get(playerX - 6, playerY) != '>' && m->getColor(playerX - 6, playerY) != 515)
		m->set(playerX - 6, playerY, '>', 259);
}

void player::trailDecay()
{
	for (int y = 0; y < m->height; y++)
	{
		for (int x = 0; x < m->width; x++)
		{
			if (m->get(x, y) == '>' && m->getColor(x, y) == 3)
				m->set(x, y, '>', 259);
			else if(m->get(x, y) == '>' && m->getColor(x, y) == 259)
				m->set(x, y, '>', 515);
			else if(m->get(x, y) == '>' && m->getColor(x, y) == 515)
				m->set(x, y, m->bgChar, m->bgColor);
		}
	}
}