#include <stdlib.h>
#include <stdio.h>
#include <string.h>


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

int hasUnique(char* str)
{
    if(str == NULL)
        return 0;

    /*127 characters --> 4 integers --> 4 masks */
    int mask[4] = {0};
    int i;

    for(i = 0; i < strlen(str); ++i)
    {
        int maskIndex = getCharInteger(str[i]);

        int aux = 1 << ( str[i] % 32);

        if((mask[maskIndex] & aux) == aux)
            return 0;

        mask[maskIndex] |= aux;
    }
    return 1;
}

int main()
{
    char str[10];
    scanf("%s", str);
    printf("%d\n", hasUnique(str));
}
