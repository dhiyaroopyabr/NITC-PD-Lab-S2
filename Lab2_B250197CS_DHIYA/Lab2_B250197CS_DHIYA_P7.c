#include <stdio.h>
int n;
int count;
int BinarySearch(int *A,int k,int low,int high)
{
    if (low > high)
        return -1;
    
    int mid = low + (high - low)/2;
    count++;
    if (A[mid]>k)
        return BinarySearch(A,k,low,mid-1);
    else if (A[mid]<k)
        return BinarySearch(A,k,mid+1,high);
    else
        return mid;
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
    for (int i = 0; i < n; i++)
    {
        count = 0;
        int pos = BinarySearch(A,A[i],0,n-1);
        printf("Element %d found at position %d, Comparisons = %d\n",A[i],pos,count);
    }
    int k;
    scanf("%d",&k);

    count = 0;
    int pos = BinarySearch(A,k,0,n-1);
    if (pos == -1)
    printf("Element %d not found, Comparisons = %d\n",k,count);
    else
    printf("Element %d found at position %d, Comparisons = %d\n",k,pos,count);
}