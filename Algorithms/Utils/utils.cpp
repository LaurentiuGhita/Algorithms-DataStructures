#include "utils.h"

void printVector(std::vector<int> input)
{
	for(int i = 0; i < input.size(); i++)
		std::cout << input[i] << " ";

	std::cout << std::endl;
}

void mySwap(int& a, int& b)
{
	a ^= b;
	b ^= a;
	a ^= b;
}