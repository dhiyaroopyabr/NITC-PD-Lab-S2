#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Lab10_B250197CS_DHIYA_P4.h"

//creating node as usual
node createNode(int vno, char model[], int price)
{
    node newNode = (node)malloc(sizeof(struct Node));
    newNode->vno = vno;
    strcpy(newNode->model,model);
    newNode->price=price;
    newNode->left=newNode->right=NULL;
    return newNode;
}

//level order insert using queue
node insertLevelOrder(node root, int vno, char model[], int price)
{
    node newNode = createNode(vno, model, price);
    if (!root) return newNode;
    node queue[1000];
    int f=0, r=0;
    queue[r++] = root;
    while (f<r)
    {
        node temp = queue[f++];
        if (!temp->left)
        {
            temp->left = newNode;
            return root;
        }
        else
        {
            queue[r++] = temp->left;
        }
        if (!temp->right)
        {
            temp->right = newNode;
            return root;
        }
        else
        {
            queue[r++] = temp->right;
        }
    }
    return root;
}

//traversals...
void inorder(node root)
{
    if (!root) return;
    inorder(root->left);
    printf("%d %s %d\n",root->vno, root->model, root->price);
    inorder(root->right);
}

void preorder(node root)
{
    if (!root) return;
    printf("%d %s %d\n",root->vno, root->model, root->price);
    preorder(root->left);
    preorder(root->right);
}

void postorder(node root)
{
    if (!root) return;
    postorder(root->left);
    postorder(root->right);
    printf("%d %s %d\n", root->vno, root->model, root->price);
}

//level order printing
void levelOrder(node root)
{
    if (!root) return;
    node queue[1000];
    int f = 0, r = 0;
    queue[r++] = root;
    while (f<r)
    {
        node temp = queue[f++];
        printf("%d %s %d\n", temp->vno, temp->model, temp->price);
        if (temp->left) queue[r++] = temp->left;
        if (temp->right) queue[r++] = temp->right;
    }
}

//search...
node search(node root, int vno)
{
    if (!root) return NULL;
    if (root->vno==vno) return root;
    node left = search (root->left, vno);
    if (left) return left;
    return search(root->right, vno);
}

