#include "Lab9_B250197CS_DHIYA_P4.h"

void enqueue(node *front, node *rear, int *size, int n)
{
    node newNode = (node)malloc(sizeof(struct list));

    int id;
    char name[51];
    char topic[101];

    scanf("%d %s %s",&id,name,topic);

    newNode->id = id;
    strcpy(newNode->name,name);
    strcpy(newNode->topic,topic);
    newNode->next = NULL;
    newNode->prev = NULL;

    if (*size == n)
    {
        printf("Full\n");
        free(newNode);
        return;
    }
    else if (*front==NULL && *rear==NULL)
    {
        *front = *rear = newNode;
    }
    else
    {
        (*rear)->next = newNode;
        newNode->prev = *rear;
        *rear = newNode;
    }

    (*size)++;
}

void dequeue(node *front, node *rear, int *size)
{
    if (*front==NULL && *rear==NULL)
    {
        printf("Empty\n");
        return;
    }
    else if (*size==1)
    {
        printf("%d %s %s\n",(*front)->id,(*front)->name,(*front)->topic);
        free(*front);
        *front = *rear = NULL;
    }
    else
    {
        printf("%d %s %s\n",(*front)->id,(*front)->name,(*front)->topic);

        node temp = *front;

        *front = (*front)->next;
        (*front)->prev = NULL;

        free(temp);
    }

    (*size)--;
}

void display(node head, char ch)
{
    if (head==NULL)
    {
        printf("Empty\n");
        return;
    }

    if (ch=='L')
    {
        while (head!=NULL)
        {
            printf("%d %s %s\n",head->id,head->name,head->topic);
            head = head->next;
        }
    }
    else
    {
        while (head!=NULL)
        {
            printf("%d %s %s\n",head->id,head->name,head->topic);
            head = head->prev;
        }
    }
}