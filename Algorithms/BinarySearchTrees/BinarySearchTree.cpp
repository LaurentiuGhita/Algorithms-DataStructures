#include "BinarySearchTree.h"

const int MIN = -9999;

TreeNode::TreeNode(int nVal, TreeNode* pParent) : m_nVal(nVal) 
{ 
	m_pRightChild = m_pLeftChild = NULL; 
	m_pParent = pParent;
}

BinarySearchTree::~BinarySearchTree()
{
	FreeTree(m_pRoot);
}

void BinarySearchTree::AddElement(int nVal)
{
	return AddElementHelper(nVal, m_pRoot);
}

bool BinarySearchTree::SearchElement(int nVal)
{
	if(NULL != SearchElementHelper(nVal, const_cast<const TreeNode*&>(m_pRoot)))
		return true;
	return false;
}

bool BinarySearchTree::DeleteElement(int nVal)
{
	DeleteElementHelper(nVal, m_pRoot);
}


void BinarySearchTree::PrintBinaryTree()
{
	PrintTree(m_pRoot);
}

void BinarySearchTree::AddElementHelper(int nVal, TreeNode*& pRoot)
{
	if(pRoot == NULL)
	{
		pRoot = new TreeNode(nVal, NULL);
	}
	else
	{
		if(nVal < pRoot->m_nVal) 
		{
			if(pRoot->m_pLeftChild == NULL)
				pRoot->m_pLeftChild = new TreeNode(nVal, pRoot);
			else
				AddElementHelper(nVal, pRoot->m_pLeftChild);			
		}
		if(nVal >= pRoot->m_nVal) 
		{
			if(pRoot->m_pRightChild == NULL)
				pRoot->m_pRightChild = new TreeNode(nVal, pRoot);
			else
				AddElementHelper(nVal, pRoot->m_pRightChild);
		}
	}
}

TreeNode* BinarySearchTree::SearchElementHelper(int nVal, const TreeNode*& pRoot)
{
	if(pRoot == NULL)
		return NULL;

	if(pRoot->m_nVal == nVal)
		return const_cast<TreeNode*> (pRoot);

	if(nVal < pRoot->m_nVal)
		return SearchElementHelper(nVal, const_cast<const TreeNode*&>(pRoot->m_pLeftChild));
	else
		return SearchElementHelper(nVal, const_cast<const TreeNode*&>(pRoot->m_pRightChild));
}

bool BinarySearchTree::DeleteElementHelper(int nVal, TreeNode*& pRoot)
{
	TreeNode* nodeToReplace = SearchElementHelper(nVal, const_cast<const TreeNode*&>(pRoot));

	if(nodeToReplace == NULL)
	{
		std::cout << "Node " << nVal << " not found \n";
		return false;
	}

	/*predecessor*/
	TreeNode* pMaxFromLeft = GetMaxFromLeftTree(nodeToReplace->m_pLeftChild);
	
	/* we could also find the successor */

	/* node to delete doesn't have a left child*/
	if(pMaxFromLeft == NULL)
	{
		TreeNode* pRightChild = nodeToReplace->m_pRightChild;
		TreeNode* pNodeToReplaceParent = nodeToReplace->m_pParent;
		if(pRightChild)
		{
			pRightChild->m_pParent = nodeToReplace->m_pParent;
			if(pNodeToReplaceParent)
			{
				if(pRightChild->m_nVal < pNodeToReplaceParent->m_nVal)
					pNodeToReplaceParent->m_pLeftChild = pRightChild;
				else
					pNodeToReplaceParent->m_pRightChild = pRightChild;
			}
		}
		else
		{
			if(nodeToReplace->m_nVal < pNodeToReplaceParent->m_nVal)
				pNodeToReplaceParent->m_pLeftChild = NULL;
			else
				pNodeToReplaceParent->m_pRightChild = NULL;
		}
		delete nodeToReplace;
	}
	else
	{
		if(pMaxFromLeft->m_nVal < pMaxFromLeft->m_pParent->m_nVal)
			pMaxFromLeft->m_pParent->m_pLeftChild = pMaxFromLeft->m_pLeftChild;

		if(pMaxFromLeft->m_pLeftChild)
			pMaxFromLeft->m_pLeftChild->m_pParent = pMaxFromLeft->m_pParent;

		nodeToReplace->m_nVal = pMaxFromLeft->m_nVal;

		delete pMaxFromLeft;
	}
}

TreeNode* BinarySearchTree::GetMaxFromLeftTree(TreeNode*& pRoot)
{
	if(pRoot == NULL)
		return NULL;

	TreeNode* m_pRightChild = pRoot->m_pRightChild;
	if(m_pRightChild)
		GetMaxFromLeftTree(pRoot->m_pRightChild);
	else
		return pRoot;
}

int BinarySearchTree::GetMinimumHelper(const TreeNode*& pRoot)
{
	int ret = MIN;
	if(pRoot == NULL)
		return ret;

	if(pRoot->m_pLeftChild == NULL)
		return pRoot->m_nVal;
	else
		return GetMinimumHelper(const_cast<const TreeNode*&>(pRoot->m_pLeftChild));
}

int BinarySearchTree::GetMaximumHelper(const TreeNode*& pRoot)
{
	int ret = MIN;
	if(pRoot == NULL)
		return ret;

	if(pRoot->m_pRightChild == NULL)
		return pRoot->m_nVal;
	else
		return GetMaximumHelper(const_cast<const TreeNode*&>(pRoot->m_pRightChild));
}

int BinarySearchTree::GetMinimum()
{
	return GetMinimumHelper(const_cast<const TreeNode*&>(m_pRoot));
}

int BinarySearchTree::GetMaximum()
{
	return GetMaximumHelper(const_cast<const TreeNode*&>(m_pRoot));
}

int BinarySearchTree::GetPredecessor(int nVal)
{
	TreeNode* pNode = SearchElementHelper(nVal, const_cast<const TreeNode*&>(m_pRoot));

	if(pNode)
	{
		if(pNode->m_pLeftChild != NULL)
			return GetMinimumHelper(const_cast<const TreeNode*&>(pNode->m_pLeftChild));
		else
		{
			/* get first parent that has a right child */	
			TreeNode* pParent = pNode->m_pParent;
			while(pParent != NULL)
			{
				if(pParent->m_nVal > pNode->m_nVal)
					pParent = pParent->m_pParent;
				else
					return pParent->m_nVal;
			}

			/* no predecessor found*/
			std::cout << "Element " << nVal << " doesn't have a predecessor\n";
			return MIN;
		}
	}
	else
	{
		return MIN;
	}
}

int BinarySearchTree::GetSuccessor(int nVal)
{
	TreeNode* pNode = SearchElementHelper(nVal, const_cast<const TreeNode*&>(m_pRoot));

	if(pNode)
	{
		if(pNode->m_pRightChild)
			return GetMinimumHelper(const_cast<const TreeNode*&>(pNode->m_pRightChild));
		else
		{
			/*get first parent that has left child*/
			TreeNode* pParent = pNode->m_pParent;
			while(pParent != NULL)
			{
				if(pParent->m_nVal < pNode->m_nVal)
					pParent = pParent->m_pParent;
				else
					return pParent->m_nVal;
			}

			std::cout << "Element " << nVal << " doesn't have a successor";
			return MIN;
		}
	}
	else
		return MIN;
}

void BinarySearchTree::PrintTree(TreeNode* pRoot)
{
	if(pRoot == NULL)
		return;

	int nParentVal;
	bool bHasParent = false;
	if(pRoot->m_pParent)
	{
		bHasParent = true;
		nParentVal = pRoot->m_pParent->m_nVal;
	}

	if(bHasParent)
		std::cout << pRoot->m_nVal << "--> with parent " << nParentVal << "\n";
	else
		std::cout << pRoot->m_nVal << "\n";


	
	if(pRoot->m_pLeftChild)
	{
		std::cout << "left child\n ";
		PrintTree(pRoot->m_pLeftChild);
	}

	
	if(pRoot->m_pRightChild)
	{
		std::cout << "right child\n";
		PrintTree(pRoot->m_pRightChild);
	}
}

void BinarySearchTree::PrintSortedTreeHelper(const TreeNode*& pRoot)
{

}


void BinarySearchTree::FreeTree(TreeNode* pRoot)
{
	if(pRoot == NULL)
		return;
	FreeTree(pRoot->m_pLeftChild);
	FreeTree(pRoot->m_pRightChild);

	delete pRoot;
}

