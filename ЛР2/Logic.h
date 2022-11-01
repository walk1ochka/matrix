#pragma once
#include <string>
#include "Structs.h"
#include "Utils.h"
#include "Line.h"

class Logic {

public:
	Logic();
	void start();
	appData getData();
private:
	appData data;
	void hello();
	int readInt(std::string message, int lBorder, int rBorder);
	bool readBool(std::string message);
};