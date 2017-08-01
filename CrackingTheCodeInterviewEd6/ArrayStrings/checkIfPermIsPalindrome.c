#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>


int getMaskIndex(char c, int size)
{
    return c / size;
}


bool checkIfPermIsPalindrome(char* str)
{
    int i;
    int masks[4] = {0};

    for(i = 0; i < strlen(str); ++i)
    {
        int maskIndex = getMaskIndex(str[i], sizeof(int) * 8);

        int aux = 1 << str[i] % 32;
        masks[maskIndex] ^= aux;
    }

    bool foundOdd = false;
    for(i = 0; i < 4; ++i)
        if(masks[i] != 0 ) // we found a mask that isn't 0 
        {
            if(foundOdd == false)
            {
                int aux = masks[i] - 1; // now all should be 1 to the right of current char 
                if((aux & masks[i]) == 0)
                {
                    foundOdd = true;
                }
                else
                    return false;
            }
            else
                return false;
            
        }

    return true;
}

int main()
{
    char* a = malloc(100 * sizeof(char));

    scanf("%s", a);

    bool perm = checkIfPermIsPalindrome(a);
    
    printf("%d\n", perm);
    free(a);
    return 0;
}

