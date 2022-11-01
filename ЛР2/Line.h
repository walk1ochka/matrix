#pragma once
#include "Symbol.h"
#include "Structs.h"
#include "Figure.h"

class Line : public Figure {
public:
	Line(int x, int y, appData data);
	~Line();
	void move();
	coords getCoords();
	bool checkBlowing();
	bool borderTouched();
private:
	int  length, prevChar = 32,probability;
	bool epilepsy,blowing = 0;
	consoleWH console;
};