#include <iostream>
#include <cstring>


const char getOpenBracket(const char c)
{

	switch(c)
	{
		case '}':
			return '{';
		case ')':
			return '(';
		case ']':
			return '[';		
	};
}

bool isOpeningBracket(const char c)
{
	if(c == '(' || c == '{' || c == '[')
		return true;
	return false;
}

bool isClosingBracket(const char c)
{
	if(c == ')' || c == ']' || c == '}')
		return true;
	return false;
}


bool properlyNested(const char* input)
{
	if(input == nullptr)
	{
		std::cout << "Invalid input";
		return false;
	}


	bool bRet = true;
	int nLength = strlen(input);

	int currentStackPos = -1;
	char* myStack = new char[nLength/2 +1]();

	for(size_t i = 0; i < strlen(input); ++i)
	{
		if(isOpeningBracket(input[i]))
		{
			/* add it to stack */
			currentStackPos++;
			myStack[currentStackPos] = input[i];
		}
		else if(isClosingBracket(input[i]))
		{
			if(currentStackPos == -1)
			{
				bRet = false;
				break;
			}

			const char topStack = myStack[currentStackPos];
			if(topStack == getOpenBracket(input[i]) )
			{
				currentStackPos--;
			}
			else
			{
				std::cout << "Found closing bracket wihtout a previous open one for bracket " << input[i] << "\n";
				bRet = false;
				break;
			}
		}
	}

	if(currentStackPos != -1)
	{
		std::cout << "Still have oopening brackets wihtout closing ones \n";
		bRet = false;
	}

	delete []myStack;
	myStack = nullptr;
	return bRet;
}

int main()
{
	std::cout << "Please enter text to check :\n";
	std::string line;
	while(std::getline(std::cin, line))
	{
		if(line == "q" || line == "quit" ||  line.empty())
			break;
		bool bProperly = properlyNested(line.c_str());
		std::cout << "Expression properly nested: " << bProperly << "\n";
	}
}