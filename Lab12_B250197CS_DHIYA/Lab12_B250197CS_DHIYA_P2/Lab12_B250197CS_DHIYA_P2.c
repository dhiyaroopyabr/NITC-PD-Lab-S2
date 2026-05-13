#include "Lab12_B250197CS_DHIYA_P2.h"
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
    if (root == NULL)
        return createNode(num);
    if (num<root->data)
        root->left = InsertKey(root->left,num);
    else if (num>root->data)
        root->right = InsertKey(root->right,num);
    return root;
}

int SearchKey(node root, int num)
{
    if (root == NULL) return 0;
    if (num == root->data) return 1;
    if (num<root->data)
        return SearchKey(root->left,num);
    else
        return SearchKey(root->right,num);
}

node minimum(node root)
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
        node successor = minimum(root->right);
        root->data = successor->data;
        root->right = DeleteKey(root->right, successor->data);
    }
    return root;
}

node maximum(node root)
{
    while (root->right!=NULL)
    {
        root = root->right;
    }
    return root;
}

node successor(node root, int num)
{
    node succ = NULL;
    node curr = root;
    // step 1 : navigate to the node while tracking possible ancestors
    while (curr!=NULL && curr->data!=num)
    {
        if (num<curr->data)
        {
            succ = curr;
            curr = curr->left;
        }
        else
        {
            curr = curr->right;
        }
    }
    if (curr==NULL) return NULL;
    // Step 2 -- right subtree exists
    if (curr->right!=NULL)
        return minimum(curr->right);
    // Step 3 -- if right subtree dont exist, use the ancestor we tracked
    return succ;
}

int kthsmallest(node root, int k, int *count)
{
    if (root==NULL) return -1;
    //Left subtree
    int left = kthsmallest(root->left,k,count);
    if (left!=-1) return left;
    //visit current node
    (*count)++;
    if (*count==k)
        return root->data;
    //right subtree
    return kthsmallest(root->right,k,count);
}