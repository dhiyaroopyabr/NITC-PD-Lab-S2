#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "Lab10_B250197CS_DHIYA_P3.h"

//create a node...
node createNode(int val)
{
    node newNode = (node)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->left = newNode->right = NULL;
    return newNode;
}

//build ya tree...
node build(char *s, int *i)
{
    if (s[*i]==')') 
    {
        return NULL;
    }
    int num = 0;
    while (isdigit(s[*i]))
    {
        num = num*10 + (s[*i]-'0');
        (*i)++;
    }
    node root = createNode(num);
    //left child
    if (s[*i]=='(')
    {
        (*i)++;
        root->left = build(s,i);
        (*i)++;
    }
    if (s[*i]=='(')
    {
        (*i)++;
        root->right = build(s,i);
        (*i)++;
    }
    return root;
}

//postorder
void postorder(node root)
{
    if (!root) return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ",root->data);
}