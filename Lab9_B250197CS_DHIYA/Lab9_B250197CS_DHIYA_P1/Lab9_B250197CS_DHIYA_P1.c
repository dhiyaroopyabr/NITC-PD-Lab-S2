#include "Lab9_B250197CS_DHIYA_P1.h"

void push(int book[], int *top, int N, int x)
{
    if (*top == N-1)
    {
        printf("Overflow!\n");
    }
    else
    {
        (*top)++;
        book[*top] = x;
    }
}

void pop(int book[], int *top)
{
    if (*top == -1)
    {
        printf("Underflow\n");
    }
    else
    {
        printf("%d\n", book[*top]);
        (*top)--;
    }
}

void peek(int book[], int top)
{
    if (top == -1)
    {
        printf("Empty\n");
    }
    else
    {
        printf("%d\n", book[top]);
    }
}

void display(int book[], int top)
{
    if (top == -1)
    {
        printf("Empty\n");
        return;
    }

    for (int i = top; i >= 0; i--)
    {
        printf("%d\n", book[i]);
    }
}