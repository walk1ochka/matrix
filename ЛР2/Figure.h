#pragma once
#include "Structs.h"
class Figure
{
public:
	Figure(int x, int y, int sp = 2);
	~Figure();
	virtual void move();
	virtual bool borderTouched(int x, int y);
	int getMoveTime();
	bool isEnded();
	void changeStatus(bool newStatus=true);
	void moveTimeInc();
private:
	bool ended = false;
protected:
	int speed, x, y;
	int moveTime=0;
	consoleWH console;
};

