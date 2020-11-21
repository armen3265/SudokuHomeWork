#pragma once

class Sudoku
{
public:
	static const int size = 9;
	void enterDigits();
	void solve();
	void print();
	
private:
	int Board[size][size];
};