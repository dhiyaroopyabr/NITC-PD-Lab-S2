#include <stdio.h>
#include <string.h>
struct atc
{
    char name[7];
    int h;
    char colon;
    int m;
};

void swap(struct atc *a, struct atc *b)
{
    struct atc temp = *a;
    *a = *b;
    *b = temp;
}

int partition(struct atc s[], int st, int end)
{
    struct atc pivot = s[end];
    int idx = st-1;
    for (int i = st; i < end; i++)
    {
        if (s[i].h<pivot.h || s[i].h==pivot.h && s[i].m<pivot.m)
        {
            swap(&s[i],&s[++idx]);
        }
    }
    swap(&s[++idx],&s[end]);
    return idx;
}

void quickSort(struct atc s[], int st, int end)
{
    if (st<end)
    {
        int pivInd = partition(s,st,end);
        quickSort(s,st,pivInd-1);
        quickSort(s,pivInd+1,end);
    }
}

int main()
{
    int n;
    scanf("%d",&n);
    struct atc s[n];
    struct atc o[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%s %d %c %d",s[i].name,&s[i].h,&s[i].colon,&s[i].m);
        o[i] = s[i];
    }
    quickSort(s,0,n-1);
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (strcmp(s[i].name,o[i].name)==0 && s[i].h==o[i].h && s[i].m==o[i].m)
        {
            count++;
        }
    }
    for (int i = 0; i < n; i++)
    {
        printf("%s %02d%c%02d\n",s[i].name,s[i].h,s[i].colon,s[i].m);
    }
    printf("%d\n",count);
}