#include <stdio.h>
struct man
{
    char name[51];
    int runs;
    int wic;
};

int check(struct man l,struct man r)
{
    if (l.runs>r.runs)
    return 1;
    else if (l.runs==r.runs && l.wic>=r.wic)
    return 1;
    else
    return 0;
}

void merge(struct man s[], int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;
    struct man l[n1];
    struct man r[n2];
    for (int i = 0; i < n1; i++)
    {
        l[i] = s[left+i];
    }
    for (int j = 0; j < n2; j++)
    {
        r[j] = s[mid+1+j];
    }
    int i = 0, j = 0, k = left;
    while (i<n1 && j<n2)
    {
        if (check(l[i],r[j]))
        {
            s[k] = l[i++];
        }
        else
        {
            s[k] = r[j++];
        }
        k++;
    }
    while (i<n1)
    {
        s[k++] = l[i++];
    }
    while (j<n2)
    {
        s[k++] = r[j++];
    }
}

void mergeSort(struct man s[], int left, int right)
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
    struct man s[100];
    int flag = 0;
    while (1)
    {
    printf("1. Enter Player Details\n");
    printf("2. Display Player List\n");
    printf("3. Sort Player Records (Merge Sort)\n");
    printf("4. Exit\n");
    int choice;
    printf("Enter your choice:\n");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:
        scanf("%d",&n);
        for (int i = 0; i < n; i++)
        {
            scanf("%s %d %d",s[i].name,&s[i].runs,&s[i].wic);
        }
        printf("Player details entered successfully.\n");
        break;
        case 2:
        for (int i = 0; i < n; i++)
        {
            printf("%s %d %d\n",s[i].name,s[i].runs,s[i].wic);
        }
        break;
        case 3:
        mergeSort(s,0,n-1);
        printf("Players sorted successfully using Merge Sort.\n");
        break;
        case 4:
        printf("Program terminated successfully.\n");
        flag = 1;
        break;
    }
    if (flag)
    break;
}
}