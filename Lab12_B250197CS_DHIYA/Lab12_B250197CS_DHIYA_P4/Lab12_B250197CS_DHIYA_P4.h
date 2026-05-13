#ifndef P4_H
#define P4_H
#include <stdio.h>

struct list
{
    int data;
    struct list *left;
    struct list *right;
};

typedef struct list* node;

node createNode(int data);
node insert(node root, int data);
int isId(node root1, node root2);
int isSubtree(node root1, node root2);

#endif