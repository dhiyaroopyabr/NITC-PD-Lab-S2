#include <stdio.h>
#include <string.h>
#include <ctype.h>

void trim(char *old, char *new)
{
    int low = 0;
    int high = strlen(old)-1;
    while (old[low]==' ')
    {
        low++;
    }
    while (high>=low && old[high]==' ')
    {
        high--;
    }
    int k = 0;  
    for (int i = low; i <= high; i++)
    {
        new[k++] = old[i];
    }
    new[k] = '\0';
}

int comp(char *a, char *b)
{
    char ta[101], tb[101];
    trim(a,ta);
    trim(b,tb);
    if (ta[0]=='\0'&& tb[0]=='\0')
    {
        return 0;
    }
    if (ta[0]=='\0')
    {
        return -1;
    }
    if (tb[0]=='\0')
    {
        return 1;
    }
    int i = 0;
    while (ta[i]&&tb[i])
    {
        char ca = tolower(ta[i]);
        char cb = tolower(tb[i]);
        if (ca!=cb)
        {
            return ca-cb;
        }
        i++;
    }
    return strcmp(ta,tb);
}

void swap(char *a, char *b)
{
    char temp[101];
    strcpy(temp,a);
    strcpy(a,b);
    strcpy(b,temp);
}

int partition(char b[][101], int st, int end)
{
    char pivot[101];
    strcpy(pivot,b[end]);
    int idx = st - 1;
    for (int i = st; i < end; i++)
    {
        if (comp(b[i],pivot)<0)
        {
            swap(b[i],b[++idx]);
        }
    }
    swap(b[++idx],b[end]);
    return idx;
}

void quickSort(char b[][101], int st, int end)
{
    if (st<end)
    {
        int pivInd = partition(b,st,end);
        quickSort(b,st,pivInd-1);
        quickSort(b,pivInd+1,end);
    }
}

int main()
{
    int n;
    scanf("%d",&n);
    char b[n][101];
    for (int i = 0; i < n; i++)
    {
        scanf(" %[^\n]",b[i]);
    }
    quickSort(b,0,n-1);
    for (int i = 0; i < n; i++)
    {
        printf("%s\n",b[i]);
    }
}