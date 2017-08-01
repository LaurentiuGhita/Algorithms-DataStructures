// number of elements divisible with K in [A, B]


int solution(int A, int B, int K) {
    // write your code in C99 (gcc 6.2.0)
    
    long long lowerLimit = A;
    long long upperLimit = B;
    
    /* find next number divisible with k*/
    if(A % K != 0)
        lowerLimit = A - A % K + K;
    
    if(B % K != 0)
        upperLimit = B - B % K;
        
    if(lowerLimit > upperLimit)
        return 0;
        
    if(lowerLimit == upperLimit)
        return 1;
        
    return (upperLimit - lowerLimit) / K + 1;
}