#include "list.h"
#include "stdbool.h"

Node* IsPalindrome(Node* pHead, int nLen, int nBigSize, bool* bStop)
{
	if(pHead == NULL)
	{
		*bStop == true;
	}

	if(*bStop == false)
	{
		if(nLen == 2)
		{
			if(pHead->m_nVal == pHead->m_pNext->m_nVal)
			{
				// return next tail
				if(nLen != nBigSize)
					return pHead->m_pNext->m_pNext;
				else
				{
					printf("List is palindrome \n");
					return NULL;
				}

			}
			else
			{
				if(nLen == nBigSize)
				{
					printf("List is not a palindrome\n");
				}
				*bStop = true;
				return NULL;
			}
		}
		if(nLen == 1)
		{
			if(nLen == nBigSize)
			{
				printf("List is palindrome\n");
				return NULL;
			}
			return pHead->m_pNext;
		}

		// we get here only if list length > 2
		Node* pTail = IsPalindrome(pHead->m_pNext, nLen -2, nBigSize, bStop);
		if(*bStop == true || pTail == NULL)
		{
			printf("List not a palindrome \n");
			return NULL;
		}
		else
		{
			if(pHead->m_nVal != pTail->m_nVal)
			{
				*bStop = true;
				if(nLen == nBigSize)
					printf("List not a palindrome\n");
				return NULL;
			}
			else
			{
				if(nLen == nBigSize)
					printf("List is palindrome\n");
				else
					return pTail->m_pNext;
			}

		}
		
	}

}


bool IsPalindrome2(Node*pHead, int len, Node** pAuxHead)
{
	if(len == 1 || len == 2)
	{
		if(len == 2)
		{
			if(pHead->m_nVal != pHead->m_pNext->m_nVal)
				return false;
		}

		if(len == 1)
			*pAuxHead = pHead->m_pNext; // middle element
		else
			*pAuxHead = pHead->m_pNext->m_pNext;
		return true;
	}
	else
	{
		bool bRet = IsPalindrome2(pHead->m_pNext, len - 2, pAuxHead);
		if(bRet == false)
			return false;

		if(*pAuxHead == NULL)
			return false;

		if(pHead->m_nVal != (*pAuxHead)->m_nVal)
		{
			return false;
		}
		else
		{
			*pAuxHead = (*pAuxHead)->m_pNext;
		}

		return bRet;
	}

}


int main()
{
	Node* pList = NULL;
	ReadList(&pList);

	int nLength = ListLength(pList);
	printf("Lenth = %d\n",nLength);


//	bool bStop = false;
//	IsPalindrome(pList, nLength, nLength, &bStop);

	Node* pAux;
	bool bResult = IsPalindrome2(pList, nLength, &pAux);
	printf("bResult = %d\n", bResult);
}