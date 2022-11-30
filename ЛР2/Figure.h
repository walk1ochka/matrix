#pragma once
#include "Structs.h"
class Figure
{
public:
	Figure(int x, int y, int sp = 2);
	~Figure();
	virtual void move();
	int getMoveTime();
	bool isEnded();
	void changeStatus(bool newStatus=true);
	void moveTimeInc();
	virtual bool isLine();
	coords getCoords();
	virtual bool checkBlowing();
private:
	bool ended = false;
protected:
	int speed, x, y;
	int moveTime=0;
	bool line = false;
	consoleWH console;
	virtual bool borderTouched(int x, int y);
};

