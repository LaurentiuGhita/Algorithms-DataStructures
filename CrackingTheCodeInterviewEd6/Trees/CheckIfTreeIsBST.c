#include "BinaryTree.h"

const int MIN = -9999;
const int MAX = 9999;


bool CheckIfTreeIsBST(Node* pRoot, int nMin, int nMax)
{
	if(pRoot == NULL)
		return true;

	if(pRoot->m_nVal < nMin || pRoot->m_nVal > nMax)
		return false;


	if(CheckIfTreeIsBST(pRoot->m_pLeftChild, MIN, pRoot->m_nVal) == false)
		return false;

	if(CheckIfTreeIsBST(pRoot->m_pRightChild, pRoot->m_nVal + 1, MAX) == false)
		return false;

	return true;
}