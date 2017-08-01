#include <iostream>
#include <string.h>

void reverse(char*& a)
{
    int nStart = 0;
    int nEnd = strlen(a)-1;
    while(nStart < nEnd)
    {
        char aux = a[nStart];
        a[nStart] = a[nEnd];
        a[nEnd] = aux;
        nStart++;
        nEnd--;
    }
}

int main()
{
    char* a;
    std::cin >> a;

    reverse(a);

    std::cout << a << "\n";
}
