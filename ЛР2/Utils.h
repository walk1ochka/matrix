#pragma once
#include <string>
#include "Structs.h"


class Utils {
public:
	static consoleWH getConsoleData();
	
	static bool isNumber(std::string str);
	static void useColor(int color, int background=0);
	static int getRandom(int left, int right);
	static int getRandom(int right);
};