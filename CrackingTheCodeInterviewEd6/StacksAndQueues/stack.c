#include "stack.h"

void Push(Stack* stk, int nElement)
{
	if(stk == NULL)
	{
		stk = malloc(sizeof(Stack));
		
		Node* pNode = malloc(sizeof(Node));
		pNode->m_nVal = nElement;
		pNode->m_pNext = NULL;

		stk->m_pTop = pNode;
	}
	else
	{
		Node* pNode = malloc(sizeof(Node));
		pNode->m_nVal = nElement;

		pNode->m_pNext = stk->m_pTop;
		stk->m_pTop = pNode;
	}
}


int Pop(Stack* stk)
{
	int val = -1;
	if(stk && stk->m_pTop)
	{
		Node* pTop = stk->m_pTop; 

		val = stk->m_pTop->m_nVal;
		stk->m_pTop = stk->m_pTop->m_pNext;

		free(pTop);
	}

	return val;
}


int Top(Stack stk)
{
	if(stk.m_pTop)
		return stk.m_pTop->m_nVal;

	return -1;
}

void Print(Stack stk)
{
	while(stk.m_pTop)
	{
		printf("%d ", stk.m_pTop->m_nVal);
		stk.m_pTop = stk.m_pTop->m_pNext;
	}
}

bool Empty(Stack stk)
{
	if(stk.m_pTop == NULL)
		return true;

	return false;
}

void SortStack(Stack* stk)
{
	Stack s2 = Stack_Default;

	while(! Empty(*stk))
	{
		int aux = Pop(stk);
		while(Top(s2) > aux)
		{
			int nT = Pop(&s2);
			Push(stk, nT);
		}

		Push(&s2, aux);
	}

	while(!Empty(s2))
	{
		Push(stk, Pop(&s2));
	}
}


int main()
{
	Stack s = Node_Default;

	Push(&s, 5);
	Push(&s, 1);
	Push(&s, 3);

	SortStack(&s);

	Print(s);

	return 0;
}