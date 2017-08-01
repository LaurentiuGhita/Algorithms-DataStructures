#include <iostream>
#include <vector>
#include <stdlib.h>
#include <sstream>


const int MAX_MIN = -999999;
const std::string NOT_MSG = "Not jolly\n";
const std::string OK_MSG = "Jolly\n";

const std::string checkIfJolly(std::vector<int>& input, const int& max)
{
	int nSize = input.size();
	int *a = new int[max]();


	for(int i = 1; i < nSize; ++i)
	{
		int absVal = abs(input[i] - input[i-1]) -1; 
		if(absVal == -1)
			return NOT_MSG;
		if( absVal >= nSize -1)
		{
			delete []a;
			return NOT_MSG;
		}
		else
		{
			if(a[absVal] != 0)
			{
				delete []a;
				return NOT_MSG;
			}

			a[absVal] = 1;
		}
	}
	delete []a;
	return OK_MSG;

}

void SolveProblem(std::istream& in)
{
	std::string line;
	std::vector<int> input;
	while(std::getline(in, line))
	{
		std::stringstream ss;
		ss << line;
		int aux;
		int max = MAX_MIN;

		while(ss >> aux)
		{
			input.push_back(aux);
			if(max < aux)
				max = aux;
			if(ss.fail())
			{
				break;
			}
		}

		std::cout << checkIfJolly(input, max);
		input.clear();
		if(line.empty())
			break;
	}
}


int main()
{
	SolveProblem(std::cin);
}
