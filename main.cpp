#include <iostream>
#include <string>
#include "sudoku.h"

using namespace std;

int main()
{
        try
        {
                Sudoku sudoku;
                std::string board[sudoku.size];

                std::cout << "Please add numbers from 1 to 9." << "\n\n";
                for (int i = 0; i < sudoku.size; i++)
                {
                        std::getline(std::cin, board[i]);
                }
                std::cout << "Thanks!All numbers have been added successfully." << "\n\n";

                sudoku.enterDigits(board);
                sudoku.solve();
                sudoku.print();
        }
        catch (const std::exception& ex)
        {
                std::cout << ex.what() << "\n";
        }
}
