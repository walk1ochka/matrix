#include "Blow.h"
#include <stdio.h>
#include "Utils.h"
#include "Symbol.h"
#include <ctime>

Blow::Blow(int x,int y,int maxR, int minR)
	:Figure(x,y){
	moveTime = clock() + 1000 / speed;
	radius = Utils::getRandom(minR, maxR);
}

Blow::~Blow()
{
}
void Blow::move() {
	for (int i = -currentRadius; i <= currentRadius; i++)
	{
		for (int j = -currentRadius; j <= currentRadius; j++)
		{
			int length = abs(i) + abs(j);
			int newX = x + i, newY = y + j;
			if ( length == currentRadius)
			{
				Symbol s(newX,newY);
				s.setColor(Utils::getRandom(1, 6));
				s.print(Utils::getRandom(32, 127));
			}
			else if (length < currentRadius) {
				Symbol s(newX, newY);
				s.print(' ');
			}
		}
	}
	if (currentRadius == radius)
	{
		changeStatus();
	}
	currentRadius++;
}