#pragma once

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
private:
	bool ended = false;
protected:
	int speed, x, y;
	int moveTime=0;
};

