#ifndef SUDOKU_H
#define SUDOKU_H
#include <fstream>
#include <iostream>


class Sudoku
{
public:
	ReadMap(std::istream& in);

private:
	int m_nSize;
	int** m_pMap;
};

#endif
