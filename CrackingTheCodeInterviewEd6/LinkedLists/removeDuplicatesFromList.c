#include "list.h"

void RemoveDuplicatesFromList(Node** pHead)
{
	if(pHead)
	{
		Node* pCurrentHead = *pHead;
		
		while(pCurrentHead)
		{
			int nValue = pCurrentHead->m_nVal;
			Node* aux = pCurrentHead;
			while(aux && aux->m_pNext != NULL)
			{
				if(aux->m_pNext->m_nVal == nValue)
				{
					// we have to remove it
					
					Node* nodeToDelete = aux->m_pNext;
					aux->m_pNext = aux->m_pNext->m_pNext;
					free(nodeToDelete);
				}
				aux = aux->m_pNext;
			}

			pCurrentHead = pCurrentHead->m_pNext;
		}
	}
}

int main()
{
	Node* pHead = NULL;

	ReadList(&pHead);
	RemoveDuplicatesFromList(&pHead);
	PrintList(pHead);
}
