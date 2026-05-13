#ifndef P3_h
#define P3_h

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct list
{
    int id;
    char name[31];
    int age;
    char place[31];
    int token;
    int bag;
    struct list* next;
};

typedef struct list* node;

void push(node *head, int *top, int n);
void pop(node *head, int *top);
void display(node head);

#endif