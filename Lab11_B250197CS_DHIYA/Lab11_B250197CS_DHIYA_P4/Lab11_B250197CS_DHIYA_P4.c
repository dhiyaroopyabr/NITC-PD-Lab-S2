#include "Lab11_B250197CS_DHIYA_P4.h"
#include <stdio.h>
#include <string.h>

int check(struct hosp a, struct hosp b)
{
    if (a.level>b.level)
    return 1;
    else if (a.level==b.level && a.time<b.time)
    return 1;
    else
    return 0;
}

void maxHeapify(struct hosp s[], int n, int i)
{
    int largest = i;
    int left = 2*i+1;
    int right = 2*i+2;
    if (left<n && check(s[left],s[largest]))
    largest = left;
    if (right<n && check(s[right],s[largest]))
    largest = right;
    if (largest!=i)
    {
        struct hosp temp = s[i];
        s[i] = s[largest];
        s[largest] = temp;
        maxHeapify(s,n,largest);
    }
}

void insert(struct hosp s[], int *n, struct hosp snew)
{
    s[*n] = snew;
    int i = *n;
    (*n)++;
    while (i>0 && check(s[i],s[(i-1)/2]))
    {
        struct hosp temp = s[i];
        s[i] = s[(i-1)/2];
        s[(i-1)/2] = temp;
        i = (i-1)/2;
    }
}

void extractMax(struct hosp s[], int *n)
{
    if (*n<=0) 
    {
        printf("Empty\n");
    }
    char max[31];
    strcpy(max,s[0].name);
    s[0] = s[*n-1];
    (*n)--;
    maxHeapify(s,*n,0);
    printf("%s\n",max);
}

void display(struct hosp s[], int n)
{
    struct hosp temp[1000];
    int tempSize = n;
    for (int i = 0; i < n; i++)
        temp[i] = s[i];
    while (tempSize > 0)
    {
        printf("%s %d\n", temp[0].name, temp[0].level);
        temp[0] = temp[tempSize - 1];
        tempSize--;
        maxHeapify(temp, tempSize, 0);
    }
}