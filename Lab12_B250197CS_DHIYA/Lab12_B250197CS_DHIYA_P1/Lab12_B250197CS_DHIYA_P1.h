#ifndef P1_H
#define P1_H

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
node min(node root);
node DeleteKey(node root, int num);
void inorder(node root);
void preorder(node root);
void postorder(node root);

#endif