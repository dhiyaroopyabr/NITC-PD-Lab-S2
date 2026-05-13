#include <stdio.h>
#include <string.h>
struct student
{
    int rollno;
    char name[21];
    float cgpa;
};
void print(struct student *s, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d %s %.1f\n",s[i].rollno,s[i].name,s[i].cgpa);
    }
}
void insert(struct student *s, int n, char choice)
{
    if (choice=='a')
    {
        for (int j = 1; j < n; j++)
        {
            struct student key = s[j];
            int i = j-1;
            while (i >= 0 && s[i].rollno>key.rollno)
            {
                s[i+1] = s[i];
                i--;
            }
            s[i+1] = key;
        }
    }
    else if (choice=='c')
    {
        for (int j = 1; j < n; j++)
        {
            struct student key = s[j];
            int i = j-1;
            while (i >= 0 && s[i].cgpa>key.cgpa)
            {
                s[i+1] = s[i];
                i--;
            }
            s[i+1] = key;
        }
    }
    else
    {
        for (int j = 1; j < n; j++)
        {
            struct student key = s[j];
            int i = j - 1;
            while (i >= 0 && strcmp(s[i].name, key.name) > 0)
                {
                    s[i + 1] = s[i];
                    i--;
                }
            s[i + 1] = key;
        }   
    }
}
void select(struct student *s, int n, char choice)
{
    if (choice=='a')
    {
        for (int i = 0; i < n; i++)
        {
            int min = i;
            for (int j = i+1; j < n; j++)
            {
                if (s[j].rollno<s[min].rollno)
                {
                    min = j;
                }
            }
            struct student temp = s[i];
            s[i] = s[min];
            s[min] = temp;
        }
    }
    else if (choice=='c')
    {
        for (int i = 0; i < n; i++)
        {
            int min = i;
            for (int j = i+1; j < n; j++)
            {
                if (s[j].cgpa<s[min].cgpa)
                {
                    min = j;
                }
            }
            struct student temp = s[i];
            s[i] = s[min];
            s[min] = temp;
        }
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            int min = i; 
            for (int j = i+1; j < n; j++)
            {
                if (strcmp(s[j].name,s[min].name)<0)
                {
                    min = j;
                }
            }
            struct student temp = s[i];
            s[i] = s[min];
            s[min] = temp;
        }
    }
}
int main()
{
    int n;
    scanf("%d",&n);
    struct student s[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&s[i].rollno);
        scanf("%s",s[i].name);
        scanf("%f",&s[i].cgpa);
    }
    while (1)
    {
        char c,choice;
        scanf(" %c",&c);
        
        if (c=='i')
        {
            scanf(" %c",&choice);
            insert(s,n,choice);
            print(s,n);
        }

        else if (c=='s')
        {
            scanf(" %c",&choice);
            select(s,n,choice);
            print(s,n);
        }
        
        else if (c=='e')
        {
            break;
        }
    }
    return 0;
}