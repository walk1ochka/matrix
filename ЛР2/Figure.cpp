#include "Figure.h"
#include "Symbol.h"

Figure::Figure(int sp)
{
	speed = sp;
}

int Figure::getMoveTime(){
	return moveTime;
}
void Figure::changeStatus() {
	ended = !ended;
}
void Figure::drawNext() {
	Symbol s(2,10);
	s.setColor(1);
	s.print('A');
}
bool Figure::isEnded() {
	return ended;
}
Figure::~Figure()
{
}