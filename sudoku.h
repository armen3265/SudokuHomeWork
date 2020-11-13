#pragma once


class Sudoku
{
	public:
			void enterDigits();
				void solve();
					void print();
						Sudoku();
							~Sudoku();
	private:
								const int size = 9;
									int Board[9][9];
};
