#include "BinaryTree.h"

const int INTEGER_MIN = -9999;
const int INTEGER_MAX = 9999;

int max(int a, int b)
{
	if(a < b)
		return b;

	return a;
}


Node* Insert2(Node** pRoot, int nVal)
{
	if(pRoot == NULL)
		return NULL;

	if(*pRoot == NULL)
	{
		*pRoot = new Node();
		(*pRoot)->m_nVal = nVal;
		return *pRoot;
	}
	else
	{
		if(nVal <= (*pRoot)->m_nVal)
			(*pRoot)->m_pLeftChild = Insert2(&(*pRoot)->m_pLeftChild, nVal);
		else
			(*pRoot)->m_pRightChild = Insert2(&(*pRoot)->m_pRightChild, nVal);
	}

	return *pRoot;
}

void Insert(Node** pRoot, int nVal)
{
	if(pRoot == NULL)
		return;
	if(*pRoot == NULL)
	{
		*pRoot = new Node();
		(*pRoot)->m_nVal = nVal;

	}
	else
	{
		if(nVal <= (*pRoot)->m_nVal)
		{
			if((*pRoot)->m_pLeftChild == NULL)
			{
				Node* pnew = new Node();
				pnew->m_nVal = nVal;

				pnew->m_pParent = *pRoot;
				(*pRoot)->m_pLeftChild = pnew;	
			}
			else	
				Insert(&(*pRoot)->m_pLeftChild, nVal);

		}
		else
		{
			if((*pRoot)->m_pRightChild == NULL)
			{
				Node* pnew =  new Node();
				pnew->m_nVal = nVal;

				pnew->m_pParent = *pRoot;
				(*pRoot)->m_pRightChild = pnew;
			}
			else
				Insert(&(*pRoot)->m_pRightChild, nVal);
		}
	}
}

void TraverseInOrder(Node* pRoot)
{
	if(pRoot)
	{
		TraverseInOrder(pRoot->m_pLeftChild);
		printf("%d\n", pRoot->m_nVal);		
		TraverseInOrder(pRoot->m_pRightChild);
	}
}

void TraversePreOrder(Node* pRoot)
{
	if(pRoot)
	{
		printf("%d\n", pRoot->m_nVal);
		TraversePreOrder(pRoot->m_pLeftChild);
		TraversePreOrder(pRoot->m_pRightChild);
	}
}

void TraversePostOrder(Node* pRoot)
{
	if(pRoot)
	{
		TraversePostOrder(pRoot->m_pLeftChild);
		TraversePostOrder(pRoot->m_pRightChild);
		printf("%d\n", pRoot->m_nVal);
	}
}

int GetHeight(Node* pRoot)
{
	if(pRoot == NULL)
		return -1;

	int nLeftHeight = GetHeight(pRoot->m_pLeftChild);
	int nRightHeight = GetHeight(pRoot->m_pRightChild);

	int nMax = nLeftHeight < nRightHeight ? nRightHeight : nLeftHeight;

	int nLen = 1 + nMax;

	return nLen;
}

int CheckHeight(Node* pRoot)
{
	if(pRoot == NULL)
		return -1;

	int nHeightLeft = CheckHeight(pRoot->m_pLeftChild);
	if(nHeightLeft == INTEGER_MIN)
		return INTEGER_MIN;

	int nHeightRight = CheckHeight(pRoot->m_pRightChild);
	if(nHeightRight == INTEGER_MIN)
		return INTEGER_MIN;

	int heightDiff = nHeightRight - nHeightLeft;
	if(abs(heightDiff) > 1)
		return INTEGER_MIN;
	else
		return max(nHeightLeft, nHeightRight) + 1;
}


bool IsBalanced(Node* pRoot)
{
	if(CheckHeight(pRoot) != INTEGER_MIN)
	{
		printf("Is balanced \n");
		return true;

	}
	else
	{
		printf("Not balanced \n");
		return false;
	}
}

bool CheckIfBinarySearchTree(Node* pRoot, int min , int max, bool bRoot)
{

	if(pRoot == NULL)
		return true;

	if(pRoot->m_nVal > max || pRoot->m_nVal < min)
		return false;

	int bLeft = CheckIfBinarySearchTree(pRoot->m_pLeftChild, INTEGER_MIN, pRoot->m_nVal, false);
	
	if(!bLeft)
		return false;

	bool bRight = CheckIfBinarySearchTree(pRoot->m_pRightChild, pRoot->m_nVal, INTEGER_MAX, false);
	if(!bRight)
		return false;

	return true;
}


int IsLeftChild(Node* pParent, Node* pChild)
{
	if(!pParent || !pChild)
		return -1;

	int nChildVal = pChild->m_nVal;
	int nParentVal = pParent->m_nVal;

	if(nChildVal <= nParentVal)
		return 1;
	else
		return 0;
}

int GetSuccessor(Node* pNode)
{
	if(pNode->m_pRightChild)
	{
		printf("Successor %d \n", pNode->m_pRightChild->m_nVal);
		return pNode->m_pRightChild->m_nVal;
	}

	Node* pParent = pNode->m_pParent;
	Node* pCurrent = pNode;

	int nRet = IsLeftChild(pParent, pCurrent); 
	while( nRet == 0)
	{
		pCurrent = pParent;
		pParent = pParent->m_pParent;
		nRet = IsLeftChild(pParent, pCurrent); 
	}
	
	if(nRet == -1)
	{
		printf("Node has no successor\n");
		return -1;
	}
	else
	{
		printf("Successor %d \n", pParent->m_nVal);
	}
}

bool Covers(Node* pRoot, Node* pChild)
{
	if(pRoot == NULL)
		return false;

	if(pRoot == pChild)
		return true;

	return Covers(pRoot->m_pLeftChild, pChild) || Covers(pRoot->m_pRightChild, pChild);
}

/* this will not work if p or q is are not present in tree 
 * additional info (a flag when found ) must be passed to know when ancestor was reached
*/
Node* FindCommonAncestor(Node* pRoot, Node* p, Node* q)
{
	if(pRoot == NULL)
		return NULL;

	if(pRoot == p && pRoot == q)
		return pRoot;

	Node* x = FindCommonAncestor(pRoot->m_pLeftChild, p, q);
	
	// already found ancestor
	if(x != NULL && x != p && x != q)
		return x;

	Node* y = FindCommonAncestor(pRoot->m_pRightChild, p, q);
	if(y != NULL && y != p && y != q)
		return y;

	if(x != NULL && y != NULL)
		return pRoot;
	else if(pRoot == p || pRoot == q)
			return pRoot;
	else
	{
		if(x == NULL)
			return y;
		else return x;
	}
}

bool MatchSubTree(Node* pRoot, Node* pTree)
{
	/* reached end with search - no elements left*/
	if(pRoot == NULL && pTree == NULL)
		return true;
	else
	{
		if(pRoot == NULL )
			return false;

		if(pTree == NULL)
			return true;

		if(pRoot->m_nVal == pTree->m_nVal)
			return MatchSubTree(pRoot->m_pLeftChild, pTree->m_pLeftChild) && MatchSubTree(pRoot->m_pRightChild, pTree->m_pRightChild);

		return false;
	}	
}

bool IsSubTree(Node* pRoot, Node* pTree)
{
	if(pRoot == NULL)
		return false;
	if(pTree == NULL)
		return true;

	if(pRoot->m_nVal == pTree->m_nVal)
		return MatchSubTree(pRoot, pTree);

	return MatchSubTree(pRoot->m_pLeftChild, pTree) || MatchSubTree(pRoot->m_pRightChild, pTree);
}

int GetMinimumHeight(Node* pRoot, int& min)
{
	return 0;
}
#if 0
int main()
{
	Node *pRoot = NULL;

	Insert2(&pRoot, 7);
	Insert2(&pRoot, 10);
	Insert2(&pRoot, 8);
	Insert2(&pRoot, 11);
	Insert2(&pRoot, 5);
	Insert2(&pRoot, 6);
	Insert2(&pRoot, 3);

	TraverseInOrder(pRoot);

	Node* pTree = NULL;
	Insert(&pTree, 10);
	Insert(&pTree, 8);
	Insert(&pTree, 11);
	Insert(&pTree, 12);

	bool bIsSubTree = IsSubTree(pRoot, pTree);
	if(bIsSubTree)
		printf("Is subtree \n");
	else
		printf("Not substree \n");

/*
	// find common ancestor
	Node* pCommon = FindCommonAncestor(pRoot, pRoot->m_pLeftChild->m_pLeftChild, pRoot->m_pLeftChild->m_pRightChild);
	printf("Ancestor value = %d\n", pCommon->m_nVal);
*/
#if 0
	//pRoot->m_pLeftChild->m_pRightChild = pNew;

	bool bIsBST = CheckIfBinarySearchTree(pRoot, INTEGER_MIN, INTEGER_MAX, true);
	if(bIsBST)
		printf("Is binary saerch tree\n");
	else
		printf("Not a binary tree\n");

	GetSuccessor(pRoot->m_pLeftChild->m_pRightChild);
#endif 
}

#endif
