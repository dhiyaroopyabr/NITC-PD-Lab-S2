#include "Lab9_B250197CS_DHIYA_P2.h"

void Enqueue(int hosp[], int *f, int *b, int N, int id)
{
   if (isFull(*f, *b, N))
   return;
   else if (*f==-1 && *b==-1)
   {
    *f = *b = 0;
    hosp[*b] = id;
   }
   else
   {
    (*b)++;
    hosp[*b] = id;
   }
}

void dequeue(int hosp[], int *f, int *b)
{
    if (isEmpty(*f, *b))
    return;
    else if (*f==*b)
    {
        printf("%d\n",hosp[*f]);
        *f = *b = -1;
    }
    else
    {
        printf("%d\n",hosp[*f]);
        (*f)++;
    }
}

void displayQueue(int hosp[], int f, int b)
{
    if (isEmpty(f,b))
    return;
    else{
        for (int i = f; i<=b; i++)
        {
            printf("%d ",hosp[i]);
        }
        printf("\n");
    }
}

int isFull(int f, int b, int N)
{
    if (b-f+1==N)
    {
        printf("QUEUE_FULL\n");
        return 1;
    }
    else
    {
        return 0;
    }
}

int isEmpty(int f, int b)
{
    if (f==-1 && b==-1)
    {
        printf("QUEUE_EMPTY\n");
        return 1;
    }
    else
    {
        return 0;
    }
}