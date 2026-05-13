#include "Lab11_B250197CS_DHIYA_P3.h"
#include <stdio.h>
#include <string.h>

int check(struct ticket a, struct ticket b)
{
    if (a.prio>b.prio)
    return 1;
    else if (a.prio==b.prio && a.time<b.time)
    return 1;
    else 
    return 0;
}

void maxHeapify(struct ticket s[], int n, int i)
{
    int largest = i;
    int left = 2*i+1;
    int right = 2*i+2;
    if (left<n && check(s[left],s[largest]))
    largest = left;
    if (right<n && check(s[left],s[largest]))
    largest = right;
    if (largest!=i)
    {
        struct ticket temp = s[i];
        s[i] = s[largest];
        s[largest] = temp;
        maxHeapify(s,n,largest);
    }
}

void insert(struct ticket s[], int *n, struct ticket snew)
{
    s[*n] = snew;
    int i = *n;
    (*n)++;
    while (i>0 && s[(i-1)/2].prio<s[i].prio)
    {
        struct ticket temp = s[i];
        s[i] = s[(i-1)/2];
        s[(i-1)/2] = temp;
        i = (i-1)/2;
    }
}

int extractMax(struct ticket s[], int *n)
{
    if (*n<=0) return -1;
    int max = s[0].id;
    s[0] = s[*n-1];
    (*n)--;
    maxHeapify(s,*n,0);
    return max;
}

void display(struct ticket s[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d %d\n",s[i].id,s[i].prio);
    }
}