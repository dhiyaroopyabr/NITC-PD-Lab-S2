#include "Lab11_B250197CS_DHIYA_P5.h"
#include <stdio.h>

int main()
{
    int arr[1000];
    int n = 0;
    char ch;
    while (1)
    {
        scanf(" %c",&ch);
        if (ch=='I')
        {
            int x;
            scanf("%d",&x);
            insert(arr,&n,x);
        }
        else if (ch=='D')
        {
            int res = extractMax(arr,&n);
            if (res==-1)
            {
                printf("Empty\n");
            }
            else
            {
                printf("%d\n",res);
            }
        }
        else if (ch=='P')
        {
            display(arr,n);
        }
        else if (ch=='S')
        {
            int n;
            scanf("%d",&n);
            int arr2[n];
            for (int i = 0; i < n; i++)
            {
                scanf("%d",&arr2[i]);
            }
            heapSort(arr2,n);
        }
        else if (ch=='E')
        {
            break;
        }
        else
        {
            printf("Invalid\n");
        }
    }
}