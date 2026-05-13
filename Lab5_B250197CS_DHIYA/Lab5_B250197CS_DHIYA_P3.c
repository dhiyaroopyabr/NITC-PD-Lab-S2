#include <stdio.h>
struct infus
{
    char name[31];
    int foll;
    int er;
    int posts;
};

int check(struct infus l, struct infus r)
{
    if (l.foll>r.foll)
    return 1;
    else if (l.foll==r.foll && l.er>r.er)
    return 1;
    else if (l.foll==r.foll && l.er==r.er && l.posts<=r.posts)
    return 1;
    else
    return 0;
}

void merge(struct infus s[], int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;
    struct infus L[n1], R[n2];
    for (int i = 0; i < n1; i++)
    {
        L[i] = s[left+i];
    }
    for (int j = 0; j < n2; j++)
    {
        R[j] = s[mid+1+j];
    }
    int i = 0, j = 0, k = left;
    while (i<n1 && j<n2)
    {
        if (check(L[i],R[j]))
        {
            s[k] = L[i++];
        }
        else
        {
            s[k] = R[j++];
        }
        k++;
    }
    while (i<n1)
    {
        s[k++] = L[i++];
    }
    while (j<n2)
    {
        s[k++] = R[j++];
    }
}

void mergeSort(struct infus s[], int left, int right)
{
    if (left<right)
    {
        int mid = left + (right - left)/2;
        mergeSort(s,left,mid);
        mergeSort(s,mid+1,right);
        merge(s,left,mid,right);
    }
}

int main()
{
    int n;
    scanf("%d",&n);
    struct infus s[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%s %d %d %d",s[i].name,&s[i].foll,&s[i].er,&s[i].posts);
    }
    mergeSort(s,0,n-1);
    for (int i = 0; i < n; i++)
    {
        printf("%s %d %d %d\n",s[i].name,s[i].foll,s[i].er,s[i].posts);
    }
}