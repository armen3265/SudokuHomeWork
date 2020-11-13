#include "Sudoku.h"
#include <iostream>

void Sudoku::enterDigits()
{
		std::cout << "Please add numbers from 1 to 9." << std::endl;
			for (int i = 0; i < size; i++)
					{
								for (int j = 0; j < size; j++)
											{
															int number;
																		std::cin >> number;
																					if (number>0 && number<9)
																									{
																														Board[i][j] = number;
																																	}
																							}
									}
				std::cout << "Thanks!All numbers have been added successfully." << std::endl;
}

void Sudoku::solve()
{
		for(int i = 0; i < size; i++)
				{
							
							for (int j = 0; j < size; j++)
										{
														if (Board[i][j] == -1)
																		{
																							for (int number = 1; number <= size; number++)
																												{
																																		bool none = true;
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
																																																														int ii;
																																																																				int lengthI;
																																																																										int lengthJ;
																																																																																int jj;
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
																																																																																																																								lengthI =9;
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
																																																																																																																										for (int l = ii; l < lengthI ; l++)
																																																																																																																																	{
																																																																																																																																									
																																																																																																																																									for (int m = jj;m<lengthJ;m++)
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

																																																						if (none)
																																																												{
																																																																			Board[i][j] = number;
																																																																									break;
																																																																														}
																																																											else
																																																																	{
																																																																								continue;
																																																																													}
																																																															}
																										}
																	else
																					{
																										continue;
																													}
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

Sudoku::Sudoku()
{
		for (int i = 0; i < size; i++)
				{
							for (int j = 0; j < size; j++)
										{
														Board[i][j] = -1;
																}
								}
}

Sudoku::~Sudoku()
{
}

