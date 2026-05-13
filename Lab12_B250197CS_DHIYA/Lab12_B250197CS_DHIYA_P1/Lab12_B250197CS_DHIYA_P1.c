#include "Lab12_B250197CS_DHIYA_P1.h"
#include <stdio.h>
#include <stdlib.h>

node createNode(int num)
{
    node temp = (node)malloc(sizeof(struct list));
    temp->data = num;
    temp->left = temp->right = NULL;
    return temp;
}

node InsertKey(node root, int num)
{
    //Base Case: we have found an empty position to insert num
    if (root==NULL)
        return createNode(num);
    if (num<root->data)
        root->left = InsertKey(root->left,num);
    else if (num>root->data)
        root->right = InsertKey(root->right,num);
    return root;
}

int SearchKey(node root, int num)
{
    if (root==NULL) return 0;
    if (num == root->data) return 1;
    if (num<root->data)
        return SearchKey(root->left,num);
    else
        return SearchKey(root->right,num);
}

node min(node root)
{
    while (root->left!=NULL)
    {
        root = root->left;
    }
    return root;
}

node DeleteKey(node root, int num)
{
    if (root==NULL)
    {
        printf("NOT PRESENT\n");
        return NULL;
    }
    if (num<root->data)
    {
        root->left = DeleteKey(root->left,num);
    }
    else if (num>root->data)
    {
        root->right = DeleteKey(root->right,num);
    }
    else
    {
        //reached here mean both of those condns not true, ie, we found num
        //Cases 1 and 2: zero and one child
        if (root->left==NULL)
        {
            node temp = root->right;
            free(root);
            return temp;
        }
        if (root->right==NULL)
        {
            node temp = root->left;
            free(root);
            return temp;
        }
        //Case 3: two children
        node successor = min(root->right);
        root->data = successor->data;
        root->right = DeleteKey(root->right,successor->data);
    }
}

void inorder(node root)
{
    if (root == NULL)
    return;
    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);
}

void preorder(node root)
{
    if (root == NULL)
    return;
    printf("%d ",root->data);
    preorder(root->left);
    preorder(root->right);
}

void postorder(node root)
{
    if (root == NULL)
    return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ",root->data);
}