#include "list.h"


// pList1 : l1 -> l2 -> l3 -> ..  number l1l2l3
// pList2 : n1 -> n2 -> n3 -> ..  number n1n2n3
// result = l1l1l3 + n1n2n3 --> first element is most significat

typedef struct ReturnInfo
{
	Node* pNode;
	int carry;
}ReturnInfo;

#if 0
ReturnInfo* AddLists(Node* pList1, Node** pList2)
{
	static int numCals = 0;
	numCals++;
	if(pList1 == NULL && pList2 == NULL)
		return NULL;

	int nLeftNumber = 0;
	int nRightNumber = 0;

	if(pList1 != NULL)
	{
		nLeftNumber = pList1->m_nVal;
	}

	if(pList2 != NULL)
	{
		nRightNumber = pList2->m_nVal;
	}

	Node* firstArg = NULL;
	if(pList1)
		firstArg = pList1->m_pNext;

	Node* secondArg = NULL;
	if(pList2)
		secondArg = pList2->m_pNext;

	ReturnInfo* lowerRankRes = AddLists(firstArg, secondArg);

	int carry = 0;
	if(lowerRankRes)
		carry = lowerRankRes->carry;

	int nextCarry = 0;
	int nCurrentNumber = nLeftNumber + nRightNumber + carry;
	if(nLeftNumber + nRightNumber + carry > 9)
	{
		nCurrentNumber %= 10;
		nextCarry = 1;
	}

	Node* aux = malloc(sizeof(Node));
	aux->m_pNext = NULL;
	aux->m_nVal = nCurrentNumber;
	if(lowerRankRes)
		aux->m_pNext = lowerRankRes->pNode;



	ReturnInfo* toRet = malloc(sizeof(ReturnInfo));
	toRet->pNode = aux;
	toRet->carry = nextCarry;

	PrintList(aux);

	return toRet;

}
#endif


int AddLists(Node* pList1, Node* pList2, Node** pList3)
{
	if(pList1 == NULL && pList2 == NULL)
		return 0 ;

	int nLeftNumber = 0;
	int nRightNumber = 0;

	if(pList1 != NULL)
	{
		nLeftNumber = pList1->m_nVal;
	}

	if(pList2 != NULL)
	{
		nRightNumber = pList2->m_nVal;
	}

	Node* firstArg = NULL;
	if(pList1)
		firstArg = pList1->m_pNext;

	Node* secondArg = NULL;
	if(pList2)
		secondArg = pList2->m_pNext;



	// reached last elements
	int currentCarry = 0;
	int prevCarry = AddLists(firstArg, secondArg, pList3);
	if(nLeftNumber + nRightNumber  + prevCarry> 9)
	{
		currentCarry = 1;
	}

	Node* pNewHead = pNewHead = malloc(sizeof(Node));
	pNewHead->m_nVal = (nLeftNumber + nRightNumber) % 10;
	
	if(firstArg == NULL && secondArg == NULL)
	{
		pNewHead->m_pNext = NULL;
	}
	else
		pNewHead->m_pNext = *pList3;

	*pList3 = pNewHead;
	return currentCarry;
}


void AddListsHelper(Node* pList1, Node* pList2, Node** pList3)
{
	if(ListLength(pList1) > ListLength(pList2))
	{
		PadList(&pList2, ListLength(pList1) - ListLength(pList2));
	}
	else
	{
		PadList(&pList1, ListLength(pList2) - ListLength(pList1));	
	}

	int carry = AddLists(pList1, pList2, pList3);
	if(carry == 1)
	{
		// need to add a new node 
		Node* aux = malloc(sizeof(Node));
		aux->m_nVal = 1;
		aux->m_pNext = *pList3;
		*pList3 = aux;
	}
}



int main()
{
	Node* pNumber1 = NULL;
	ReadList(&pNumber1);
	Node* pNumber2 = NULL;
	ReadList(&pNumber2);
	Node* pResult = NULL;
	printf("----------------\n");
	AddListsHelper(pNumber1, pNumber2, &pResult);
	PrintList(pResult);
	return 0;
}






