#include "Logic.h"
#include <vector>
#include <iostream>
#include "Blow.h"

using namespace std;


Logic::Logic() {
		//Utils::useColor(15, 0);
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
		vector <Line*> lines;
		vector <Blow*> blows;
		system("cls");
		int prevTime = clock() - 1000;
		while (true)
		{
			if (clock() - prevTime >= 1000)
			{
				for (size_t i = 0; i < data.frequency; i++)
				{
					Line* l = new Line(Utils::getRandom(Utils::getConsoleData().width),1,data);
					lines.push_back(l);
				}
				prevTime = clock();
			}
			for (size_t i = 0; i < lines.size(); i++)
			{
				if (clock() >= (*lines[i]).getMoveTime())
				{
					(*lines[i]).move();
					(*lines[i]).moveTimeInc();
					coords XY = (*lines[i]).getCoords();
					if ((*lines[i]).checkBlowing())
					{
						Blow* b = new Blow(XY.x, XY.y, data.maxRadius, data.maxRadius);
						blows.push_back(b);
					}
				}				
				if ((*lines[i]).isEnded())
				{
					delete lines[i];
					lines.erase(lines.begin() + i);
				}
				
			}
			for (size_t i = 0; i < blows.size(); i++)
			{
				if (clock() >= (*blows[i]).getMoveTime())
				{
					(*blows[i]).move();
					(*blows[i]).moveTimeInc();
				}
				if ((*blows[i]).isEnded())
				{
					delete blows[i];
					blows.erase(blows.begin() + i);
				}
			}
		}
	}

	appData Logic::getData() {
		return data;
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
