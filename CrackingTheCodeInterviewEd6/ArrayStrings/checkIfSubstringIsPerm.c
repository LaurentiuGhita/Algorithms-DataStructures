#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool checkIfPermutation(char* a, char* b)
{
    if(a == NULL || b == NULL)
        return false;

    if(strlen(a) != strlen(b))
        return false;

    int charCountA[128] = {0};
    int charCountB[128] = {0};

    int i;
    for(i = 0; i < strlen(a); ++i)
    {
        charCountA[a[i]]++;
        charCountB[b[i]]++;
    }

    for(i = 0; i < 128; ++i)
    {
        if(charCountA[i] != charCountB[i])
            return false;
    }

    return true;
}

int main()
{
    char a[10];
    char b[10];

    printf("a = "); scanf("%s", a);
    printf("b = "); scanf("%s", b);
    bool perm = checkIfPermutation(a, b);

    perm == true ? printf("Permutation\n") : printf("Not a perm\n");
    return 0;
}
