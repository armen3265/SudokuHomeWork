#include "sudoku.h"

std::string Sudoku::answer()
{
  std::string answer;
  for(int i = 0; i < size; i++)
  {
    answer += Board[i];
  }
  return answer;
}

void Sudoku::enterDigits(std::string board[size])
{
	//add numbers, empty squares add "0"
	
	for (int i = 0; i < size; i++)
	{
		Board[i] = board[i];
	}
}

void Sudoku::solve()
{
	//check completely solved or not. If not, continue the cycle in while.
	bool finish = false;

	while (!finish)
	{
		int zeros = 0;
		bool hard = true;
		//if it finds at least one empty cell, the "finish" is changed to false
		finish = true;
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				if (Board[i][j] == '0')
				{
					zeros++;
					//found an empty cell, the cycle will continue
					finish = false;

					//check how many possible coincidences are in one cell
					int coincidences = 0;

					char selectedNumber;
					for (char number = '1'; number <= '9'; number++)
					{

						//is the number checked for the cell? If no non=false, go to the next number
						bool none = true;

						//check horizontally
						for (int k = 0; k < size; k++)
						{
							if (number == Board[i][k])
							{
								none = false;
								break;
							}
							else
							{
								continue;
							}
						}
						if (none)
						{
							//check vertical
							for (int k = 0; k < size; k++)
							{
								if (number == Board[k][j])
								{
									none = false;
									break;
								}
								else
								{
									continue;
								}
							}
						}
						if (none)
						{
							//Find in which 3x3 square the cell is located.
							int ii;
							int lengthI;

							int jj;
							int lengthJ;
							if (size - i > 6)
							{
								ii = 0;
								lengthI = 3;
							}
							else if (size - i > 3)
							{
								ii = 3;
								lengthI = 6;
							}
							else
							{
								ii = 6;
								lengthI = 9;
							}
							if (size - j > 6)
							{
								jj = 0;
								lengthJ = 3;
							}
							else if (size - j > 3)
							{
								jj = 3;
								lengthJ = 6;
							}
							else
							{
								jj = 6;
								lengthJ = 9;
							}

							//Looking for coincidence in the square.
							for (int l = ii; l < lengthI; l++)
							{

								for (int m = jj; m < lengthJ; m++)
								{
									if (number == Board[l][m])
									{
										none = false;
										break;
									}
									else
									{
										continue;
									}
								}
							}
						}

						//number is good to add
						if (none)
						{
							//the number matches
							coincidences++;
							selectedNumber = number;
							continue;
						}
						else
						{
							continue;
						}

						//if there is more than one match, go to the next cell
						//stops the cycle
						if (coincidences > 1)
							break;
					}

					//after the end of the cycle, if there is only one match, means add the number to the cell
					if (coincidences == 1)
					{
						hard = false;
						Board[i][j] = selectedNumber;
					}
				}
				else
				{
					continue;
				}
			}
		}
		if (hard && zeros!=0)
		{
			throw std::runtime_error("The task is difficult and impossible to solve");
		}
	}
}

void Sudoku::print()
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			std::cout << Board[i][j] << " ";
		}
		std::cout << std::endl;
	}
}
