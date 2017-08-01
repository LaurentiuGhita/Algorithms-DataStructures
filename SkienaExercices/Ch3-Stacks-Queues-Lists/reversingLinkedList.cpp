#include <iostream>

struct Node
{
	Node(int x) : m_nVal(x), m_pNext(nullptr){}
	int m_nVal;
	Node* m_pNext;
};


Node* reverseList(Node* pNode)
{

	if(pNode != nullptr)
	{
		Node* pCurrent = pNode;
		Node* pNext = pNode->m_pNext;

		// first node next is null
		pCurrent->m_pNext = nullptr;

		while(pNext != nullptr)
		{
			// next node
			Node* next = pNext;

			// next link from next node
			pNext = pNext->m_pNext;

			// change next link to point to current node
			next->m_pNext= pCurrent;

			pCurrent = next;
		}

		/* return new head of list */
		if(pNext == nullptr)
			return pCurrent;
	}
	else
	{
		return nullptr;
	}
}

Node* reverseListRecursive(Node* pNode, Node* pReversed)
{
	if(pNode == nullptr)
		return pReversed;

	Node* current = pNode;
	Node* rest = current->m_pNext;
	current->m_pNext = pReversed;

	return reverseListRecursive(rest, current);

}

void printList(const Node* pHead)
{
	Node* pAux = const_cast<Node*>(pHead);
	while(pAux != nullptr)
	{
		std::cout << pAux->m_nVal << " ";
		pAux = pAux->m_pNext;
	}
	std::cout << "\n";
}


int main()
{
	Node node1(1);
	Node node2(2);
	Node node3(3);
	Node node4(4);
	Node node5(5);

	node1.m_pNext = &node2;
	node2.m_pNext = &node3;
	node3.m_pNext = &node4;
	node4.m_pNext = &node5;

	printList(&node1);
	Node* newHead = reverseListRecursive(&node1, NULL);

	printList(newHead);
}