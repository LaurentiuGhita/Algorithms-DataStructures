#include <stdio.h>



/*
 N = 1 0 0 1 0 0 0 
 M = 1 0 1
 i = 2
 j = 4
*/
void Insertion(int N, int M, int i, int j)
{
	int nAllOnes = ~0;

	int nFirstJZeros = (nAllOnes << ( j + 1)); // first j + 1 equal to 0 -->  1 1 1 1 1 1  0 0 0 0 0
	int nRight =  ((1 << i) - 1); // last i equal to 1 --> 0 0 0 0 1 1  

	int mask = nFirstJZeros | nRight; // 1 0 0 0 0 0 0 

	int toAdd = (M << (i + 1)); //--> 1 0 1 0 0 0

	int aux = N;
	aux &= mask; //--> aux = 1 0 0 0 0 0 0 
	aux |= toAdd; // --> aux = 1 0 1 0 1 0 0

	printf("Insertion = %d\n", aux);
}


int main()
{

	Insertion(15, 0, 1, 2);
}