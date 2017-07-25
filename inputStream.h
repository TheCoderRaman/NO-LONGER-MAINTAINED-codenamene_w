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
#define VK_SHIFT 0x10
#define VK_R 0x52
#define VK_L 0x4C
#define VK_W 0x57
#define VK_A 0x41
#define VK_S 0x53
#define VK_D 0x44

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
			if(GetAsyncKeyState(VK_SHIFT) != 0)
			{
				input << "shift ";
			}
			if(GetAsyncKeyState(VK_R) != 0)
			{
				input << "r ";
			}
			if(GetAsyncKeyState(VK_L) != 0)
			{
				input << "l ";
			}
			if(GetAsyncKeyState(VK_W) != 0)
			{
				input << "w ";
			}
			if(GetAsyncKeyState(VK_A) != 0)
			{
				input << "a ";
			}
			if(GetAsyncKeyState(VK_S) != 0)
			{
				input << "s ";
			}
			if(GetAsyncKeyState(VK_D) != 0)
			{
				input << "d ";
			}

			inputStr = input.str();
		}
};