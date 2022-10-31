#include "Logic.h"
#include <vector>
#include <iostream>

using namespace std;


Logic::Logic() {
		//Utils::useColor(15, 0);
		hello();
		data.speed = readInt("Enter the speed of the line");
		data.length = readInt("Enter the length of the line");
		data.frequency = readInt("Enter the lines frequency");
		data.epilepsy = readBool("Do you want some epilepsy?");
	}

	void Logic::start() {
		vector <Line*> lines;
		system("cls");
		int prevTime = clock() - 1000;
		while (true)
		{
			if (clock() - prevTime >= 1000)
			{
				for (size_t i = 0; i < data.frequency; i++)
				{
					Line* l = new Line(data.length, data.epilepsy, Utils::getRandom(Utils::getConsoleData().width));
					lines.push_back(l);
				}
				prevTime = clock();
			}
			for (size_t i = 0; i < lines.size(); i++)
			{
				if (clock() >= (*lines[i]).moveTime)
				{
					(*lines[i]).drawNext();
					(*lines[i]).moveTime += 1000 / data.speed;
				}
				if ((*lines[i]).isEnded())
				{
					delete lines[i];
					lines.erase(lines.begin() + i);
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
	int Logic::readInt(string message) {
		while (true)
		{
			string str;
			cout << message << " (Number 1-30): ";
			cin >> str;
			if (Utils::isNumber(str))
			{
				if (stoi(str) < 1 || stoi(str) > 30)
				{
					cout << "Wrong range, write number between 1 and 30!" << endl;
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
