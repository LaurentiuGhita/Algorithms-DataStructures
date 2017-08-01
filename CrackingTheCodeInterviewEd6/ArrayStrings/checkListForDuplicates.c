#include <stdio.h>

typedef struct Node
{
	Node* m_pNext;
	int m_nVal;
}Node;

void AddToList(Node* pHead, int nElement)
{
	Node* newNode = malloc(sizeof(Node)); 
	newNode->m_pNext = NULL;
	newNode->m_nVal = nElement;

	if(pHead == NULL)
	{
		pHead = newNode;
	}
	else
		AddToList(pHead->m_pNext, nElement);
}

void PrintList(Node* pHead)
{
	while(pHead != NULL)
	{
		printf("%d ", pHead->m_nVal);
	}
	printf("\n");
}

int main()
{
	Node* pHead;
	AddToList(pHead, 10);
	AddToList(pHead, 11);
	AddToList(pHead, 12);

	PrintList(pHead);
}
