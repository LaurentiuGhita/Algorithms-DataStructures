#include "AVLTree.h"
#include <string>
#include <sstream>



int main()
{
	AVLTree<int> avlTree;

	std::string line;
	while(std::getline(std::cin, line))
	{
		std::stringstream ss;
		ss << line;
		std::string part1;

		ss >> part1;

		if(part1 == "add" || part1 == "Add" || part1 == "a")
		{
			int number;
			ss >> number;
			avlTree.AddNode(number);
		}
		else if(part1 == "remove" || part1 == "delete" || part1 == "d" || part1 == "r")
		{
			int number;
			ss >> number;
			avlTree.RemoveNode(number);
		}
		else if(part1 == "print" || part1 == "p")
		{
			avlTree.PrintPreOrder();
		}
		else if(part1 == "q" || part1 == "quit")
		{
			return 0;
		}
		else
		{
			std::cout << "Invalid command \n";
		}

		std::cout << "-----------------------------------------------\n";
	}

	return 0;
}