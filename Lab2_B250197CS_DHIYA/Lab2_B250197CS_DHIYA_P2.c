#include <stdio.h>
int n;

int LinearSearch(int *A, int k)
{
    int index = -1;
    for (int i = 0; i < n; i++)
    {
        if (A[i]==k)
        {
            index = i;
            break;
        }
    }
    return index;
}
int main()
{
    scanf("%d",&n);
    int A[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&A[i]);
    }
    int k;
    scanf("%d",&k);
    printf("%d",LinearSearch(A,k));
    return 0;
}