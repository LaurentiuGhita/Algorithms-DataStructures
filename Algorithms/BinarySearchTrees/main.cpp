#include "BinarySearchTree.h"

int main()
{
	BinarySearchTree binaryTree;
	binaryTree.AddElement(50);
	binaryTree.AddElement(49);
	binaryTree.AddElement(20);
	binaryTree.AddElement(6);
	binaryTree.AddElement(25);
	binaryTree.AddElement(21);
	binaryTree.AddElement(27);
	binaryTree.AddElement(26);
	binaryTree.AddElement(59);
#if 0
	binaryTree.AddElement(3);
	binaryTree.AddElement(1);
	binaryTree.AddElement(4);
	binaryTree.AddElement(5);
	binaryTree.AddElement(6);

	binaryTree.AddElement(12);
	binaryTree.AddElement(11);
	binaryTree.AddElement(8);
	binaryTree.AddElement(10);
	binaryTree.AddElement(17);
	binaryTree.AddElement(15);
	binaryTree.AddElement(20);
	std::cout << binaryTree.SearchElement(5) << "\n";
	std::cout << binaryTree.SearchElement(2) << "\n";
	std::cout << binaryTree.SearchElement(10) << "\n";
#endif
	//std::cout << binaryTree.GetMaximum() << " " << binaryTree.GetMinimum() << "\n";
	std::cout << binaryTree.GetSuccessor(27);
}