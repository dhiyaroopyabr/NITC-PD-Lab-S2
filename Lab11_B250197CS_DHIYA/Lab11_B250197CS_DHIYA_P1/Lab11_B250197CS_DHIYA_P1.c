#include "Lab11_B250197CS_DHIYA_P1.h"
#include <stdio.h>

void minHeapify(struct loan s[], int n, int i)
{
    int smallest = i;
    int left = 2*i+1;
    int right = 2*i+2;
    if (left<n && (s[left].cibil<s[smallest].cibil || (s[left].cibil==s[smallest].cibil && s[left].loan<s[smallest].loan)))
    smallest = left;
    if (right<n && (s[right].cibil<s[smallest].cibil || (s[right].cibil==s[smallest].cibil && s[right].loan<s[smallest].loan)))
    smallest = right;
    if (smallest!=i)
    {
        struct loan temp = s[i];
        s[i] = s[smallest];
        s[smallest] = temp;

        minHeapify(s,n,smallest);
    }
}

void buildMinHeap(struct loan s[], int n)
{
    for (int i = n/2 - 1; i>=0; i--)
    {
        minHeapify(s,n,i);
    }
}

void heapSort(struct loan s[], int n)
{
    buildMinHeap(s,n);
    for (int i = n-1; i>0; i--)
    {
        struct loan temp = s[0];
        s[0] = s[i];
        s[i] = temp;
        minHeapify(s,i,0);
    }
}
