#include "Line.h"
#include <ctime>
#include "Utils.h"

	Line::Line(int _length, bool _epilepsy, int x)
		:length(_length), epilepsy(_epilepsy), startX(x) {
		moveTime = clock() + Utils::getRandom(999);
	};
	 void Line::drawNext() {
		consoleWH consData = Utils::getConsoleData();
		if (currentY <= consData.height + length + 1) {
			if (currentY <= consData.height + 1) {
				const int white = 7;
				int color = white;
				int oldColor = 2;
				int charCode = Utils::getRandom(32, 127);
				if (epilepsy)
				{
					oldColor = Utils::getRandom(1, white-1);
				}
				Symbol s(startX + ((currentY - 1) % 2), currentY - 1);
				s.setColor(oldColor);
				s.print(prevChar);
				prevChar = charCode;
				if (currentY <= consData.height)
				{
					Symbol s(startX + (currentY % 2), currentY);
					s.setColor(color);
					s.print(charCode);
				}
			}
			int newY = currentY - length;
			Symbol s(startX + (newY % 2), newY);
			s.print(' ');
		}
		else {
			changeStatus();
		}
		currentY++;
	}
	int Line::getLength() {
		return length;
		}
	Line::~Line() {
	}
