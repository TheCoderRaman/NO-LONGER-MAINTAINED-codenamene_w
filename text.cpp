#include <iostream>
#include <string>
#include <vector>

#include "text.h"

static map *m;

//make pointer labels for dynamic labels

struct label
{
	int x, y;
	std::string txt;
	int color;
	int frames;
};

static std::vector<label> labels;

text::text(map *mapPointer)
{
	m = mapPointer;
	labels.resize(0);
}

void text::addLabel(int x, int y, std::string txt, int color, int frames)
{
	labels.reserve(labels.size() + 1);
	label l;
	l.x = x;
	l.y = y;
	l.txt = txt;
	l.color = color;
	l.frames = frames;
	labels.push_back(l);
}

void text::print()
{
	for (int x = 0; x < labels.size(); x++)
	{
		if (labels[x].frames < 1)
		{
			for (int y = 0; y < labels[x].txt.length(); y++)
				m->set(labels[x].x + y, labels[x].y, m->bgChar, m->bgColor);	
			labels.erase(labels.begin() + x);
		}
	}

	for (int x = 0; x < labels.size(); x++)
	{
		for (int y = 0; y < labels[x].txt.length(); y++)
		{
			m->set(labels[x].x + y, labels[x].y, labels[x].txt[y], labels[x].color);		
		}
		if(labels[x].frames > 0)
			labels[x].frames--;
	}

}