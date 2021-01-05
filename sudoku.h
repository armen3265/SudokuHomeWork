#pragma once
#ifndef SUDOKU_H
#define SUDOKU_H

#include <iostream>
#include <string>
#include <array>

class Sudoku
{
public:
	static const int size = 9;
	void enterDigits(const std::array<std::string, size> &board);
	void solve();
	void print();
  std::string answer();
private:
	std::array<std::string, size> Board;
};

#endif // !SUDOKU_H
