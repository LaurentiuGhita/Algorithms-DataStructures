#include <iostream>
#include "backtrackingTemplates.h"

const int MAX_CANDIDATES = 100;

// are the first k element of a a complete solution ?
bool IsASolution(int*& a, int k, int n)
{
    return k == n;
}


// fill array c with the complete set of canditates for the k-th position of a 
// given the contents of the first k - 1 positions
void ConstructCandidates(int*& a, int k, int n, int*&c, int& ncandidates)
{
    c[0] = 1; // is in set
    c[1] = 0; // not in set
    ncandidates = 2; // posible candidates
}

/*
 * 
 */
void processSolution(int*& a, int k, int n)
{
    std::cout << "\n(";
    for(int i = 1; i <= k; ++i)
        if(a[i] == 1)
        {
        	if(i < k)
        		std::cout << i << ",";
        	else
            	std::cout << i;
        }
        else
        {
        	if(i < k)
        		std::cout << "_,";
        	else
        		std::cout << "_";
        }
    std::cout << ")\n";
}


void backtrack(int*&a, int k, int n)
{
    int* c = new int[MAX_CANDIDATES];
    int nCandidates = 0;

    if(IsASolution(a, k, n))
    	processSolution(a,k, n);
    else
    {
    	k = k + 1;
    	ConstructCandidates(a, k, n, c, nCandidates);
    	for(int i = 0; i < nCandidates; ++i)
    	{
    		a[k] = c[i];
    		backtrack(a, k, n);
    	}
    }

    delete[](c);
}

void printVector(int*&a, int nStart, int nEnd)
{
    for(int i = nStart; i <= nEnd; ++i)
    {
        std::cout << a[i] << " ";
    }
    std::cout << "\n";
}


int main()
{
    int n;
    int* v;
    int* a; // partial solution vector

    BacktrackProblem<int> subSetProblem;
    subSetProblem.SetIsASolutionRoutine(&IsASolution);
    subSetProblem.SetProcessSolutionRoutine(&processSolution);
    subSetProblem.SetConstructCanditatesRoutine(&ConstructCandidates);
    
    std::cout << "Size of vector = "; std::cin >> n;
    
    v = new int[n + 1];
    a = new int[n + 1];
    std::cout << "Elements = "; 
    for(int i = 1; i <= n; ++i)
    {
        std::cin >> v[i];
    }

    //subSetProblem.BacktrackAlgorithm(a, 0 , n);

	subSetProblem.Solve(a, 0 ,n );


    delete[](v);
    delete[](a);
}





