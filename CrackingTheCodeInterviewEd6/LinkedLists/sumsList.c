#include "list.h"




void SumLists(Node* pNumber1, Node* pNumber2, Node** pResult)
{
	if(!pNumber1 || !pNumber2)
	{
		printf("Invalid lists \n");
		return;
	}

	if(pNumber1 == NULL)
		pResult = &pNumber2;
	if(pNumber2 == NULL)
		pResult = &pNumber1;

	Node* p1 = pNumber1;
	Node* p2 = pNumber2;

	int nCarry = 0;
	while(p1 || p2)
	{
		int nFirst = p1 ? p1->m_nVal : 0;
		int nSecond = p2 ? p2->m_nVal : 0;

		int val = (nFirst + nSecond + nCarry) % 10;

		if(nFirst + nSecond + nCarry > 9)
			nCarry = 1;
		else
			nCarry = 0;

		AddToList(pResult, val);

		if(p1)
			p1 = p1->m_pNext;
		if(p2)
			p2 = p2->m_pNext;
	}

	PrintReverseList(*pResult);
}

int main()
{
	Node* pNumber1 = NULL;
	ReadList(&pNumber1);
	Node* pNumber2 = NULL;
	ReadList(&pNumber2);
	Node* pResult = NULL;
	SumLists(pNumber1, pNumber2, &pResult);
}