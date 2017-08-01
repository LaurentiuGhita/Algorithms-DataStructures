#include <stdio.h>
#include <string.h>
#include <iostream>

void removeDuplicates(char*& a)
{
    if(a == NULL)
    {
        return;
    }

    int len = strlen(a);
    if(len < 2)
        return;

    int tail = 1;

    for(int i = 1; i < len; ++i)
    {
        int j;
        for(j = 0; j < tail; ++j)
        {
            if(a[i] == a[j])
                break;
        }
        if(j == tail)
        {
            a[tail] = a[i];
            ++tail;
        }
    }
    a[tail] = '\0';
}

void remDuplicates(char*& str)
{
	if(str == NULL)
		return;

	int len = strlen(str);
	if(len < 2)
		return;
	bool *hit = new bool[256];
	for(int i = 0; i < 256; i++)
		hit[i] = false;

	hit[str[0]] = true;
	int tail = 1;
	for(int i = 1; i < len; i++)
		if(hit[str[i]] == false)
		{
			str[tail] = str[i];
			++tail;
			hit[str[i]] = true;
		}

	str[tail] = '\0';
}

void myRemoveDuplicates(char*& str)
{
	int aux = 0;
	int tail = 1;

	int len = strlen(str);
	aux = (1 << str[0]);

	for(int i = 1; i < len; ++i)
	{
		// no duplicate
		if( (aux & ( 1 << str[i]))  == 0)
		{
			str[tail] = str[i];
			tail++;
			aux |= 1 << str[i]; 
		}
	}
	str[tail] = '\0';
}

int main()
{
    char* a = new char[100];
    std::cin >> a;
    myRemoveDuplicates(a);

    std::cout << a << "\n";
}
