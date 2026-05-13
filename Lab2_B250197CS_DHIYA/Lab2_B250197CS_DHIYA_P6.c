#include <stdio.h>
int n;
int BinarySearch(int *A, int k)
{
    int st = 0;
    int end = n - 1;
    while (st<=end)
    {
        int mid = st + (end-st)/2;
        if (k < A[mid])
        end = mid - 1;
        else if (k > A[mid])
        st = mid + 1;
        else
        return mid;
    }
    return -1;
}
int main()
{
    scanf("%d",&n);
    int A[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&A[i]);
    }
    for (int i = 0; i < n-1; i++)
    {
        int l = i;
        for (int j = i; j < n; j++)
        {
            if (A[j]<A[l])
            {
                l = j;
            }
        }
        int temp = A[i];
        A[i] = A[l];
        A[l] = temp;
    }
    int k;
    scanf("%d",&k);
    printf("%d",BinarySearch(A,k));
}