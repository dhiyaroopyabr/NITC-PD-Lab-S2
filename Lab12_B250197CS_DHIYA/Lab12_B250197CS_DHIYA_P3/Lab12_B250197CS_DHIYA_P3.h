#ifndef P3_H
#define P3_H

typedef long long ll;

struct list
{
    ll no;
    char name[51];
    struct list* left;
    struct list* right;
};

typedef struct list* node;

node createNode(ll no, char* name);
node insert(node root, ll no, char *name);
node maximum(node root);
node minimum(node root);
node predecessor(node root, ll no);
node successor(node root, ll no);
node preorderPred(node root, ll no, node *prev);
node preorderSucc(node root, ll no, int *found);
node postorderPred(node root, ll no, node *prev);
node postorderSucc(node root, ll no, int *found);

#endif