#include "Lab9_B250197CS_DHIYA_P4.h"

int main()
{
    node front = NULL;
    node rear = NULL;

    int n;
    int size = 0;

    char s[100];

    scanf("%d",&n);

    while(1)
    {
        scanf("%s",s);

        if (strcmp(s,"Enqueue")==0)
        {
            enqueue(&front,&rear,&size,n);
        }
        else if (strcmp(s,"Dequeue")==0)
        {
            dequeue(&front,&rear,&size);
        }
        else if (strcmp(s,"Display")==0)
        {
            char ch;
            scanf(" %c",&ch);

            if (ch=='L')
            {
                display(front,ch);
            }
            else
            {
                display(rear,ch);
            }
        }
        else if (strcmp(s,"Exit")==0)
        {
            break;
        }
    }

    return 0;
}