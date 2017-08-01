#include "list.h"
#include <stdbool.h>




Node* IntersectionNode(Node* pList1, Node* pList2)
{
	int nList1Size = 0;
	int nList2Size = 0;
	
	Node* pTail1 = GetTail(pList1, &nList1Size);
	Node* pTail2 = GetTail(pList2, &nList2Size);

	if(nList2Size == nList1Size && pTail1 == pTail2)
	{
		while(pList1 != pList2)
		{
			pList1 = pList1->m_pNext;
			pList2 = pList2->m_pNext;
		}

		printf("Commont value at node with val %d\n", pList1->m_nVal);
		return pList1;
	}

	if(pTail1 == pTail2)
	{
		Node* pList1Start = pList1;
		Node* pList2Start = pList2;

		if(nList1Size < nList2Size)
		{
			int nAdvanceCount = nList2Size - nList1Size;
			while(nAdvanceCount != 0)
			{
				pList2Start = pList2Start->m_pNext;
				nAdvanceCount--;
			}
		}
		if(nList1Size > nList2Size)
		{
			int nAdvanceCount = nList1Size - nList2Size;
			while(nAdvanceCount != 0)
			{
				pList1Start = pList1Start->m_pNext;
				nAdvanceCount--;
			}			
		}

		while(pList1Start != pList2Start)
		{
			pList2Start = pList2Start->m_pNext;
			pList1Start = pList1Start->m_pNext;
		}

		printf("Commont value at node with val %d\n", pList1Start->m_nVal);
		return pList1Start;
	}
	else
	{
		printf("Lists don't intersect\n");
		return NULL;
	}
}


int main()
{
	Node* pList1 = NULL;
	ReadList(&pList1);

	Node* pList2 = NULL;
	AddToList(&pList2, 1);
	pList2->m_pNext = pList1->m_pNext->m_pNext;

	IntersectionNode(pList1, pList2);
}