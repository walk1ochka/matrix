#pragma once
#include "Symbol.h"
#include "Structs.h"


class Line {
public:
	Line(int _length, bool _epilepsy, int x);
	void drawNext();
	int getLength();
	bool ended = 0;
	int moveTime;
	virtual ~Line();

private:
	int  length, count = 0, currentY = 1, startX, prevChar = 32;
	bool epilepsy;
};