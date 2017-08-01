#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* longestSubPalindrome(char**a)
{
	char* str = *a;

	if(str == NULL)
		return NULL;

	int nStringLen = strlen(str);
	int i;
	int leftIndex = 0;
	int righIndex = nStringLen - 1;

	char* maxPalindrome = (char*) malloc(100 * sizeof(char));
	int nMaxSize = 0;

	for(i = 0; i < nStringLen; ++i)
	{
		leftIndex = i;
		righIndex = nStringLen - 1;

		while(leftIndex <)


		while(str[leftIndex] != str[righIndex])
		{
			righIndex--;
		}

		if(leftIndex == righIndex)
		{
			if(nMaxSize < 1)
			{
				strncpy(maxPalindrome, str + i, 1);
				nMaxSize = 1;
			}
		}
		else
		{
			while(leftIndex < righIndex)
			{
				if(str[leftIndex] == str[righIndex])
				{
					leftIndex++;
					righIndex--;
				}
				else
				{
					break;
				}
			}
			if(leftIndex == righIndex || leftIndex == righIndex + 1)
			{

			}
			else
			{

			}
		}


	}
}

char* longestPalindromeSubstring(char** a)
{
	char* str = *a;
	if(str == NULL)
		return NULL;

	int i;
	int nLen = strlen(str);
	int leftIndex;
	int righIndex;

	char* maxSubString = NULL;
	int nMaxSize = 0;

	for(i = 0; i < nLen; ++i)
	{
		leftIndex = i;
		righIndex = nLen - 1;
		char* currentPalindromeSubstr = NULL;
		int size = 0;
		while(str[leftIndex] != str[righIndex])
		{
			righIndex--;
		}

		if(leftIndex == righIndex)
		{
			currentPalindromeSubstr = str[leftIndex];
			size = 1;
			if(strlen(currentPalindromeSubstr) > nMaxSize )
			{
				maxSubString = currentPalindromeSubstr;
				nMaxSize = 1;
			}
		}

		int nEnd = righIndex;
		while(str[leftIndex] == str[righIndex])
		{
			leftIndex++;
			righIndex--;
			size++;
		}

		// we found a palindrome starting from i to nEnd 
		if(leftIndex == righIndex - 1 || leftIndex == righIndex)
		{
			int currentSize = nEnd - i;
			if(currentSize > nMaxSize)
			{
				strncpy(maxSubString, str + i, currentSize);
			}

		}

	}

}

int main()
{
	char* inputString = (char*)malloc(100 * sizeof(char));
	scanf("%s", inputString);
	//longestPalindromeSubstring(&inputString);

}