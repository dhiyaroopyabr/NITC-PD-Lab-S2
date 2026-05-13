#include "Lab12_B250197CS_DHIYA_P2.h"
#include <stdio.h>

int main()
{
    char ch;
    int num;
    node root = NULL;
    while (1)
    {
        scanf(" %c",&ch);
        if (ch=='i')
        {
            scanf("%d",&num);
            root = InsertKey(root,num);
        }
        else if (ch=='s')
        {
            scanf("%d",&num);
            if (SearchKey(root,num))
            {
                printf("PRESENT\n");
            }
            else
            {
                printf("NOT PRESENT\n");
            }
        }
        else if (ch=='d')
        {
            scanf("%d",&num);
            root = DeleteKey(root,num);
        }
        else if (ch=='k')
        {
            scanf("%d",&num);
            int count = 0;
            printf("%d\n",kthsmallest(root,num,&count));
        }
        else if (ch=='m')
        {
            node max = maximum(root);
            printf("%d\n",max->data);
        }
        else if (ch=='n')
        {
            node succ = successor(root,num);
            printf("%d\n",succ->data);
        }
        else if (ch=='e')
        {
            break;
        }
    }
}