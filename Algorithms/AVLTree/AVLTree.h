#ifndef AVL_TREE_H
#define AVL_TREE_H

#include <iostream>
#include <stdlib.h>

template <typename T>
struct AVLNode
{
	AVLNode(T val) : m_data(val), m_nHeight(1), pLeft(nullptr), pRight(nullptr), pParent(nullptr){}
	T m_data;
	int m_nHeight;
	struct AVLNode* pLeft;
	struct AVLNode* pRight;
	struct AVLNode* pParent;

	//AVLNode<T> operator=(const AVLNode<T>& src );


	int Height() { return m_nHeight; } const
	void SetHeight(int nHeight) { m_nHeight = nHeight; }
};

template <typename T>
class AVLTree
{
public:
	AVLTree() : m_pRoot(nullptr){}
	void PrintPreOrder();
	void AddNode(T val);
	void RemoveNode(T val);

	int GetHeight(AVLNode<T>& root);
	AVLNode<T>* GetNode(T val);
	int GetChildHeightDiff(AVLNode<T>& root);

	AVLNode<T>* LeftLeftRotation(AVLNode<T>*& pRoot);
	AVLNode<T>* RightRightRotation(AVLNode<T>*& pRoot);
	AVLNode<T>* RightLeftRotation(AVLNode<T>*& pRoot);
	AVLNode<T>* LeftRightRotation(AVLNode<T>*& pRoot);
	

	AVLNode<T>* Balance(AVLNode<T>*& pRoot);
	int	AdjustHeight(AVLNode<T>& pRoot);
	int RecomputeHeight(AVLNode<T>& pRoot);
	void RecomputeHeightUpward(AVLNode<T>& root);

	AVLNode<T>* GetPredecessor(const AVLNode<T>& root); // to make private
private:
	void PrintPreOrderHelper(const AVLNode<T>& pRoot);
	AVLNode<T>* AddNodeHelper(T val, AVLNode<T>*& pRoot);
	AVLNode<T>* RemoveNodeHelper(T val, AVLNode<T>*& pRoot);

	AVLNode<T>* GetNodeHelper(T val, AVLNode<T>& root);
	

	AVLNode<T>* m_pRoot;
};

template <typename T>
void AVLTree<T>::PrintPreOrder()
{
	if(m_pRoot)
		PrintPreOrderHelper(*m_pRoot);
}

template <typename T>
void AVLTree<T>::AddNode(T val)
{
	if(m_pRoot == nullptr)
	{
		m_pRoot = new AVLNode<T>(val);
	}
	else
		AddNodeHelper(val, m_pRoot);
}

template <typename T>
void AVLTree<T>::RemoveNode(T val)
{
	AVLNode<T>* nodeToDelete = GetNode(val);
	AVLNode<T>* replacementNode = nullptr;
	if(nodeToDelete == nullptr)
	{
		std::cout << "Node " << val << " not in tree \n";

	}
	else
	{
		AVLNode<T>* pPredecessor = GetPredecessor(*nodeToDelete);
		AVLNode<T>* pParent = nodeToDelete->pParent;

		if(pPredecessor)
		{
			// adjust link from parrent
			nodeToDelete->m_data = pPredecessor->m_data;

			if(pPredecessor->pParent != nodeToDelete)
			{
				// it is a right child from left subtree
				AVLNode<T>* predecessorParent = pPredecessor->pParent;
				AVLNode<T>* predecessorLeftTreeRoot = pPredecessor->pLeft;

				// adjust link for predecessor's parent
				if(predecessorParent)
				{
					predecessorParent->pRight = predecessorLeftTreeRoot;
					if(predecessorLeftTreeRoot)
						predecessorLeftTreeRoot->pParent = predecessorParent;
				

					RecomputeHeightUpward(*predecessorParent); // not sure
				}
			}
			else
			{	
				// first left child
				AVLNode<T>* bkp = nodeToDelete;

				if(pPredecessor->pLeft)
					pPredecessor->pLeft->pParent = nodeToDelete;

				nodeToDelete->pLeft = pPredecessor->pLeft;

				RecomputeHeightUpward(*nodeToDelete);
			}
				
			delete pPredecessor;
		}
		else
		{
			// right child replaces node to delete
			AVLNode<T>* pRightChild = nodeToDelete->pRight;

			// link parent 
			if(pParent)
			{
				if(val < pParent->m_data)
				{
					// node to delete is left child
					pParent->pLeft = pRightChild;
				}
				else
					pParent->pRight = pRightChild;
			}
			if(pRightChild)
				pRightChild->pParent = nodeToDelete->pParent;

			RecomputeHeightUpward(*pParent);
		}

		// rebalance up to the root
		AVLNode<T>* node = pParent;
		while(node != nullptr)
		{
			Balance(node);
			node = node->pParent;
		}
	}
}


template <typename T>
int AVLTree<T>::GetHeight(AVLNode<T>& root)
{
	return root.Height();
}

template <typename T>
AVLNode<T>* AVLTree<T>::GetNode(T val)
{
	return GetNodeHelper(val, *m_pRoot);
}

template <typename T>
int AVLTree<T>::GetChildHeightDiff(AVLNode<T>& root)
{
	int nLeftHeight = 0;
	int nRightHeight = 0;
	
	if(root.pLeft)
		nLeftHeight = GetHeight(*root.pLeft);
	if(root.pRight) 
		nRightHeight = GetHeight(*root.pRight);

	return nLeftHeight - nRightHeight;
}

template <typename T>
void AVLTree<T>::PrintPreOrderHelper(const AVLNode<T>& root)
{
	std::cout << root.m_data;
	std::cout  << " weight " << root.m_nHeight << " ";
	if(root.pParent)
		std::cout << " with parent " << root.pParent->m_data;
	
	if(root.pLeft)
		std::cout << " with left child " << root.pLeft->m_data;

	if(root.pRight)
		std::cout << " and right child " << root.pRight->m_data;

	std::cout << "\n";

	if(root.pLeft)
	{
		PrintPreOrderHelper(*root.pLeft);
	}
	
	if(root.pRight)
		PrintPreOrderHelper(*root.pRight);
}

template <typename T>
AVLNode<T>* AVLTree<T>::AddNodeHelper(T val, AVLNode<T>*& pRoot)
{
	if(pRoot == nullptr)
		return new AVLNode<T>(val);

	// add as left child
	if(val > pRoot->m_data)
	{
		pRoot->pRight = AddNodeHelper(val, pRoot->pRight);
		pRoot->pRight->pParent = pRoot;
	}
	else if(val < pRoot->m_data)
	{
		pRoot->pLeft = AddNodeHelper(val, pRoot->pLeft);
		pRoot->pLeft->pParent = pRoot;
	}


	AdjustHeight(*pRoot);
	Balance(pRoot);
	return pRoot;
//	
}

template <typename T>
AVLNode<T>* AVLTree<T>::GetNodeHelper(T val, AVLNode<T>& root)
{
	if(root.m_data == val)
		return &root;
	else
	{
		if(val > root.m_data)
		{
			if(root.pRight)
				return GetNodeHelper(val, *root.pRight);

		}
		else
		{
			if(root.pLeft)
				return GetNodeHelper(val, *root.pLeft);
		}
		return nullptr;
	}
}

template <typename T>
AVLNode<T>* AVLTree<T>::GetPredecessor(const AVLNode<T>& root)
{
	if(root.pLeft == nullptr)
		return nullptr;

	//return max from left subtree --> go right as much as pussible

	AVLNode<T>* predecessor = root.pLeft;

	while(predecessor->pRight != nullptr)
	{
		predecessor = predecessor->pRight;
	}

	return predecessor;
}

template <typename T>
AVLNode<T>* AVLTree<T>::LeftLeftRotation(AVLNode<T>*& pRoot)
{
	AVLNode<T>* newRoot = pRoot->pRight;
	newRoot->pParent = pRoot->pParent;


	pRoot->pRight = newRoot->pLeft;
	if(newRoot->pLeft)
		newRoot->pLeft->pParent = pRoot;

	newRoot->pLeft = pRoot;
	pRoot->pParent = newRoot;

	if(pRoot == m_pRoot)
		m_pRoot = newRoot;
	else
		pRoot = newRoot;

	RecomputeHeight(*newRoot);

	return newRoot;
}

template <typename T>
AVLNode<T>* AVLTree<T>::RightRightRotation(AVLNode<T>*& pRoot)
{
	AVLNode<T>* newRoot = pRoot->pLeft;
	newRoot->pParent = pRoot->pParent;

	pRoot->pLeft = newRoot->pRight;
	if(newRoot->pRight)
		newRoot->pRight->pParent = pRoot;

	newRoot->pRight = pRoot;
	pRoot->pParent = newRoot;

	if(pRoot == m_pRoot)
		m_pRoot = newRoot;
	else
		pRoot = newRoot;

	RecomputeHeight(*newRoot);
	return newRoot;
}


template <typename T>
AVLNode<T>* AVLTree<T>::RightLeftRotation(AVLNode<T>*& pRoot)
{
	bool bChangeRoot = false;
	/* first rotate left left subtree */
	AVLNode<T>* temp = pRoot->pLeft;
	pRoot->pLeft = LeftLeftRotation(temp);

	if(pRoot == m_pRoot)
		bChangeRoot = true;

	AVLNode<T>* newRoot = RightRightRotation(pRoot);

	if(bChangeRoot)
		m_pRoot = newRoot;

	return newRoot;
}

template <typename T>
AVLNode<T>* AVLTree<T>::LeftRightRotation(AVLNode<T>*& pRoot)
{
	bool bChangeRoot = false;
	/* first rotate right the right subtree */
	AVLNode<T>* temp = pRoot->pRight;
	pRoot->pRight = RightRightRotation(temp);

	if(pRoot == m_pRoot)
		bChangeRoot = true;

	AVLNode<T>* newRoot = LeftLeftRotation(pRoot);

	if(bChangeRoot)
		m_pRoot = newRoot;

	return newRoot;
}


template <typename T>
AVLNode<T>* AVLTree<T>::Balance(AVLNode<T>*& pRoot)
{
	if(pRoot == nullptr)
		return nullptr;

	bool bChangeRoot = false;
	if(pRoot == m_pRoot)
		bChangeRoot = true;

	AVLNode<T>& temp = *pRoot;

	int nDiff = GetChildHeightDiff(temp);
	
	// no changs
	if(abs(nDiff) == 1 || abs(nDiff) == 0)
		return pRoot;

	// left subtree has bigger height 
	if(nDiff > 1)
	{
		std::cout << "balancing root node with val" << pRoot->m_data << "\n";
		if(GetChildHeightDiff(*(pRoot->pLeft)) >= 0)
		{
			// simple left left
			pRoot = RightRightRotation(pRoot);

		}
		else
		{
			pRoot = RightLeftRotation(pRoot);
		}
	}
	else
	{	
		if(GetChildHeightDiff(*(pRoot->pRight)) <= 0)
		{
			// simple right right
			pRoot = LeftLeftRotation(pRoot);
		}
		else
			pRoot = LeftRightRotation(pRoot);
	}

	if(bChangeRoot)
		m_pRoot = pRoot;

	return pRoot;
}

template <typename T>
int	AVLTree<T>::AdjustHeight(AVLNode<T>& root)
{
	int nLeft = 0;
	int nRight = 0;

	if(root.pLeft)
		nLeft = GetHeight(*root.pLeft);
	
	if(root.pRight)
		nRight = GetHeight(*root.pRight);

	int max = std::max(nLeft, nRight);

	root.SetHeight(max + 1);
	return max + 1;
}

template <typename T>
int AVLTree<T>::RecomputeHeight(AVLNode<T>& root)
{
	if(nullptr == root.pRight && nullptr == root.pLeft)
	{
		root.SetHeight(1);
		return 1;
	}

	int nLeftHeight = 0;
	if(root.pLeft)
		nLeftHeight = RecomputeHeight(*root.pLeft);



	int nRightHeight = 0;
	if(root.pRight)
		nRightHeight = RecomputeHeight(*root.pRight);

	int max = std::max(nLeftHeight, nRightHeight);

	int currentHeight = root.Height();

	if(currentHeight != max + 1)
		root.SetHeight(max + 1);

	return max + 1;
}

template <typename T>
void AVLTree<T>::RecomputeHeightUpward(AVLNode<T>& root)
{
	AVLNode<T>* node = &root;
	while(node != nullptr)
	{
		int nCurrentHeight = node->Height();
		int nRet = RecomputeHeight(*node);
		if(nCurrentHeight == nRet)
		{
			//std::cout << "Stopping at node with val " << node->m_data << "\n";
			break;
		}
		node = node->pParent;
	}
}

#endif