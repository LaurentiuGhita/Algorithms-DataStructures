#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char* replaceCharWithStr(char* source, char c, char* replaceWith)
{
	int nLength = strlen(source);
	int replaceLength = strlen(replaceWith);

	// assume all chars will be replaces with new str --> 
	int newSize = nLength * replaceLength;
	char* newStr = malloc(sizeof(char) * newSize);

	int newStrIndex = 0;
	int i = 0;

	for(i = 0; i < nLength; ++i)
	{
		if(source[i] == c)
		{
			int j;
			for(j = 0; j < replaceLength; ++j)
			{
				newStr[newStrIndex] = replaceWith[j];
				newStrIndex++;
			}
		}
		else
		{
			newStr[newStrIndex] = source[i];
			newStrIndex++;
		}
	}

	newStr[newStrIndex] = '\0';
	return newStr;
}


int main()
{
	char str[100];
	char newStr[100];
	char c;
	printf("Enter string: "); scanf("%s", str);
	printf("Enter char to replace: "); scanf("%s", &c);
	printf("Enter string to replace with: "); scanf("%s", newStr);

	char* result = replaceCharWithStr(str, c, newStr);

	printf("String after replace = %s\n", result);

	free(result);
}
