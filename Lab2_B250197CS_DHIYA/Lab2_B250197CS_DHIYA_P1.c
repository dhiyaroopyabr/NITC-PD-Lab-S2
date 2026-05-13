#include <stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    int A[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&A[i]);
    }
    int k;
    scanf("%d",&k);
    int index = -1;
    for (int i = 0; i < n; i++)
    {
        if (A[i]==k)
        {
            index = i;
            break;
        }
    }
    printf("%d",index);
    return 0;
}