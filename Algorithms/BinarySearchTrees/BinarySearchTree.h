#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

#include <iostream>

struct TreeNode
{
	TreeNode(int nVal, TreeNode* pParent);
	int m_nVal;
	TreeNode* m_pRightChild;
	TreeNode* m_pLeftChild;
	TreeNode* m_pParent;
};

class BinarySearchTree
{
public:
	BinarySearchTree() : m_pRoot(NULL) {};
	~BinarySearchTree();
	void AddElement(int nVal);
	bool SearchElement(int nVal);
	bool DeleteElement(int nVal);
	void PrintBinaryTree();
	int  GetMinimum();
	int  GetMaximum();
	int  GetPredecessor(int nVal);
	int  GetSuccessor(int nVal);
	int  PrintSortedTree();

private:
	void AddElementHelper(int nVal, TreeNode*& pRoot);
	TreeNode* SearchElementHelper(int nVal, const TreeNode*& pRoot);
	bool DeleteElementHelper(int nVal, TreeNode*& pRoot);
	TreeNode* GetMaxFromLeftTree(TreeNode*& pRoot);
	int GetMinimumHelper(const TreeNode*& pRoot);
	int GetMaximumHelper(const TreeNode*& pRoot);
	void PrintTree(TreeNode* pRoot);
	void FreeTree(TreeNode* pRoot);
	void PrintSortedTreeHelper(const TreeNode*&);

	TreeNode* m_pRoot;
};

#endif