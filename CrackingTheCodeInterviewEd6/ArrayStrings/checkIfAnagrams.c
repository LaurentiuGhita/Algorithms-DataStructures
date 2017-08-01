#include <stdio.h>
#include <string.h>

// ---> O(n)
int checkIfAnagram(char* str1, char* str2)
{
	int charCount[128] = {0};

	if(strlen(str1) != strlen(str2))
		return 0;


	int i;
	// vector of unique character count
	for(i = 0; i < strlen(str1); ++i)
	{
		charCount[str1[i]]++; // increase count from first string
		charCount[str2[i]]--; // decrease count from 2nd string
	}

	// if anagram we should have 0 count for each char
	for(i = 0; i < 128; ++i)
		if(charCount[i] != 0)
			return 0;

	return 1;
}

// alternative solution is to sort strings and compare --> O(nlogn)

int main()
{
	char s1[100];
	char s2[100];

	printf("String 1 = "); scanf("%s", s1);
	printf("String 2 = "); scanf("%s", s2);

	int result = checkIfAnagram(s1, s2);
	if(result == 0)
		printf("Strings are not anagrams \n");
	else
		printf("Strings are anagrams \n");

	return 0;
}