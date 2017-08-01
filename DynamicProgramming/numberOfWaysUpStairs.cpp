/*
	n stairs - can jump 1, 2 , 3 stairs
	how many ways can he jump
*/

#include <iostream>
#include <map>
#include <unordered_map>


// ne eficienta 3 ^ n
long long normalNumberOfWays(int n)
{
	if(n < 0)
		return 0;
	if(n == 0)
		return 1;

	return normalNumberOfWays(n-1) + normalNumberOfWays(n-2) + normalNumberOfWays(n-3);
}


// top down --> stack overflow
void numberOfWays(int n, std::unordered_map<int,long long>& partialResults)
{
	if(n >= 0)
	{

		if(n == 0)
		{
			partialResults[n] = 1;
		}
		else
		{

			int currentSolution = 0;

			for(int i = 1; i <= 3; ++i)
			{
				if(n - i >= 0)
				{
					if(partialResults.find(n-i) != partialResults.end())
						currentSolution += partialResults[n -i];
					else
					{
						numberOfWays(n-i, partialResults);
						currentSolution += partialResults[n-i];
					}	
				}
			}

			partialResults[n] = currentSolution;	
		}
	}
}

// with map
void bottomUp(int n)
{
	std::unordered_map<int,long long> result;

	result[0] = 1; // new element inserted
	
	for(int i = 1; i <= n; ++i)
	{
		long long currentStepSolution = 0;
		if(i - 1 >= 0)
			currentStepSolution += result[i-1];
		if(i -2 >= 0)
			currentStepSolution += result[i-2];
		if(i -3 >= 0)
			currentStepSolution += result[i-3];
		result[i] = currentStepSolution;
	}
	std::cout << "numer of ways to climb = " << result[n] << "\n";

}

// best solution
void bottomUpWithoutMap(int n)
{
	int n1 = 1; // n - 1
	int n2 = 0; // n - 2
	int n3 = 0; // n - 3
	long long currentStepSolution = 0;

	for(int i = 1; i <= n; ++i)
	{
		currentStepSolution = 0;
		if(i - 1 >= 0)
			currentStepSolution += n1;
		if(i -2 >= 0)
			currentStepSolution += n2;
		if(i -3 >= 0)
			currentStepSolution += n3;

		n1 = n2;
		n2 = n3;
		n3 = currentStepSolution;
	}
	std::cout << "numer of ways to climb = " << currentStepSolution << "\n";

}

int main()
{
	int nNumStairs = 0;
	std::unordered_map<int,long long> result;
	std::cout << "num stairs = "; std::cin >> nNumStairs;
	//numberOfWays(nNumStairs, result);
	//std::cout << "numer of ways to climb = " << normalNumberOfWays(nNumStairs) << "\n";
	//std::cout << "numer of ways to climb = " << result[nNumStairs] << "\n";
	bottomUp(nNumStairs);
}