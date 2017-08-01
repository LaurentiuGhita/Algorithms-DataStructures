#include "list.h"


Node* GetKthElementAddress(Node* pHead, int k)
{
	int count = 0;
	Node* pRet = NULL;
	if(pHead)
	{
		while(pHead && count < k)
		{
			count++;
			pHead = pHead->m_pNext;
		}
	}

	return pHead;
}

void MoveOneToLeft(Node** pAddress)
{
	if(pAddress && *pAddress)
	{

		Node* pDest = *pAddress;
		Node* pFrom = pDest->m_pNext;
		Node* pNewTail = pDest;

		while(pFrom && pFrom->m_pNext)
		{
			pDest->m_nVal = pFrom->m_nVal;
			pDest = pDest->m_pNext;
			pFrom = pFrom->m_pNext;
		}

		//pDest was tail
		if(pFrom == NULL)
			pDest->m_pNext = NULL;
		else
		{
			if(pFrom->m_pNext == NULL)
			{
				Node* pToDelete = pFrom;
				pDest->m_nVal = pFrom->m_nVal;
				free(pToDelete);
				pDest->m_pNext = NULL;
			}			
		}


	}
}

void DeleteByAddress(Node** pHead, Node* pAddress)
{
	if(pHead)
	{
		Node* pCurrentHead = *pHead;
		if(pCurrentHead)
		{
			while(pCurrentHead)
			{
				if(pCurrentHead == pAddress)
				{
					MoveOneToLeft(&pCurrentHead);
					break;
				}
				else
				{
					pCurrentHead = pCurrentHead->m_pNext;
				}	
			}

		}
	}
}


int main()
{
	Node* pList = NULL;
	ReadList(&pList);

	int nIndex;
	printf("Element index to delete "); scanf("%d", &nIndex);

	Node* pAddress = GetKthElementAddress(pList, nIndex);
	DeleteByAddress(&pList, pAddress);


	PrintList(pList);

}