#include "list.h"

int main()
{
	Node* pHead = NULL;
	AddToList(&pHead, 10);
	AddToList(&pHead, 11);
	AddToList(&pHead, 12);
	DeleteFromList(&pHead, 11);
	//DeleteFromList(&pHead, 12);
	//DeleteFromList(&pHead, 10);

	PrintList(pHead);
}
