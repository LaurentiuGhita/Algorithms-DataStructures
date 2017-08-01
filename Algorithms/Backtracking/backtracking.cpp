#include "backtracking.h"

const int MAX_CANDIDATES = 100;


template <typename T>
void BacktrackProblem<T>::BacktrackAlgorithm(int*&a , int k, T input)
{
    int* c = new int[MAX_CANDIDATES];
    int nCandidates = 0;

    if(IsASolution(a, k, input))
    	ProcessSolution(a,k, input);
    else
    {
    	k = k + 1;
    	ConstructCanditates(a, k, input, c, nCandidates);
    	for(int i = 0; i < nCandidates; ++i)
    	{
    		a[k] = c[i];
    		BacktrackAlgorithm(a, k, input);
    	}
    }

    delete[](c);
}