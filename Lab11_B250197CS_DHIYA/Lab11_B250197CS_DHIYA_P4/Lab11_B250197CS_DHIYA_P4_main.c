#include "Lab11_B250197CS_DHIYA_P4.h"
#include <stdio.h>
#include <string.h>

int main()
{
    int N;
    scanf("%d",&N);
    struct hosp s[1000];
    int n = 0;
    int timer = 0;
    for (int i = 0; i < N; i++)
    {
        char str[100];
        scanf("%s",str);
        if (strcmp(str,"ADD")==0)
        {
            char name[31];
            int level;
            scanf("%s %d",name,&level);
            struct hosp snew;
            strcpy(snew.name,name);
            snew.level = level;
            snew.time = timer++;
            insert(s,&n,snew);
        }
        else if (strcmp(str,"TREAT")==0)
        {
            extractMax(s,&n);
        }
        else if (strcmp(str,"DISPLAY")==0)
        {
            display(s,n);
        }
    }
}