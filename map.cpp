#include <string>
#include <iostream>
#include <Windows.h>
#include <vector>

using namespace std;

#include "map.h"

int width, height;
int centerX, centerY;
int bgColor;
char bgChar;
double starSpeed;
int fps;
vector<vector<char>> mapV;
vector<vector<int>> colorMapV; //implement

map::map(int w, int h, int bgcolor, char bgchar)
{
	width = w;
	centerX = w / 2;
	height = h;
	centerY = h / 2;
	bgColor = bgcolor;
	bgChar = bgchar;
	starSpeed = 0.0;
	fps = 0;

	for (int y = 0; y < h; y++)
	{
		vector<char> row (w);
		fill(row.begin(), row.end(), bgChar);
		mapV.push_back(row);
	}

	for (int y = 0; y < h; y++)
	{
		vector<int> row (w);
		fill(row.begin(), row.end(), bgColor);
		colorMapV.push_back(row);
	}	
}

char map::get(int x, int y)
{
	return mapV[y][x];
}


int map::getColor(int x, int y)
{
	return colorMapV[y][x];
}

void map::move(int x, int y, int newx, int newy)
{
	mapV[newy][newx] = mapV[y][x];
	mapV[y][x] = bgChar;
	colorMapV[newy][newx] = colorMapV[y][x];
	colorMapV[y][x] = bgColor;
}

void map::set(int x, int y, char newChar, int newColor)
{
	mapV[y][x] = newChar;
	colorMapV[y][x] = newColor;
}

void map::setChar(int x, int y, char newChar)
{
	mapV[y][x] = newChar;
}

void map::setColor(int x, int y, int newColor)
{
	colorMapV[y][x] = newColor;
}

char map::replace(int x, int y, char newChar)
{
	char old = mapV[y][x];
	mapV[y][x] = newChar;
	return old;
}

int map::replaceColor(int x, int y, int newColor)
{
	int old = colorMapV[y][x];
	colorMapV[y][x] = newColor;
	return old;
}

void map::swap(int x, int y, int x2, int y2)
{
	char c = mapV[y][x];
	int c2 = colorMapV[y][x];
	mapV[y][x] = mapV[y2][x2];
	mapV[y2][x2] = c;
	colorMapV[y][x] = colorMapV[y2][x2];
	colorMapV[y2][x2] = c2;
}

vector<vector<char>> map::getCopy()
{
	return mapV;
}

vector<vector<int>> map::getColorCopy()
{
	return colorMapV;
}