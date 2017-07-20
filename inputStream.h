#pragma once

#include <iostream>
#include <Windows.h>
#include <string>
#include <sstream>

#define VK_CONTROL 0x11
#define VK_RIGHT 0x27
#define VK_LEFT 0x25
#define VK_UP 0x26
#define VK_DOWN 0x28
#define VK_SPACE 0x20
#define VK_ESCAPE 0x1B
#define VK_R 0x52

class inputStream
{
	public:
		std::string inputStr;
		std::stringstream input;

		inputStream()
		{

		}

		void listen()
		{
			input.str(std::string());
			input.clear();

			if(GetAsyncKeyState(VK_SPACE) != 0)
			{
				input << "space ";
			}
			if(GetAsyncKeyState(VK_LEFT) != 0)
			{
				input << "left ";
			}
			if(GetAsyncKeyState(VK_UP) != 0)
			{
				input << "up ";
			}
			if(GetAsyncKeyState(VK_DOWN) != 0)
			{
				input << "down ";
			}
			if(GetAsyncKeyState(VK_RIGHT) != 0)
			{
				input << "right ";
			}
			if(GetAsyncKeyState(VK_CONTROL) != 0)
			{
				input << "ctrl ";
			}
			if(GetAsyncKeyState(VK_ESCAPE) != 0)
			{
				input << "esc ";
			}
			if(GetAsyncKeyState(VK_R) != 0)
			{
				input << "r ";
			}

			inputStr = input.str();
		}
};