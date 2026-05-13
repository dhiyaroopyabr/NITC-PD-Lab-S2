#ifndef P3_H
#define P3_H

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
};

typedef struct Node* node;

node createNode(int val);
node build(char *s, int *i);
void postorder(node root);

#endif