#include <iostream>
#include <stdio.h>
#include <string.h>

bool CheckUnique(char*& a, int nSize)
{
    bool bIsUnique = true;
    int checker = 0;
    for(int i = 0; i < nSize; ++i)
    {
        int aux = 1 << a[i];
        if((checker & (1 << a[i])) != 0 )
        {
            bIsUnique = false;
            break;
        }
        checker |= 1 << a[i];
    }
    bIsUnique == true ? std::cout << "Sting has unique characters\n" : std::cout << "String doesn't have unique char\n";
}

int main()
{
    char* a;
    std::cin >> a;
    std::cout << CheckUnique(a, strlen(a)) << "\n";
}
