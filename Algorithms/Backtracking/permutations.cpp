#include <iostream>
#include "backtrackingTemplates.h"


/* posible canditates are the ones that haven't appeared so far in our solution vector*/
void ConstructCandidates(int*& a, int k, int n, int*&c, int& ncandidates)
{
	bool inPermutation[100] = { false };

	/*go through first k - 1 elements*/
	for(int i = 1; i < k; i++)
	{
		inPermutation[a[i]] = true;
	}
	ncandidates = 0;
	// go through all possible elements and select unused ones
	for(int i = 1; i <= n; i++)
	{
		if(inPermutation[i] == false)
		{
			c[ncandidates] = i;
			ncandidates++;	
		}

	}
}

void processSolution(int*& a, int k, int n)
{
	std::cout << "(";
	for(int i = 1; i <=  k; ++i)
	{
		if(i <  k)
			std::cout << a[i] << ", ";
		else
			std::cout << a[i] << ")\n";
	}
}

bool IsASolution(int*& a, int k, int n)
{
	return k == n;
}


void backtrack(int*& a, int k, int n)
{
	int* canditates = new int[100];
	int ncandidates = 0;

	if(IsASolution(a,k,n))
	{
		processSolution(a,k,n);
	}
	else
	{
		k = k + 1;
		ConstructCandidates(a, k, n, canditates, ncandidates);
		for(int i = 0; i < ncandidates; i++)
		{
			a[k] = canditates[i];
			backtrack(a, k, n);
		}
	}

}

int main()
{


    int n;
    int* v;
    int* a; // partial solution vector

    
    std::cout << "Size of vector = "; std::cin >> n;
    
  //  v = new int[n];
    a = new int[n + 1]();
    //std::cout << "Elements = "; 

    backtrack(a, 0 , n);

    delete[](a);
}