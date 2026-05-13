#include "Lab12_B250197CS_DHIYA_P3.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

node createNode(ll no, char* name)
{
    node temp = (node)malloc(sizeof(struct list));
    temp->no = no;
    strcpy(temp->name,name);
    temp->left = temp->right = NULL;
    return temp;
}

node insert(node root, ll no, char* name)
{
    if (root == NULL)
        return createNode(no,name);
    if (no<root->no)
        root->left = insert(root->left,no,name);
    else if (no>root->no)
        root->right = insert(root->right,no,name);
    return root;
}

node maximum(node root)
{
    if (root == NULL) return NULL;
    while (root->right!=NULL)
    {
        root = root->right;
    }
    return root;
}

node minimum(node root)
{
    if (root == NULL) return NULL;
    while (root->left!=NULL)
    {
        root = root->left;
    }
    return root;
}

// INORDER
node predecessor(node root, ll no)
{
    node pred = NULL;
    node curr = root;
    while (curr!=NULL && curr->no!=no)
    {
        if (no>curr->no)
        {
            pred = curr;
            curr = curr->right;
        }
        else
        {
            curr = curr->left;
        }
    }
    if (curr==NULL) return NULL;
    if (curr->left!=NULL) return maximum(curr->left);
    return pred;
}

node successor(node root, ll no)
{
    node succ = NULL;
    node curr = root;
    while (curr!=NULL && curr->no!=no)
    {
        if (no<curr->no)
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
    if (curr->right!=NULL)
        return minimum(curr->right);
    return succ;
}

node preorderPred(node root, ll no, node *prev)
{
    if (root == NULL) return NULL;
    if (root->no == no) return *prev;
    *prev = root;
    node left = preorderPred(root->left,no,prev);
    if (left != NULL) return left;
    return preorderPred(root->right,no,prev);
}

node preorderSucc(node root, ll no, int *found)
{
    if (root==NULL) return NULL;
    if (*found) return root;
    if (root->no == no) *found = 1;
    node left = preorderSucc(root->left,no,found);
    if (left!=NULL) return left;
    return preorderSucc(root->right,no,found);
}

node postorderPred(node root, ll no, node *prev)
{
    if (root==NULL) return NULL;
    node left = postorderPred(root->left,no,prev);
    if (left!=NULL) return left;
    node right = postorderPred(root->right,no,prev);
    if (right!=NULL) return right;
    if (root->no==no) return *prev;
    *prev = root;
    return NULL;
}

node postorderSucc(node root, ll no, int *found)
{
    if (root==NULL) return NULL;
    node left = postorderSucc(root->left,no,found);
    if (left!=NULL) return left;
    node right = postorderSucc(root->right,no,found);
    if (right!=NULL) return right;
    if (*found) return root;
    if (root->no==no) *found = 1;
    return NULL;
}