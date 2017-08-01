#include <stdio.h>
#include <string.h>
#include <stdlib.h>


// map all 127 ascii characters into 4 intervals 
int getCharInteger(char c)
{
    if(c < 123 / 4)
        return 0;
    if(c < 127 / 2)
        return 1;
    if(c < 127 * 3 / 4)
        return 2;
    if(c < 127)
        return 3;
}

// with mask 
void removeDuplicates2(char* str)
{
	int mask[4] = {0};

	int i = 0;
	int tail = 0;
	for(i = 0; i < strlen(str); ++i)
	{
		int maskId = getCharInteger(str[i]);

		int aux = 1 << (str[i] % 32);

		if((mask[maskId] & aux) != aux)
		{
			mask[maskId] |= aux;
			str[tail] = str[i];
			tail++;
		}
	}

	str[tail] = '\0';
}

// with bool vector
void removeDuplicates(char* str)
{
	if(strlen(str) > 1)
	{
		int bHit[128];
		int i = 0;
		for(i = 0; i < 128; ++i)
		{
			bHit[i] = false;
		}

		bHit[str[0]] = true;

		int n = strlen(str);
		int tail = 1;
		for(i = 1; i < n; ++i)
		{
			// char not found
			if( bHit[ str[i] ] != 1)
			{
				str[tail] = str[i];
				++tail;
				bHit[ str[i] ] = 1;
			}
		}
		str[tail] = '\0';	
	}
}

int main()
{
	char str[100];
	printf("String = "); 
	scanf("%s", str);
	removeDuplicates2(str);

	printf("String without duplicates = %s\n", str);
}