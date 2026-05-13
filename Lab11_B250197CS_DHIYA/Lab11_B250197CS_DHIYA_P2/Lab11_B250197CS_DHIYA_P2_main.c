#include "Lab11_B250197CS_DHIYA_P2.h"
#include <stdio.h>

int main()
{
    int n;
    scanf("%d",&n);
    struct infus s[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%s %d %d %d",s[i].name,&s[i].foll,&s[i].er,&s[i].posts);
    }
    heapSort(s,n);
    for (int i = 0; i < n; i++)
    {
        printf("%s %d %d %d\n",s[i].name,s[i].foll,s[i].er,s[i].posts);
    }
}