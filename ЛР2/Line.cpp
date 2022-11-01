#include "Line.h"
#include <ctime>
#include "Utils.h"
#include "Structs.h"

	Line::Line(int x, int y, appData data)
		:Figure(x,y,data.speed),length(data.length), epilepsy(data.epilepsy), probability(data.probability){
		moveTime = clock() + Utils::getRandom(999);
		console = Utils::getConsoleData();
	};
	 void Line::move() {
		if (y <= console.height + length + 1) {
			if (!borderTouched()) {
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
				if (y <= console.height)
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

	//int Line::getLength() {
	//	return length;
	//	}

	 bool Line::checkBlowing() {
		 if (Utils::probabilityCheck(probability) && !borderTouched())
		 {
			 length--;
			 y--;
			 if (length <= 0) {
				 changeStatus();
			}
			 return true;
		 }
		 return false;
	 }

	 bool Line::borderTouched() {
		 if (y > console.height + 1) {
			 return true;
		 }
		 else {
			 return false;
		 }
	 }

	coords Line::getCoords(){
		coords c;
		c.x = x;
		c.y = y;
		return c;
	}

	Line::~Line() {
	}
