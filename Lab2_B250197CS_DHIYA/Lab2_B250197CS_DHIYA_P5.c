#include <stdio.h>
#include <string.h>
int main()
{
    int n;
    scanf("%d",&n);
    struct student
    {
        char str[100];
        int marks;
    }s[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%s",s[i].str);
        scanf("%d",&s[i].marks);
    }
    char key[100];
    scanf("%s",key);
    for (int i = 0; i < n; i++)
    {
        if(strcmp(s[i].str,key)==0)
        {
            printf("%d",s[i].marks);
            break;
        }
    }
}