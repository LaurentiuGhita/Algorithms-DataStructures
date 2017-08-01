/*

Task description
Write a function:

int solution(int A[], int N);

that, given a non-empty zero-indexed array A of N integers, returns the minimal positive integer (greater than 0) that does not occur in A.

For example, given:

  A[0] = 1
  A[1] = 3
  A[2] = 6
  A[3] = 4
  A[4] = 1
  A[5] = 2
the function should return 5.

Assume that:

N is an integer within the range [1..100,000];
each element of array A is an integer within the range [−2,147,483,648..2,147,483,647].
Complexity:

expected worst-case time complexity is O(N);
expected worst-case space complexity is O(N), beyond input storage (not counting the storage required for input arguments).
Elements of input arrays can be modified.


*/

// you can write to stdout for debugging purposes, e.g.
// printf("this is a debug message\n");


void mySwap(int* a, int *b)
{
    *a ^= *b;
    *b ^= *a;
    *a ^= *b;
}

int segregate(int* a, int N)
{
    int i;
    int j = 0;
    for(i = 0; i < N; i++)
    {
        if(a[i] < 0)
        {
            if(i != j)
                mySwap(&a[i], &a[j]);
            ++j;
        }
    }
    
    return j;
}

void printVector(int* a, int N)
{
    int i;
    for(i = 0; i < N; ++i)
    {
        printf("%d ", a[i]);
    }
    
    printf("\n");
}

int solution(int A[], int N) {
    // write your code in C99 (gcc 6.2.0)
    
    
    int nIndex = segregate(A, N);
    //printVector(A,N);
    int i;
    int found[N - nIndex + 1];
    for(i = 0; i <= N -nIndex; ++i)
    {
        found[i] = 1;
    }
    
    int newUpper = N - nIndex;
    
    for(i = nIndex; i < N; ++i)
    {
        if(A[i] <= newUpper)
        {
            found[A[i]] = -A[i];
        }
    }
    
    for(i = 1; i <= newUpper; ++i)
    {
        if(found[i] > 0)
            return i;
    }
    
    return newUpper+1;
}