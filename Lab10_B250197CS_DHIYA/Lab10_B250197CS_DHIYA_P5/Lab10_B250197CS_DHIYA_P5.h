#ifndef P5_H
#define P5_H
struct Node
{
    char data;
    struct Node* left;
    struct Node* right;
};

typedef struct Node* node;

node createNode(char val);
node buildTree(char *s, int *i);
void preorder(node root);
void postorder(node root);

int evalPostfix(char *exp);
int evalPrefix(char *exp);

node buildFromInPost(char *in, char *post, int l, int r, int *i);
node buildFromInPre(char *in, char *pre, int l, int r, int *i);

#endif
