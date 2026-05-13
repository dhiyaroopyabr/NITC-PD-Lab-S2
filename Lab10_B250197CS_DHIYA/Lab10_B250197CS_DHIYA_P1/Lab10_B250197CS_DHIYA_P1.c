#include "Lab10_B250197CS_DHIYA_P1.h"
int isBalanced(char *exp)
{
    char stack[MAX];
    int top = -1;
    for (int i = 0; exp[i]!='\0'; i++)
    {
        if (exp[i]=='(')
        {
            top++;
            stack[top] = '(';
        }
        else if (exp[i]==')')
        {
            if (top==-1)
            return 0;
            top--;
        }
    }
    if (top==-1)
    return 1;
    else
    return 0;
}