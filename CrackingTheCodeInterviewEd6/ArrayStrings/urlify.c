#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void replaceCharWithString(char* str, char toBeReplaced, char* newStr)
{
    int i;
    int count = 0;
    for(i = 0; i < strlen(str); ++i)
    {
        if(str[i] == toBeReplaced)
            ++count;
    }

    int newLen = strlen(str) + (strlen(newStr) - 1) * count; 
    if(sizeof(str) < newLen)
        str = realloc(str, newLen * sizeof(char));

    int currentIndex = newLen -1;
    for(i = strlen(str) - 1; i >= 0; --i)
    {
        if(str[i] == toBeReplaced)
        {
            int j;
            for(j = strlen(newStr) -1; j >= 0; j--)
            {
                str[currentIndex] = newStr[j];
                currentIndex--;
            }
        }
        else
        {
            str[currentIndex] = str[i];
            currentIndex--;
        }
    }
    printf("--> %s \n", str);
}

int main()
{
    char* str = malloc(5 * sizeof(char));
    scanf("%s", str);
    replaceCharWithString(str, 'a', "cu");
    free(str);
}
