#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "Lab10_B250197CS_DHIYA_P6.h"

// create node
node createNode(int val) {
    node n = (node)malloc(sizeof(*n));
    n->data = val;
    n->left = n->right = NULL;
    return n;
}

// build tree (same as Q3)
node buildTree(char *s, int *i) {
    if (s[*i] == '(') (*i)++;

    if (s[*i] == ')') {
        (*i)++;
        return NULL;
    }

    int num = 0;
    while (isdigit(s[*i])) {
        num = num * 10 + (s[*i] - '0');
        (*i)++;
    }

    node root = createNode(num);

    root->left = buildTree(s, i);
    root->right = buildTree(s, i);

    if (s[*i] == ')') (*i)++;

    return root;
}

// LEFT VIEW
int leftView(node root) {
    if (!root) return 0;

    node q[1000];
    int f = 0, r = 0;
    int count = 0;

    q[r++] = root;

    while (f < r) {
        int size = r - f;

        for (int i = 0; i < size; i++) {
            node temp = q[f++];

            if (i == 0) {
                printf("%d ", temp->data);
                count++;
            }

            if (temp->left) q[r++] = temp->left;
            if (temp->right) q[r++] = temp->right;
        }
    }
    return count;
}

// RIGHT VIEW
int rightView(node root) {
    if (!root) return 0;

    node q[1000];
    int f = 0, r = 0;
    int count = 0;

    q[r++] = root;

    while (f < r) {
        int size = r - f;

        for (int i = 0; i < size; i++) {
            node temp = q[f++];

            if (i == size - 1) {
                printf("%d ", temp->data);
                count++;
            }

            if (temp->left) q[r++] = temp->left;
            if (temp->right) q[r++] = temp->right;
        }
    }
    return count;
}

// TOP VIEW
int topView(node root) {
    if (!root) return 0;

    int vis[2000] = {0};
    int val[2000];

    node q[1000];
    int hd[1000];

    int f = 0, r = 0;
    int count = 0;

    q[r] = root;
    hd[r++] = 1000;

    int min = 1000, max = 1000;

    while (f < r) {
        node temp = q[f];
        int d = hd[f++];
        
        if (!vis[d]) {
            vis[d] = 1;
            val[d] = temp->data;
            count++;
        }

        if (temp->left) {
            q[r] = temp->left;
            hd[r++] = d - 1;
            if (d - 1 < min) min = d - 1;
        }

        if (temp->right) {
            q[r] = temp->right;
            hd[r++] = d + 1;
            if (d + 1 > max) max = d + 1;
        }
    }

    for (int i = min; i <= max; i++) {
        if (vis[i]) printf("%d ", val[i]);
    }

    return count;
}