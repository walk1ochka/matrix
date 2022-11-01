#include "Figure.h"
#include "Symbol.h"

Figure::Figure(int x, int y, int sp)
	:x(x),y(y),speed(sp){
}

int Figure::getMoveTime(){
	return moveTime;
}
void Figure::changeStatus(bool newStatus) {
	ended = newStatus;
}
void Figure::move() {
	Symbol s(2,10);
	s.setColor(1);
	s.print('?');
}
void Figure::moveTimeInc() {
	moveTime += 1000 / speed;
}
bool Figure::isEnded() {
	return ended;
}
Figure::~Figure()
{
}