#include "Lab9_B250197CS_DHIYA_P5.h"

void Insert(struct list s[], int *f, int *r, int N, int id, char *name, char *dep)
{
    if (*f==-1 && *r==-1)
    {
        *f = *r = 0;
        s[*r].id = id;
        strcpy(s[*r].name,name);
        strcpy(s[*r].dep,dep);
    }
    else if ((*r+1)%N == *f)
    {
        printf("Full\n");
    }
    else
    {
        *r = (*r+1)%N;
        s[*r].id = id;
        strcpy(s[*r].name,name);
        strcpy(s[*r].dep,dep);
    }
}

void Delete(struct list s[], int *f, int *r, int N)
{
    if (*f==-1 && *r==-1)
    {
        printf("Empty\n");
    }
    else if (*f==*r)
    {
        printf("%d %s %s\n",s[*f].id,s[*f].name,s[*f].dep);
        *f = *r = -1;
    }
    else
    {
        printf("%d %s %s\n",s[*f].id,s[*f].name,s[*f].dep);
        *f = (*f+1)%N;
    }
}

void Display_F(struct list s[], int f, int r, int N)
{
    int i = f;

    if (f==-1 && r==-1)
    {
        printf("Empty_F\n");
    }
    else
    {
        while (i!=r)
        {
            printf("%d %s %s\n",s[i].id,s[i].name,s[i].dep);
            i = (i+1)%N;
        }

        printf("%d %s %s\n",s[r].id,s[r].name,s[r].dep);
    }
}

void Display_R(struct list s[], int f, int r, int N)
{
    int i = r;

    if (f==-1 && r==-1)
    {
        printf("Empty_R\n");
    }
    else
    {
        while (i!=f)
        {
            printf("%d %s %s\n",s[i].id,s[i].name,s[i].dep);
            i = (i-1+N)%N;
        }

        printf("%d %s %s\n",s[f].id,s[f].name,s[f].dep);
    }
}
