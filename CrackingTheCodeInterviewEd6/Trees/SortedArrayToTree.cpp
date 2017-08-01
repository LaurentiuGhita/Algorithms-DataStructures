#include "BinaryTree.h"
#include <vector>

Node* CreateMinimalSubTree(std::vector<int> array, int start, int end)
{
	if(end < start)
		return NULL;

	int middle = (start + end) / 2;

	Node* pRoot = new Node();
	pRoot->m_nVal = array[middle];
	pRoot->m_pParent = NULL;

	if(start == end)
	{
		pRoot->m_pRightChild = NULL;	
		pRoot->m_pLeftChild = NULL;
		return pRoot;
	}

	pRoot->m_pLeftChild = CreateMinimalSubTree(array, start, middle - 1);
	pRoot->m_pRightChild = CreateMinimalSubTree(array, middle + 1, end);

	if(pRoot->m_pLeftChild)
		pRoot->m_pLeftChild->m_pParent = pRoot;

	if(pRoot->m_pRightChild)
		pRoot->m_pRightChild->m_pParent = pRoot;

	return pRoot;	
}


int main()
{
	std::vector<int> v1;
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	v1.push_back(4);
	v1.push_back(5);
	v1.push_back(6);
	v1.push_back(7);
	v1.push_back(8);
	v1.push_back(9);

	Node* pRoot = CreateMinimalSubTree(v1, 0, v1.size() - 1);
	TraverseInOrder(pRoot);
}