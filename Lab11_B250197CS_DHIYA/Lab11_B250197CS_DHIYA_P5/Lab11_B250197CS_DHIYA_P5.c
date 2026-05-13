#include "Lab11_B250197CS_DHIYA_P5.h"
#include <stdio.h>

void maxHeapify(int arr[], int n, int i)
{
    int largest = i;
    int left = 2*i+1;
    int right = 2*i+2;
    if (left<n && arr[left]>arr[largest])
    largest = left;
    if (right<n && arr[right]>arr[largest])
    largest = right;
    if (largest!=i)
    {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        maxHeapify(arr,n,largest);
    }
}

void insert(int arr[], int *n, int val)
{
    int i = *n;
    arr[i] = val;
    (*n)++;
    while(i>0 && arr[(i-1)/2]<arr[i])
    {
        int temp = arr[i];
        arr[i] = arr[(i-1)/2];
        arr[(i-1)/2] = temp;
        i = (i-1)/2;
    }
}

int extractMax(int arr[], int *n)
{
    if (*n<=0)
    return -1;

    int max = arr[0];
    arr[0] = arr[*n - 1];
    (*n)--;
    maxHeapify(arr,*n,0);
    return max;
}

void display(int arr[], int n)
{
    if (n<=0)
    {
        printf("Empty\n");
        return;
    }
    for (int i = 0; i < n; i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
}

void heapSort(int arr[], int n)
{
    for (int i = n/2 - 1; i>=0; i--)
    {
        maxHeapify(arr,n,i);
    }
    for (int i = n-1; i > 0; i--)
    {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        maxHeapify(arr, i , 0);
    }
    for (int i = 0; i < n; i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
}