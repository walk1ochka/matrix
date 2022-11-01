#pragma once
#include "Figure.h"
class Blow:public Figure
{
public:
	Blow(int x, int y, int maxR, int minR);
	~Blow();
	void move();
private:
	int radius,currentRadius = 0;
};

