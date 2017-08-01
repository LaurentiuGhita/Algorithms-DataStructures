#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int checkIfRotation(char* s1, char* s2)
{
	if(strlen(s1) != strlen(s2))
		return 0;

	// concat s1 with s1 and search if s2 is substring
	char *concat = malloc(strlen(s1) * 2 * sizeof(char));
	strncpy(concat, s1, strlen(s1));
	strncat(concat, s1, strlen(s1));

	if(strstr(concat,s2) != NULL)
		return 1;

	return 0;
}


int main()
{
	char str1[100];
	char str2[100];
	printf("Enter string1: "); scanf("%s", str1);
	printf("Enter string2: "); scanf("%s", str2);

	int nResult = checkIfRotation(str1, str2);
	if(nResult != 0)
		printf("String is rotation\n");
	else
		printf("String is not rotation\n");
	return 0;
}