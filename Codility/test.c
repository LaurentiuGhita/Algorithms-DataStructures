#include <stdio.h>
#include <stdlib.h>

int main()
{

    int *a = malloc( 3 * sizeof(int));
    int *b = malloc( 3 * sizeof(int));

    b[0] = 0;
    b[1] = 1;
    b[2] = 2;

    *a = *b++;
    a[1] = *b;
    printf("%d\n", a[0]);
    printf("%d\n", a[1]);
}
