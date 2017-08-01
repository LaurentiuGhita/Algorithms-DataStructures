// you can write to stdout for debugging purposes, e.g.
// printf("this is a debug message\n");

int myComp(const void* a, const void *b)
{
    return *(int*)a < *(int*)b;
}

int solution(int A[], int N) {
    // write your code in C99 (gcc 6.2.0)
    
    if(N == 0)
        return 0;
    
    if(N == 1)
        return 1;
    
    qsort(A, N, sizeof(int), myComp);
    int index = 1;
    int currentElement = A[0];
    int nDifferent = 1;
    
    while(index < N)
    {
        if(A[index] != currentElement)
        {
            currentElement = A[index];
            nDifferent++;
        }
        index++;
    }
    
    return nDifferent;
}