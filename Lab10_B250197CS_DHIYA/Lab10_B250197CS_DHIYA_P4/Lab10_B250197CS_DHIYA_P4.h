#ifndef P4_H
#define P4_H

struct Node
{
    int vno;
    char model[31];
    int price;
    struct Node *left;
    struct Node *right;
};

typedef struct Node* node;

node createNode(int vno, char model[], int price);
node insertLevelOrder(node root, int vno, char model[], int price);

void inorder(node root);
void preorder(node root);
void postorder(node root);
void levelOrder(node root);

node search(node root, int vno);

#endif