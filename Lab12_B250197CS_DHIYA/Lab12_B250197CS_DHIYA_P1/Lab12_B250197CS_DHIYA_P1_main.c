#include "Lab12_B250197CS_DHIYA_P1.h"
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
            root = InsertKey(root, num);
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
            root = DeleteKey(root,num);
        }
        else if (ch=='p')
        {
            inorder(root);
            printf("\n");
        }
        else if (ch=='t')
        {
            preorder(root);
            printf("\n");
        }
        else if (ch=='b')
        {
            postorder(root);
            printf("\n");
        }
        else if (ch=='e')
        {
            break;
        }
    }
}