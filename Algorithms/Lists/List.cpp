#include "List.h"

Node::Node(int nVal)
{
	m_nVal = nVal;
	pNext = NULL;
}

List::~List()
{
	Node* aux = headNode;
	while(aux != NULL)
	{
		Node* current = aux;
		aux = aux->pNext;
		delete current;
	}
}

void List::Add(int nVal)
{
	Node* newNode = new Node(nVal);
    newNode->pNext = headNode;
}

void List::Print()
{
	if(headNode == NULL)
	{
		std::cout << "List is empty\n";
		return;
	}

	Node* aux = headNode;
	while(aux != NULL)
	{
		std::cout << aux->m_nVal << " ";
		aux = aux->pNext;
	}
	std::cout << std::endl;
}

bool List::Search(int nVal)
{
	if(headNode == NULL)
	{
		return false;
	}

	Node* aux = headNode;
	while(aux != NULL)
	{
		if(aux->m_nVal == nVal)
		{
			return true;
		}
		aux = aux->pNext;
	}
}

bool List::Delete(int nVal)
{
	if(headNode == NULL)
		return false;

	Node* nodeToDelete = headNode;
	Node* previous = NULL;
	while(nodeToDelete != NULL && nodeToDelete->m_nVal != nVal)
	{
		previous = nodeToDelete;
		nodeToDelete = nodeToDelete->pNext;
	}

	if(previous == NULL)
	{
		headNode = headNode->pNext;
	}
	else
	{
		previous->pNext = nodeToDelete->pNext;
	}

	delete nodeToDelete;

}