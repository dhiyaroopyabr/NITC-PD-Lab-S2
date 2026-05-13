#include <stdio.h>
#include <stdlib.h>

struct list
{
    int key;
    struct list *next;
};

typedef struct list *node;

node CREATE_NODE(int k)
{
    node temp = (node)malloc(sizeof(struct list));
    if (temp==NULL)
    {
        exit(0);
    }
    temp->key = k;
    temp->next = NULL;
    return temp;
}

void LIST_INSERT_FRONT(node *L, node x)
{
    x->next = *L;
    *L = x;
}

void LIST_INSERT_TAIL(node *L, node x)
{
    if (*L==NULL)
    {
        *L = x;
    }
    else
    {
        node p;
        p = *L;
        while (p->next!=NULL)
        {
            p = p->next;
        }
        p->next = x;
    }
}

void LIST_INSERT_AFTER(node *L, node x, node y)
{
   if (y == NULL) return;

    x->next = y->next;
    y->next = x;
}

void LIST_INSERT_BEFORE(node *L, node x, node y)
{
    if (*L==y)
    {
        x->next = y;
        *L = x;
        return;
    }
    node p;
    p = *L;
    while (p->next!=NULL && p->next!=y)
    {
        p = p->next;
    }
    if (p->next==y)
    {
        x->next = y;
        p->next = x;
    }
}

void LIST_DELETE(node *L, node x)
{
    if (*L == NULL || x == NULL)
    {
        printf("1\n");
        return;
    }
    if (*L == x)
    {
        node temp = *L;
        printf("%d\n",temp->key);
        *L = temp->next;
        free(temp);
        return;
    }
    node p = *L;
    while (p->next!=NULL && p->next!=x)
    {
        p = p->next;
    }
    if (p->next == x)
    {
        printf("%d\n",x->key);
        p->next = x->next;
        free(x);
    }
}

void LIST_DELETE_FIRST(node *L)
{
    if (*L == NULL)
{
    printf("1\n");
    return;
}
    node temp = *L;           
    printf("%d\n", temp->key);
    *L = temp->next;          
    free(temp);
}

void LIST_DELETE_LAST(node *L)
{
    if (*L == NULL)
{
    printf("1\n");
    return;
}
    if ((*L)->next == NULL)
    {
        printf("%d\n", (*L)->key);
        free(*L);
        *L = NULL;
        return;
    }
    node p = *L;
    while (p->next->next != NULL)
    {
        p = p->next;
    }
    node temp = p->next;    
    printf("%d\n", temp->key);
    free(temp);
    p->next = NULL;
}

node LIST_SEARCH(node L, int k)
{
    node temp = L;
    while (temp!=NULL)
    {
        if (temp->key==k)
        {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

int main()
{
    int flag = 0;
    node L = NULL;
    while (1)
    {
        char c;
        scanf(" %c",&c);
        int k, sk;
        node x, y;
        switch(c)
        {
            case 'f':
            scanf("%d",&k);
            x = CREATE_NODE(k);
            LIST_INSERT_FRONT(&L,x);
            break;
            case 't':
            scanf("%d",&k);
            x = CREATE_NODE(k);
            LIST_INSERT_TAIL(&L,x);
            break;
            case 'b':
            scanf("%d %d",&k,&sk);
            x = CREATE_NODE(k);
            y = LIST_SEARCH(L,sk);
            LIST_INSERT_BEFORE(&L,x,y);
            break;
            case 'a':
            scanf("%d %d",&k,&sk);
            x = CREATE_NODE(k);
            y = LIST_SEARCH(L,sk);
            LIST_INSERT_AFTER(&L,x,y);
            break;
            case 'd':
            scanf("%d",&k);
            x = LIST_SEARCH(L,k);
            LIST_DELETE(&L,x);
            break;
            case 'i':
            LIST_DELETE_FIRST(&L);
            break;
            case 'l':
            LIST_DELETE_LAST(&L);
            break;
            case 's':
            scanf("%d",&k);
            y = LIST_SEARCH(L,k);
            if (y!=NULL)
            {
                printf("2\n");
            }
            else
            {
                printf("1\n");
            }
            break;
            case 'e':
            flag = 1;
            break;
        }
        if (flag)
        {
            break;
        }
    }
}