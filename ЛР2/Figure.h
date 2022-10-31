#pragma once

class Figure
{
public:
	Figure(int sp = 2);
	~Figure();
	virtual void drawNext();
	int getMoveTime();
	bool isEnded();
	void changeStatus();
	int moveTime;
private:
	int speed;
	bool ended = false;
};

