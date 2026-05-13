#include "Lab9_B250197CS_DHIYA_P1.h"

int main()
{
    int book[1000];
    int N;
    int top = -1;
    scanf("%d",&N);
    int ch;
    while (1)
    {
        int flag = 0;
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
            {
                int x;
                scanf("%d",&x);
                push(book, &top, N, x);
                break;
            }

            case 2:
                pop(book, &top);
                break;

            case 3:
                peek(book, top);
                break;

            case 4:
                display(book, top);
                break;

            case 5:
                flag = 1;
                break;
        }
        if (flag)
            break;
    }
    return 0;
}