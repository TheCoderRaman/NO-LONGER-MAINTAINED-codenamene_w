#include <string>
#include <iostream>
#include <Windows.h>
#include <sstream>
#include <vector>
#include <stdlib.h>

using namespace std;

#include "renderer.h"
#include "clocks.h"

static map *m;
static clocks *c;

int framesElapsed = 0;

renderer::renderer(map *mapPointer, clocks *C)
{
	m = mapPointer;
	c = C;
}

void renderer::oldRender()
{
	vector<vector<char>> mapCopy = m->getCopy();
	vector<vector<int>> mapColorCopy = m->getColorCopy();

	for (int y = 0; y < m->height; y++)
	{

		//what if i extend blocks to more than a line
		stringstream block;
		int lastColor = mapColorCopy[y][0];
		int currentColor;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), lastColor);

		for (int x = 0; x < m->width; x++)
		{
			if (mapColorCopy[y][x] == lastColor)
			{
				block << mapCopy[y][x];
			}
			else
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), lastColor);
				cout << block.str();
				block.str(string());
				block.clear();
				block << mapCopy[y][x];
				lastColor = mapColorCopy[y][x];
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), lastColor);
			}
		}
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), lastColor);
		cout << block.str() << endl;
	}
}

void renderer::render()
{
	vector<vector<char>> mapCopy = m->getCopy();
	vector<vector<int>> mapColorCopy = m->getColorCopy();

	stringstream block;
	int lastColor = mapColorCopy[0][0];

	for (int y = 0; y < m->height; y++)
	{
		for (int x = 0; x < m->width; x++)
		{
			if (mapColorCopy[y][x] == lastColor)
			{
				block << mapCopy[y][x];
			}
			else
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), lastColor);
				cout << block.str();
				block.str(string());
				block.clear();
				block << mapCopy[y][x];
				lastColor = mapColorCopy[y][x];
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), lastColor);
			}
		}
		if (y != m->height - 1)
		{
			if (mapColorCopy[y+1][0] == lastColor)
			{
				block << "\n";
			}
		}
		else
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), lastColor);
			cout << block.str();
			block.str(string());
			block.clear();
			block << "\n";
			if (y < m->height - 1)
				lastColor = mapColorCopy[y+1][0];
		}
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), lastColor);
	cout << block.str() << endl;
	block.str(string());
	block.clear();
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	cout << endl << c->frameCount; 
}

void renderer::simpleRender()
{
	for (int y = 0; y < m->height; y++)
	{
		for (int x = 0; x < m->width; x++)
		{
			cout << m->get(x, y);
		}
		cout << endl;
	}
}

renderer::~renderer()
{
	system("color");
}