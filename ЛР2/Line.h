#pragma once
#include "Symbol.h"
#include "Structs.h"
#include "Figure.h"

class Line : public Figure {
public:
	Line(int _length, bool _epilepsy, int x, int y, int speed);
	int getLength();
	~Line();
	void move();
	
private:
	int  length, prevChar = 32;
	bool epilepsy;
};