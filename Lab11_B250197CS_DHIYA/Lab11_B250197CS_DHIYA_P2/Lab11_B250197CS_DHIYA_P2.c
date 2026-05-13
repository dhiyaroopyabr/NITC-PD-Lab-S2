#include "Lab11_B250197CS_DHIYA_P2.h"
#include <stdio.h>

int check(struct infus a, struct infus b)
{
    if (a.foll<b.foll)
    return 1;
    else if (a.foll==b.foll && a.er<b.er)
    return 1;
    else if (a.foll==b.foll && a.er==b.er && a.posts>b.posts)
    return 1;
    else
    return 0;
}

void minHeapify(struct infus s[], int n, int i)
{
    int smallest = i;
    int left = 2*i+1;
    int right = 2*i+2;
    if (left<n && check(s[left],s[smallest]))
    smallest = left;
    if (right<n && check(s[right],s[smallest]))
    smallest = right;
    if (smallest!=i)
    {
        struct infus temp = s[i];
        s[i] = s[smallest];
        s[smallest] = temp;
        minHeapify(s,n,smallest);
    }
}

void buildMinHeap(struct infus s[], int n)
{
    for (int i = n/2 - 1; i>=0; i--)
    {
        minHeapify(s,n,i);
    }
}

void heapSort(struct infus s[], int n)
{
    buildMinHeap(s,n);
    for (int i = n-1; i>0; i--)
    {
        struct infus temp = s[0];
        s[0] = s[i];
        s[i] = temp;
        minHeapify(s,i,0);
    }
}