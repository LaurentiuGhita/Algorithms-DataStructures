#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <queue>

const int NOT_SET = -1000;

struct Node 
{
	Node() : m_nVal(-999), m_pParent(NULL), m_pLeftChild(NULL), m_pRightChild(NULL) {}
	int m_nVal;
	struct Node* m_pParent;
	struct Node* m_pLeftChild;
	struct Node* m_pRightChild;
};// Node_Default = { -999, NULL, NULL, NULL} ;

typedef struct Node Node;

void Insert(Node** pRoot, int nVal);
void TraverseInOrder(Node* pRoot);
void TraversePreOrder(Node* pRoot);
void TraversePostOrder(Node* pRoot);
int CheckHeight(Node* pRoot);
int GetHeight(Node* pRoot);
bool IsBalanced(Node* pRoot);
bool CheckIfBinarySearchTree(Node* pRoot, int min , int max, bool bRoot);
int GetSuccessor(Node* pNode);
int IsLeftChild(Node* pParent, Node* pChild);
bool Covers(Node* pRoot, Node* pChild);
Node* FindCommonAncestor(Node* pRoot, Node* p, Node* q);
bool MatchSubTree(Node* pRoot, Node* pTree);
int GetMinimumHeight(Node* pRoot, int& min);
