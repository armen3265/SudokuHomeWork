#include <iostream>
#include "sudoku.h"

int main()
{
	Sudoku sudoku;

	sudoku.enterDigits();
	sudoku.solve();
	sudoku.print();
}
