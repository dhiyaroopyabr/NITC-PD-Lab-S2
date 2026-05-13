#include "Lab9_B250197CS_DHIYA_P3.h"

void push(node *head, int *top, int n)
{
    node newNode = (node)malloc(sizeof(struct list));

    int id;
    char name[31];
    int age;
    char place[31];
    int token;
    int bag;

    scanf("%d %s %d %s %d %d",&id,name,&age,place,&token,&bag);

    newNode->id = id;
    strcpy(newNode->name,name);
    newNode->age = age;
    strcpy(newNode->place,place);
    newNode->token = token;
    newNode->bag = bag;
    newNode->next = NULL;

    if (*top == n-1)
    {
        printf("Full\n");
        free(newNode);
        return;
    }

    if (*head == NULL)
    {
        (*top)++;
        *head = newNode;
    }
    else
    {
        (*top)++;
        newNode->next = *head;
        *head = newNode;
    }
}

void pop(node *head, int *top)
{
    if (*head == NULL)
    {
        printf("empty\n");
        return;
    }

    node temp = *head;

    printf("%d %s %d %s %d %d\n",
           temp->id,temp->name,temp->age,
           temp->place,temp->token,temp->bag);

    *head = (*head)->next;

    free(temp);
    (*top)--;
}

void display(node head)
{
    if (head==NULL)
    {
        printf("empty\n");
        return;
    }

    node temp = head;

    while (temp!=NULL)
    {
        printf("%d %s %d %s %d %d\n",
               temp->id,temp->name,temp->age,
               temp->place,temp->token,temp->bag);

        temp = temp->next;
    }
}
