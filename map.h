#pragma once
#include <string>
#include <vector>

class map
{
	public:
		map(int w, int h, int bgcolor, char bgchar);
		char get(int x, int y);
		int getColor(int x, int y);
		void move(int x, int y, int newx, int newy);
		void set(int x, int y, char newChar, int newColor);
		void setChar(int x, int y, char newChar);
		void setColor(int x, int y, int newColor);
		char replace(int x, int y, char newChar);
		int replaceColor(int x, int y, int newChar);
		void swap(int x, int y, int x2, int y2);
		std::vector<std::vector<char>> getCopy();
		std::vector<std::vector<int>> getColorCopy();

		int width;
		int centerX;
		int height;
		int centerY;
		char bgChar;
		int bgColor;
		int playerX;
		int playerY;
	private:
};