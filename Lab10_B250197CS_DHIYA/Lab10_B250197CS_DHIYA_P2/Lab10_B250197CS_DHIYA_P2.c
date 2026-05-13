#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "Lab10_B250197CS_DHIYA_P2.h"

//we r creating node
node createNode(int val)
{
    node newNode = (node)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->left = newNode->right = NULL;
    return newNode;
}

//build the tree
node build(char *s, int *i)
{
    if (s[*i]=='(') (*i)++;

    if (s[*i]==')') 
    {
        (*i)++;
        return NULL;
    }

    int num = 0;
    while (isdigit(s[*i]))
    {
        num = num*10 + (s[*i]-'0');
        (*i)++;
    }

    node root = createNode(num);

    root->left = build(s,i);
    root->right = build(s,i);
    if (s[*i]==')')(*i)++;
    return root;
}

//search the req node
node search(node root, int x)
{
    if (!root) return NULL;
    if (root->data==x) return root;
    node left = search(root->left, x);
    if (left) return left;
    return search(root->right, x);
}

//print nodes at depth k
void display(node root, int k)
{
    if (!root) return;
    if (k==0)
    {
        printf("%d ",root->data);
        return;
    }
    display(root->left,k-1);
    display(root->right,k-1);
}