#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


typedef struct Node
{
	int m_nVal;
	struct Node* m_pNext;
} Node;

struct Stack
{
	Node* m_pTop;
} Stack_Default = { NULL};

typedef struct Stack Stack;

void Push(Stack* stk, int nElement);
int Pop(Stack* stk);
int Top(Stack stk);
void Print(Stack stk);
void SortStack(Stack* stk);


