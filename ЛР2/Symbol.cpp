#include <iostream>
#include "Symbol.h"
#include "Utils.h"


Symbol::Symbol(int x, int y)
		:x(x), y(y) {
		Utils::useColor(color, background);
	};

	void Symbol::setColor(int _col, int _bg) {
		this->background = _bg;
		this->color = _col;
		Utils::useColor(color, background);
	}

	void Symbol::print(char charCode) {
		printf("\033[%d;%dH%c", y, x, charCode);
	}
