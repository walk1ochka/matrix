#pragma once

class Symbol {
public:
	int x;
	int y;

	Symbol(int x, int y);
	void setColor(int _col, int _bg=0);
	void print(char charCode);
private:
	int color=15;
	int background=0;
};