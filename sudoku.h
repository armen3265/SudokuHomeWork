#pragma once
#ifndef SUDOKU_H
#define SUDOKU_H

#include <iostream>
#include <string>

class Sudoku
{
public:
	static const int size = 9;
	void enterDigits(const std::string board[size]);
	void solve();
	void print();
  std::string answer();
private:
	std::string Board[size];
};

#endif // !SUDOKU_H
