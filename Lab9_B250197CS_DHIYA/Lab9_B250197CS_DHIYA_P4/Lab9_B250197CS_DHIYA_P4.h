#ifndef P4_h
#define P4_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct list
{
    int id;
    char name[51];
    char topic[101];
    struct list* prev;
    struct list* next;
};

typedef struct list* node;

void enqueue(node *front, node *rear, int *size, int n);
void dequeue(node *front, node *rear, int *size);
void display(node head, char ch);

#endif