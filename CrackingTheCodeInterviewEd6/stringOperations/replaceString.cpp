#include <iostream>
#include <string.h>

char* replaceCharWith(char*& str, char toReplace,  char* with)
{
	char* result = str;
	int lenWith = strlen(with);
	int len = strlen(str);
	int matchCount = 0;

	for(int i = 0; i < len; ++i)
	{
		if(str[i] == toReplace)
			++matchCount;
	}

	if(matchCount == 0)
		return result;


	int newLen = len + lenWith * matchCount;
	result = new char[newLen];
	int resultIndex = 0;

	for(int i = 0; i < len; ++i)
	{
		if(str[i] != toReplace)
			result[resultIndex++] = str[i];
		else
		{
			for(int j = 0; j < strlen(with); ++j)
			{
				result[resultIndex++] =	with[j];
			}
			 
		}
	}

	return result;
}

int main()
{
	char* a = new char[100];
	std::cin >> a;

	char r;
	std::cout << "replace char "; std::cin >> r;

	char* w = new char[10];
	std::cout << "with "; std::cin >> w;

	std::cout << replaceCharWith(a, r, w) << "\n";

}