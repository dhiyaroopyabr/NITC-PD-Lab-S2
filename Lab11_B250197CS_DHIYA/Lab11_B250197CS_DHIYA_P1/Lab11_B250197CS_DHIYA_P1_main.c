#include "Lab11_B250197CS_DHIYA_P1.h"
#include <stdio.h>

int main()
{
    int N;
    scanf("%d",&N);
    struct loan s[N];
    for (int i = 0; i < N; i++)
    {
        scanf("%d %d",&s[i].cibil,&s[i].loan);
    }
    heapSort(s,N);
    for (int i = 0; i < N; i++)
    {
        printf("%d %d\n",s[i].cibil,s[i].loan);
    }
}