#include <stdio.h>
struct student 
{
    char name[100];
    int marks;
};
int main()
{
    int n;
    scanf("%d",&n);
    struct student s[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%s",s[i].name);
        scanf("%d",&s[i].marks);
    }
    for (int i = 0; i < n-1; i++)
    {
        int min = i;
        for (int j = i+1; j < n; j++)
        {
            if (s[j].marks < s[min].marks)
            {
                min = j;
            }
        }
        
        struct student key = s[min];
        while (min > i)
        {
            s[min] = s[min - 1];
            min--;
        }
        s[i] = key;
    }
    for (int i = 0; i < n; i++)
    {
        printf("%s %d\n",s[i].name,s[i].marks);
    } 
}