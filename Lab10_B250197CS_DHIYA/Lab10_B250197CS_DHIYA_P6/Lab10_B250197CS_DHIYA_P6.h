#ifndef P6_H
#define P6_H

typedef struct node {
    int data;
    struct node *left;
    struct node *right;
} *node;

node createNode(int val);
node buildTree(char *s, int *i);

int leftView(node root);
int rightView(node root);
int topView(node root);

#endif