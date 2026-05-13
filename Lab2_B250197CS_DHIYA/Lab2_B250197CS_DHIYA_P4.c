#include <stdio.h>
#include <string.h>
#define N 100
int n;
int count(char A[][N], char *s)
{
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (strcmp(A[i],s)==0)
        {
            count++;
        }
    }
    return count;
}
int main()
{
    scanf("%d",&n);
    char A[100][N];
    for (int i = 0; i < n; i++)
    {
        scanf("%s",A[i]);
    }
    char s[100];
    scanf("%s",s);
    printf("%d",count(A,s));
}