#include "Lab12_B250197CS_DHIYA_P4.h"
#include <stdio.h>

int main()
{
    int n1,n2,x;
    node root1 = NULL;
    node root2 = NULL;
    // bst1
    scanf("%d",&n1);
    for (int i = 0; i < n1; i++)
    {
        scanf("%d",&x);
        root1 = insert(root1,x);
    }
    // bst2
    scanf("%d",&n2);
    for (int i = 0; i < n2; i++)
    {
        scanf("%d",&x);
        root2 = insert(root2,x);
    }
    // check
    if (isSubtree(root2,root1))
        printf("BST1 is a subtree of BST2\n");
    else
        printf("BST1 is NOT a subtree of BST2\n");
    return 0;
}