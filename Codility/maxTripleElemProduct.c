// you can write to stdout for debugging purposes, e.g.
// printf("this is a debug message\n");

int myComp(const void* a, const void* b)
{
    if(*(int*)a < *(int*)b)
        return -1;
    
    if(*(int*)a == *(int*)b)
        return 0;
    
    return 1;
}

int getMax(int a, int b)
{
    if(a > b)
        return a;
        
    return b;
}


int solution(int A[], int N) {
    // write your code in C99 (gcc 6.2.0)

    qsort(A, N, sizeof(int), myComp);

    
    int prod =  A[N-3] * A[N-2] * A[N-1];
    int prod2 = A[0] * A[1] * A[N-1];
    
    return getMax(prod, prod2);
        
    
    
    return 0;
}