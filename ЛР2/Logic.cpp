#include "Logic.h"
#include <vector>
#include <iostream>
#include "Blow.h"
#include "MyVector.cpp"
#include "Figure.h"

using namespace std;


Logic::Logic() {
		hello();
		data.speed = readInt("Enter the speed of the line",1,30);
		data.length = readInt("Enter the length of the line",1, 30);
		data.frequency = readInt("Enter the lines frequency", 1, 30);
		data.probability = readInt("Enter the probability of blowing", 1, 1000);
		while (true)
		{
			data.minRadius = readInt("Enter the lower radius of blowing", 1, 10);
			data.maxRadius = readInt("Enter the higher radius of blowing", 1, 10);
			if (data.minRadius <= data.maxRadius) {
				break;
			}
			else
			{
				cout << "lower radius mustn't be over higher!";
			}
		}
		data.epilepsy = readBool("Do you want some epilepsy?");
	}

	void Logic::start() {
		myVector<Figure*> figures;
		system("cls");
		int prevTime = clock() - 1000;
		while (true)
		{
			if (clock() - prevTime >= 1000)
			{
				for (size_t i = 0; i < data.frequency; i++)
				{
					Line* l = new Line(Utils::getRandom(Utils::getConsoleData().width),1,data);
					figures.pushBack(l);
				}
				prevTime = clock();
			}
			for (size_t i = 0; i < figures.getLength(); i++)
			{
				if (clock() >= figures[i]->getMoveTime())
				{
					figures[i]->move();
					figures[i]->moveTimeInc();
					if (figures[i]->isLine())
					{
						if (figures[i]->checkBlowing())
						{
							coords XY = (figures[i]->getCoords());
							Blow* b = new Blow(XY.x, XY.y, data.maxRadius, data.maxRadius);
							
							figures.pushBack(b);
						}
					}
					
				}				
				if (figures[i]->isEnded())
				{
					if (!figures[i]->isLine())
					{
						figures[i]->move();
					}
					delete figures[i];
					figures.erase(figures.begin() + i);
				}
				
			}
		}
	}

	void  Logic::hello() {
		cout << "Hello!" << endl << "This is the Matrix app where" << endl << "symbols are falling from the sky like zig-zag!" << endl << endl;
	}
	int Logic::readInt(string message,int lBorder,int rBorder) {
		while (true)
		{
			string str;
			cout << message << " (Number "<<lBorder<<'-'<< rBorder<<"): ";
			cin >> str;
			if (Utils::isNumber(str))
			{
				if (stoi(str) < lBorder || stoi(str) > rBorder)
				{
					cout << "Wrong range, write number between " << lBorder <<" and " << rBorder << "!" << endl;
				}
				else
				{
					return stoi(str);
				}
			}
			else
			{
				cout << "Wrong insert data, write integer!" << endl;
			}
		}
	}
	bool Logic::readBool(string message) {
		while (true)
		{
			char ch;
			cout << message << " (Y/N): ";
			cin >> ch;
			if (ch == 'Y' or ch == 'y')
			{
				return true;
			}
			else if (ch == 'N' or ch == 'n') {
				return false;
			}
			else
			{
				cout << "Wrong insert data, write Y or N!!" << endl;
			}
		}
	}
