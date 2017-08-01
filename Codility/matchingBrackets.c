// you can write to stdout for debugging purposes, e.g.
// printf("this is a debug message\n");
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

const int START_SIZE = 10;
const int RESIZE_MULTIPLIER = 2;

typedef struct Stack
{
    char* m_nElements;
    int m_nTopIndex;
    int m_nSize;
}Stack;

bool reallocStack(Stack** stack, int nNewSize);

void initStack(Stack** stack)
{
    Stack* pStack = *stack;

    pStack = malloc(sizeof(Stack));
    pStack->m_nElements = malloc(START_SIZE * sizeof(char));
    
    pStack->m_nTopIndex = -1;
    pStack->m_nSize = START_SIZE;

    *stack = pStack;
}

char top(Stack* stack)
{
    if(stack == NULL)
        return '\0';
    
    if(stack->m_nTopIndex <= -1)
        return '\0';

    int nTopElementIndex = stack->m_nTopIndex;
    return stack->m_nElements[nTopElementIndex];        
}

void popStack(Stack** stack)
{
    Stack* pStack = *stack;
    if(pStack)
    {
        if(pStack->m_nTopIndex >= 0)
        {
            pStack->m_nElements[pStack->m_nTopIndex] = '\0';
            pStack->m_nTopIndex--;   
        }
    }
}

void pushStack(Stack** stack, char elem)
{
    Stack* pStack = *stack;
    if(pStack)
    {
        bool bCanAdd = true;
        if(pStack->m_nSize - pStack->m_nTopIndex == 1)
        {
            bCanAdd = reallocStack(stack, pStack->m_nSize *  RESIZE_MULTIPLIER);
        }
        
        if(bCanAdd)
        {
            pStack->m_nTopIndex++;
            pStack->m_nElements[pStack->m_nTopIndex] = elem;
        }
    }
}

bool reallocStack(Stack** stack, int nNewSize)
{
    Stack* pStack = *stack;
    if(pStack)
    {       
        char* aux = realloc(pStack->m_nElements, nNewSize);
        if(aux)
        {
            pStack->m_nElements = aux;
            pStack->m_nSize = nNewSize;
        }
        else
            return false;
            
        return true;
    }
    else
        return false;
}

bool isEmpty(Stack* stack)
{
    if(stack)
    {
        return (stack->m_nTopIndex < 0);
    }
    else
        return true;
}

void printAllStack(Stack* stack)
{
    if(stack)
    {
        while(!isEmpty(stack))
        {
            printf("Element %c\n", top(stack));
            popStack(&stack);
        }
    }
}

void freeStack(Stack** stack)
{
    Stack* pStack = *stack;
    if(pStack)
    {
        if(pStack->m_nElements)
        {
            free(pStack->m_nElements);
            pStack->m_nElements = NULL;
        }

        free(pStack);

        pStack = NULL;
    }

    *stack = pStack;
}

char getMatchingBracket(char c)
{
    char ret = ' ';
    switch(c) 
    {
        case '(' :
            ret = ')';
            break;
        case '[' :
            ret = ']';
            break;
        case '{' :
            ret = '}';
            break;
        default:
            break;
    }

    return ret;
}

bool isOpeningBracket(char c)
{
    if(c == '\0')
        return false;

    if(c == '{' || c == '(' || c == '[')
        return true;

    return false;
}

bool isClosingBracket(char c)
{
    if(c == '\0')
        return false;
    if(c == '}' || c == ')' || c == ']')
        return true;

    return false;  
}

bool isProperlyNested(char* str)
{
    int i = 0;
    Stack* myStack = NULL;
    initStack(&myStack);
    for(i = 0; i < strlen(str); ++i)
    {
        if(isOpeningBracket(str[i]))
        {
            pushStack(&myStack, str[i]);
        }
        else if(isClosingBracket(str[i]))
        {
            if(isEmpty(myStack))
                return false;
            else
            {
                char chTop = top(myStack);
                char matching = getMatchingBracket(chTop);
                if(matching == str[i])
                    popStack(&myStack); 
            }

        }
    }
    return true;
}

int main() {
    
    char* str = malloc(10);
    printf("str = ");
    scanf("%s", str);

    printf("%d\n", isProperlyNested(str));
    return 0;
    
}