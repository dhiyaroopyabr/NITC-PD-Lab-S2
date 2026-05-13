#ifndef P2_H
#define P2_H

struct list
{
    int data;
    struct list* left;
    struct list* right;
};

typedef struct list* node;

node createNode(int num);
node InsertKey(node root, int num);
int SearchKey(node root, int num);
node DeleteKey(node root, int num);
int kthsmallest(node root, int k, int *count);
node minimum(node root);
node maximum(node root);
node successor(node root, int num);

#endif