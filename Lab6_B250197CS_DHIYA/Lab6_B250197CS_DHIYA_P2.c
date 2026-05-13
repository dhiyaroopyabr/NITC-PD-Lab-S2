#include <stdio.h>
#include <stdlib.h>
struct dll
{
    int key;
    struct dll* prev;
    struct dll* next;
};

typedef struct dll* node;

void PRINT(node L)
{
    node p = L;
    while (p!=NULL)
    {
        printf("%d ",p->key);
        p = p->next;
    }
    printf("\n");
}

node CREATE_NODE(int k)
{
    node temp = (node)malloc(sizeof(struct dll));
    if (temp == NULL)
    {
        exit(0);
    }
    temp->key = k;
    temp->prev = NULL;
    temp->next = NULL;
    return temp;
}

void LIST_INSERT_FRONT(node *L, node x)
{
    if (*L == NULL)
    {
        *L = x;
    }
    else
    {
        x->next = *L;
        (*L)->prev = x;
        *L = x;
    }
}

void LIST_INSERT_TAIL(node *L, node x)
{
    if (*L == NULL)
    {
        *L = x;
    }
    else
    {
        node p = *L;
        while (p->next!=NULL)
        {
            p = p->next;
        }
        p->next = x;
        x->prev = p;
    }
}

void LIST_INSERT_AFTER(node L, node x, node y)
{
    if (y==NULL || x==NULL) return;
    if (y->next==NULL)
    {
        y->next = x;
        x->prev = y;
    }
    else
    {
        y->next->prev = x;
        x->next = y->next;
        y->next = x;
        x->prev = y;

    }
}

void LIST_INSERT_BEFORE(node *L, node x, node y)
{
    if (y==NULL || x==NULL)
    return;
    if (*L==y)
    {
        y->prev = x;
        x->next = y;
        *L = x;
    }
    else
    {
        x->prev = y->prev;
        y->prev->next = x;
        x->next = y;
        y->prev = x;  
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
    printf("%d\n", x->key);
    *L = x->next;
    if (*L != NULL)
        (*L)->prev = NULL;
    free(x);
}
    else if (x->next == NULL)
    {
        printf("%d\n",x->key);
        x->prev->next = NULL;
        x->prev = NULL;
    }
    else
    {
        printf("%d\n",x->key);
        x->prev->next = x->next;
        x->next->prev = x->prev;
        x->next = NULL;
        x->prev = NULL;  
    }
}

void LIST_DELETE_FIRST(node *L)
{
    if (*L == NULL)
        return;

    node temp = *L;
    printf("%d\n", temp->key);

    *L = temp->next;
    if (*L != NULL)
        (*L)->prev = NULL;

    free(temp);
}

void LIST_DELETE_LAST(node *L)
{
    if (*L == NULL)
        return;

    node p = *L;

    if (p->next == NULL)
    {
        printf("%d\n", p->key);
        free(p);
        *L = NULL;
        return;
    }

    while (p->next != NULL)
        p = p->next;

    printf("%d\n", p->key);
    p->prev->next = NULL;
    free(p);
}
node LIST_SEARCH(node L, int k)
{
    if (L==NULL)
    {
        return NULL;
    }
    else
    {
        node p = L;
        while (p!=NULL)
        {
            if (p->key == k)
            {
                return p;
            }
            p = p->next;
        }
        return NULL;
    }
}

int main()
{
    node L = NULL;
    int k, sk;
    node x, y;
    char c;
    int flag = 0;
    while (1)
    {
        scanf(" %c",&c);
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
            case 'a':
            scanf("%d %d",&k,&sk);
            x = CREATE_NODE(k);
            y = LIST_SEARCH(L,sk);
            LIST_INSERT_AFTER(L,x,y);
            break;
            case 'b':
            scanf("%d %d",&k,&sk);
            x = CREATE_NODE(k);
            y = LIST_SEARCH(L,sk);
            LIST_INSERT_BEFORE(&L,x,y);
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
            if (y==NULL)
            {
                printf("1\n");
            }
            else
            {
                printf("2\n");
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