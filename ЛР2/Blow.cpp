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
	move();
}
void Blow::move() {
	for (int i = -currentRadius; i <= currentRadius; i++)
	{
		for (int j = -currentRadius; j <= currentRadius; j++)
		{
			const int space = 32;
			int charCode = space;
			int length = abs(i) + abs(j);
			int newX = x + i, newY = y + j;
			if ( length == currentRadius)
			{
				if (!isEnded())
				{
					charCode = Utils::getRandom(space + 1, 127);
				}
				Symbol s(newX,newY);
				s.setColor(Utils::getRandom(1, 6));
				s.print(charCode);
			}
			else if (length < currentRadius) {
				Symbol s(newX, newY);
				s.print(space);
			}
		}
	}
	if (currentRadius >= radius)
	{
		changeStatus();
	}
	currentRadius++;
}