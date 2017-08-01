#include "list.h"


Node* FindLoopStart(Node* pHead)
{
	if(pHead)
	{
		Node* pSlow = pHead;
		Node* pFast = pHead;

		do
		{
			pSlow = pSlow->m_pNext;
			pFast = pFast->m_pNext->m_pNext;
		}while(pSlow != pFast);

		// K steps until slow enters loop --> fast node is K positions ahead --> LOOP_SIZE - K behind and he
		// gets 1 step closer
		// they have met after LOOP_SIZE - k positions

		pSlow = pHead;
		while(pSlow != pFast)
		{
			pSlow = pSlow->m_pNext;
			pFast = pFast->m_pNext;
		}

		printf("Node value where loop starts is %d\n", pSlow->m_nVal);
		return pSlow;


	}
}


int main()
{
	Node* pList = NULL;
	ReadList(&pList);

	int nLength;
	Node* pTail = GetTail(pList, &nLength);

	pTail->m_pNext = pList->m_pNext->m_pNext;
	printf("%d\n", pTail->m_pNext->m_nVal);

	Node* pResult =	FindLoopStart1(pList);
	printf("Intersection = %d\n", pResult->m_nVal);

}