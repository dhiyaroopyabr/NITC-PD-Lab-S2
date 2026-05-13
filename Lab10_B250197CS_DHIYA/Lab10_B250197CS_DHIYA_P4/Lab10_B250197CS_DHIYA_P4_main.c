#include <stdio.h>
#include "Lab10_B250197CS_DHIYA_P4.h"

int main()
{
    node root = NULL;
    int ch;
    printf("1. Insert Vehicle’s info into BT\n");
    printf("2. Display Inorder Traversal\n");
    printf("3. Display Preorder Traversal\n");
    printf("4. Display Postorder Traversal\n");
    printf("5. Display Level Order Traversal\n");
    printf("6. Search for a Vehicle’s No.\n");
    printf("7. Exit\n");
    while(1)
    {
        scanf(" %d",&ch);
        if (ch==1)
        {
            int vno, price;
            char model[31];
            scanf("%d %s %d",&vno, model, &price);
            root = insertLevelOrder(root,vno,model,price);
        }
        else if (ch==2)
        {
            inorder(root);
        }
        else if (ch==3)
        {
            preorder(root);
        }
        else if (ch==4)
        {
            postorder(root);
        }
        else if (ch==5)
        {
            levelOrder(root);
        }
        else if (ch==6)
        {
            int vno;
            scanf("%d",&vno);
            node res = search(root, vno);
            if (res)
            printf("%d %s %d\n",res->vno,res->model,res->price);
            else
            printf("-1\n");
        }
        else if (ch==7)
        {
            break;
        }
    }
    return 0;
}