#include "Lab12_B250197CS_DHIYA_P4.h"
#include <stdio.h>
#include <stdlib.h>

node createNode(int data)
{
    node newNode = (node)malloc(sizeof(struct list));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

node insert(node root, int data)
{
    if (root==NULL)
        return createNode(data);
    if (data<root->data)
        root->left = insert(root->left,data);
    else if (data>root->data)
        root->right = insert(root->right,data);
    return root;
}

// check identical trees
int isId(node root1, node root2)
{
    if (root1==NULL && root2==NULL)
        return 1;
    if (root1==NULL || root2==NULL)
        return 0;
    return (root1->data==root2->data)&&isId(root1->left,root2->left)&&isId(root1->right,root2->right);
}

// check subtree
int isSubtree(node root1, node root2)
{
    if (root2==NULL)
        return 1;
    if (root1==NULL)
        return 0;
    if (isId(root1,root2))
        return 1;
    return isSubtree(root1->left,root2) || isSubtree(root1->right,root2);
}