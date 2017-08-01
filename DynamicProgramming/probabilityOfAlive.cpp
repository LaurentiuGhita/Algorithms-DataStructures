#include <iostream>
#include <sstream>
#include <map>



double GetProbabilityOfAlive(int x, int y, int step, int nMaxRow, int nMaxCol)
{
	static std::map<std::string, double> results;

	if(step == 0)
		return 1;

	std::stringstream ss;
	ss << x << "+" << y;
	std::string key = ss.str();

	if(results.find(key) != results.end())
	{
		return results[key];
	}


	double probability = 0.0;

	if(x -1 >= 0)
		probability += (0.25 * GetProbabilityOfAlive(x-1, y, step -1, nMaxRow, nMaxCol));

	if(x  + 1 < nMaxRow)
		probability += (0.25 * GetProbabilityOfAlive(x + 1, y, step -1, nMaxRow, nMaxCol));

	if(y - 1 >= 0)
		probability += (0.25 * GetProbabilityOfAlive(x, y - 1, step -1, nMaxRow, nMaxCol));

	if(y + 1 < nMaxCol)
		probability += (0.25 * GetProbabilityOfAlive(x, y + 1, step -1, nMaxRow, nMaxCol));

	results[key] = probability;
	return probability;

}


int main()
{
	//std::cout << GetProbabilityOfAlive(1,1, 1, 3,3) << "\n";
	//std::cout << GetProbabilityOfAlive(1,1, 2, 3,3) << "\n";
	std::cout << GetProbabilityOfAlive(1,1, 2 ,3,3) << "\n";
}


