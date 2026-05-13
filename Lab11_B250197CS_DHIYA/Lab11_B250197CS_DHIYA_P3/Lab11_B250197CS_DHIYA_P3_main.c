#include "Lab11_B250197CS_DHIYA_P3.h"
#include <stdio.h>
#include <string.h>

int main()
{
    int N;
    scanf("%d",&N);
    int n = 0;
    struct ticket s[1000];
    int timer = 0;
    for (int i = 0; i < N; i++)
    {
        char str[100];
        scanf("%s",str);
        if (strcmp(str,"RAISE")==0)
        {
            int id, prio;
            scanf("%d %d",&id,&prio);
            struct ticket snew;
            snew.id = id;
            snew.prio = prio;
            snew.time = timer++;
            insert(s,&n,snew);
        }
        else if (strcmp(str,"RESOLVE")==0)
        {
            printf("%d\n",extractMax(s,&n));
        }
        else if (strcmp(str,"SHOW")==0)
        {
            display(s,n);
        }
    }
}