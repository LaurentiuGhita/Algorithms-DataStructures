#include <stdio.h>
#include <stdlib.h>
/*
 * M nodes
   M - 1 edges
   A[i] = x --> undirected edge from i to x
   A[i] = i --> i is capital
   Find distance vector from capital
 */

int getDistance(int A[], int D[], int S[], int index,int capital)
{
    if(A[index] == capital)
    {
        D[index] = 1;
        S[1]++;
        return 1;
    }
    else
    {
       if(D[A[index]] == 0)
            D[index] = 1 + getDistance(A, D, S, A[index], capital);
       else
            D[index] = 1 + D[A[index]];
       
       S[D[index]]++;
       return D[index];
    }
}


int* solution(int A[], int M)
{
    

    int i = 0;
    int capital = -1;
    int distanceVector[M];
    
    
    int* sol = malloc(100 * sizeof(int));
    for(i = 0; i < M; i++)
    {
        sol[i] = 0;
        distanceVector[i] = 0;
    }
    
    // find capital
    for(i = 0; i < M; i++)
    {
        if(A[i] == i)
            capital = i;
    }

    for(i = 0; i < M; i++)
    {
        if(i != capital)
        {
            if(distanceVector[i] == 0)
            {
                getDistance(A, distanceVector, sol, i, capital);
            }
        }
    }

    return sol;
}

int main()
{
    int A[10];
    int i = 0;
    for(i = 0; i < 10; ++i)
        scanf("%d", &A[i]);
    int* S = solution(A, 10);
    for(i = 0; i < 10; ++i)
        printf("%d ", S[i]);
    printf("\n");
}
