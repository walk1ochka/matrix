#include "Line.h"
#include <ctime>
#include "Utils.h"

	Line::Line(int _length, bool _epilepsy, int x, int y, int speed)
		:Figure(x,y,speed),length(_length), epilepsy(_epilepsy){
		moveTime = clock() + Utils::getRandom(999);
	};
	 void Line::move() {
		consoleWH consData = Utils::getConsoleData();
		if (y <= consData.height + length + 1) {
			if (y <= consData.height + 1) {
				const int white = 7;
				int color = white;
				int oldColor = 2;
				int charCode = Utils::getRandom(32, 127);
				if (epilepsy)
				{
					oldColor = Utils::getRandom(1, white-1);
				}
				Symbol s(x + ((y - 1) % 2), y - 1);
				s.setColor(oldColor);
				s.print(prevChar);
				prevChar = charCode;
				if (y <= consData.height)
				{
					Symbol s(x + (y % 2), y);
					s.setColor(color);
					s.print(charCode);
				}
			}
			int newY = y - length;
			Symbol s(x + (newY % 2), newY);
			s.print(' ');
		}
		else {
			changeStatus();
		}
		y++;
	}
	int Line::getLength() {
		return length;
		}
	Line::~Line() {
	}
