#include "Lab9_B250197CS_DHIYA_P2.h"

int main()
{
    int hosp[10];
    int N;
    int f = -1;
    int b = -1;
    scanf("%d",&N);
    char str[100];
    int id;
    while (1)
    {
        scanf("%s",str);

        if (strcmp("ENQUEUE",str)==0)
        {
            scanf("%d",&id);
            Enqueue(hosp,&f,&b,N,id);
        }
        else if (strcmp("DEQUEUE",str)==0)
        {
            dequeue(hosp,&f,&b);
        }
        else if (strcmp("DISPLAY_QUEUE",str)==0)
        {
            displayQueue(hosp,f,b);
        }
        else if (strcmp("IS_FULL",str)==0)
        {
            int res = isFull(f,b,N);
            if (!res)
            {
                printf("QUEUE_NOT_FULL\n");
            }
        }
        else if (strcmp("IS_EMPTY",str)==0)
        {
            int res = isEmpty(f,b);
            if (!res)
            {
                printf("QUEUE_NOT_EMPTY\n");
            }
        }
        else if (strcmp("EXIT",str)==0)
        {
            break;
        }
    }
    return 0;
}