#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

bool isProperlyNested( char* S)
{
    if(strlen(S) == 0)
        return true;

    
    char *stack = malloc(sizeof(char) * strlen(S) );
    char *top = stack;
    char *str = S;
    *top = *str;
    str++;

    while(*str != '\0')
    {
        if( (*str == ')' && *top == '(' ) || 
            (*str == ']' && *top == '[' ) || 
            (*str == '}' && *top == '{' ))
        {
            top--;
        }
        else
        {
            // push on stack
            if(*str == '(' || *str == '{' || *str == '[')
            {
                top++;
                *top = *str;
            }
            else
            {
                free(stack);
                return false;
            }
        }

        str++;
    }

    if(*top == '\0')
    {
        top++;
        if(top == stack)
        {
            free(stack);
            return true;
        }
    }
    free(stack);
    return false;
     
}

int solution(char *S) {
    // write your code in C99 (gcc 6.2.0)
    if(isProperlyNested(S))
        return 1;
    return 0;
}
int main()
{
    printf("%d\n",isProperlyNested("(()"));
}