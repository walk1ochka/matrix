#pragma once
#include "Symbol.h"
#include "Structs.h"
#include "Figure.h"

class Line : public Figure {
public:
	Line(int _length, bool _epilepsy, int x);
	int getLength();
	~Line();
	void drawNext();
private:
	int  length, currentY = 1, startX, prevChar = 32;
	bool epilepsy;
};