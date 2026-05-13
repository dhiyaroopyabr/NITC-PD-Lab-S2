#ifndef P2_H
#define P2_H

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
};

typedef struct Node* node;

node createNode(int val);
node build(char *s, int *i);
node search(node root, int x);
void display(node root, int k);

#endif