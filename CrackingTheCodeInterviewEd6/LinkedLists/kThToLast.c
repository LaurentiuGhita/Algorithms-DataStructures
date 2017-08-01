#include "list.h"


int KthToLastElement(Node* pHead, int k)
{
	if(pHead)
	{

		Node* pSlow = pHead;
		Node* pFast = pHead;

		int i = 0;
		for(i = 0; i < k; ++i)
		{
			pFast = pFast->m_pNext;
			if(!pFast)
			{
				printf("No %d th from last element\n", k);
			}
		}

		while(pFast->m_pNext)
		{
			pSlow = pSlow->m_pNext;
			pFast = pFast->m_pNext;
		}

		return pSlow->m_nVal;
	}
}

int main()
{
	Node* pList = NULL;
	ReadList(&pList);

	int k;
	printf("Select k-th from end "); scanf("%d", &k);
	printf("K-th element from last = %d\n", KthToLastElement(pList, k));

	FreeList(&pList);
}