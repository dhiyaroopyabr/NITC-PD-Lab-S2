#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "Lab10_B250197CS_DHIYA_P5.h"

//create node...
node createNode(char val)
{
    node newNode = (node)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->left = newNode->right = NULL;
    return newNode;
}

//build tree from paranthesis notation...
node buildTree(char *s, int *i)
{
    if (s[*i]=='(') (*i)++;
    if (s[*i]==')')
    {
        (*i)++;
        return NULL;
    }
    node root = createNode(s[*i]);
    (*i)++;
    root->left = buildTree(s,i);
    root->right = buildTree(s,i);
    if (s[*i]==')') (*i)++;
    return root;
}

//traversals
void preorder(node root)
{
    if (!root) return;
    printf("%c",root->data);
    preorder(root->left);
    preorder(root->right);
}

void postorder(node root)
{
    if (!root) return;
    postorder(root->left);
    postorder(root->right);
    printf("%c",root->data);
}

//postfix eval...
int evalPostfix(char *exp)
{
    int st[1000], top = -1;
    for (int i = 0; exp[i]; i++)
    {
        if (isdigit(exp[i]))
        {
            st[++top] = exp[i] - '0';
        }
        else
        {
            int b = st[top--];
            int a = st[top--];
            if (exp[i]=='+') st[++top] = a+b;
            if (exp[i]=='-') st[++top] = a-b;
            if (exp[i]=='*') st[++top] = a*b;
            if (exp[i]=='/') st[++top] = a/b;
        }
    }
    return st[top];
}

//prefix eval...
int evalPrefix(char *exp)
{
    int st[1000], top=-1;
    int n = strlen(exp);
    for (int i = n-1; i>=0; i--)
    {
        if (isdigit(exp[i]))
        {
            st[++top] = exp[i] - '0';
        }
        else
        {
            int a = st[top--];
            int b = st[top--];
            if (exp[i]=='+') st[++top] = a+b;
            if (exp[i]=='-') st[++top] = a-b;
            if (exp[i]=='*') st[++top] = a*b;
            if (exp[i]=='/') st[++top] = a/b; 
        }
    }
    return st[top];
}

//searching
int find(char *in, int l, int r, char x)
{
    for (int i = l; i<=r; i++)
    {
        if (in[i]==x) return i;
    }
    return -1;
}

//build from inorder and postfix
node buildFromInPost(char *in, char *post, int l, int r, int *i)
{
    if (l>r) return NULL;
    node root = createNode(post[(*i)--]);
    int pos = find(in, l, r, root->data);
    root->right = buildFromInPost(in, post, pos+1, r, i);
    root->left = buildFromInPost(in, post, l, pos-1, i);
    return root;
}

//build from inorder and prefix
node buildFromInPre(char *in, char *pre, int l, int r, int *i)
{
    if (l>r) return NULL;
    node root = createNode(pre[(*i)++]);
    int pos = find(in,l,r,root->data);
    root->left = buildFromInPre(in, pre, l, pos-1, i);
    root->right = buildFromInPre(in, pre, pos+1, r, i);
    return root;
}

