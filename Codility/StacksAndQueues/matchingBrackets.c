#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct ListNode 
{
    char m_c;
    struct ListNode* m_pNext;

}ListNode;

void Push(ListNode** stack, char c)
{
    ListNode* pTop = *stack;

    ListNode* pNew = malloc(sizeof(ListNode));
    pNew->m_c = c;
    pNew->m_pNext = pTop;

    pTop = pNew;
    *stack = pTop;

}

bool IsEmpty(ListNode* stack)
{
    return stack == NULL;
}

char Top(ListNode* stack)
{
    if(!IsEmpty(stack))
        return stack->m_c;

    return '\0';
}

bool Pop(ListNode** stack)
{
    ListNode* pTop = *stack;

    if(pTop)
    {
        ListNode* pToDelete = pTop;
        pTop = pTop->m_pNext;
        free(pToDelete);
        pToDelete= NULL;
        *stack = pTop;
        return true;

    }
    else
        return false;
}

void Free(ListNode** stack)
{
    while(Pop(stack));
}

int main()
{
    ListNode *s = NULL;
    Push(&s, 'c');
    Push(&s, 'a');

    Free(&s);
}