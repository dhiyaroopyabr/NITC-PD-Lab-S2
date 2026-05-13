#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct clist
{
    int rno;
    char name[31];
    float marks;
    struct clist* next;
};

typedef struct clist* node;

void DISPLAY(node L)
{
    if (L==NULL)
    {
        printf("-1\n");
        return;
    }
    else
    {
        node p = L;
        do {
        printf("%d %s %.2f\n", p->rno, p->name, p->marks);
        p = p->next;
    } while (p != L);
    }
}

void SEARCH(node L, int roll)
{
    if (L==NULL)
    {printf("-1\n");
    return;}
    else
    {
       node p = L;
        do {
            if (p->rno==roll)
            {   
                printf("%d %s %.2f\n", p->rno, p->name, p->marks);
                return;
            }
            p = p->next;

    } while (p != L);
    }
    printf("-1\n");
}

void INSERT_END(node *L, int roll, char* name, float marks)
{
    node temp = (node)malloc(sizeof(struct clist));
    if (temp == NULL)
    {
        exit(0);
    }
    temp->rno = roll;
    strcpy(temp->name,name);
    temp->marks = marks;
    if ((*L)==NULL)
    {
        *L = temp;
        temp->next = *L;
        return;
    }
    else
    {
        node p = *L;
        while (p->next!=*L)
        {
            p = p->next;
        }
        p->next = temp;
        temp->next = *L;
    }
}

void DELETE(node *L, int roll)
{
    node curr = *L;
    node prev = NULL;
    if (*L == NULL)
    {
        printf("-1\n");
        return;
    }
    else if (curr->next == curr)
    {
        if (curr->rno == roll)
        {
            printf("%d %s %.2f\n", curr->rno, curr->name, curr->marks);
            free(curr);
            *L = NULL;
        }
        else
        {
            printf("-1\n");
        }
        return;
    }
    else if (curr->rno == roll)
    {
        node tail = *L;

        while (tail->next != *L)
            tail = tail->next;

        printf("%d %s %.2f\n", curr->rno, curr->name, curr->marks);

        tail->next = curr->next;
        *L = curr->next;
        free(curr);
        return;
    }
    prev = curr;
    curr = curr->next;
    while (curr != *L)
    {
        if (curr->rno == roll)
        {
            printf("%d %s %.2f\n", curr->rno, curr->name, curr->marks);
            prev->next = curr->next;
            free(curr);
            return;
        }
        prev = curr;
        curr = curr->next;
    }
    printf("-1\n");
}

int main()
{
    node L = NULL;
    char c;
    int flag = 0;
    int roll;
    char name[31];
    float marks;
    while (1)
    {
        scanf(" %c",&c);
        switch(c)
        {
            case 'i':
            scanf("%d",&roll);
            scanf("%s",name);
            scanf("%f",&marks); 
            INSERT_END(&L,roll,name,marks);
            break;
            case 's':
            scanf("%d",&roll);
            SEARCH(L,roll);
            break;
            case 'd':
            scanf("%d",&roll);
            DELETE(&L,roll);
            break;
            case 'D':
            DISPLAY(L);
            break;
            case 'e':
            flag = 1;
            break;
        }
        if (flag)
        break;
    }
}