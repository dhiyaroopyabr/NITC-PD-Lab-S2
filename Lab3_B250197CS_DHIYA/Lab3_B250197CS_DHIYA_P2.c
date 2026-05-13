#include <stdio.h>
#include <string.h>
#define N 50
#define L 100
void print(char s[][L], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%s\n",s[i]);
    }
}
void sort(char s[][L], int n)
{
    char key[L];

    for (int j = 1; j < n; j++)
    {
        strcpy(key,s[j]);
        int i = j-1;
        while (i>=0 && strcmp(s[i],key)>0)
        {
            strcpy(s[i+1],s[i]);
            i--;
        }
        strcpy(s[i+1],key);
    }
}
void insert(char s[][L], int *n, char name[])
{
    int i = *n - 1;
    while (i>=0 && strcmp(s[i],name)>0)
    {
        strcpy(s[i+1],s[i]);
        i--;
    }
    strcpy(s[i+1],name);
    (*n)++;
}
int main()
{
    int n;
    scanf("%d",&n);
    char s[N][L];
    for (int i = 0; i < n; i++)
    {
        scanf("%s",s[i]);
    }
    sort(s,n);
    print(s,n);
    while (n<N)
    {
        char c;
        char name[L];
        scanf(" %c",&c);
        if (c=='y')
        {
            scanf("%s",name);
            insert(s,&n,name);
            print(s,n);
        }
        else if (c=='n')
        {
            break;
        }
    }
    return 0;
}