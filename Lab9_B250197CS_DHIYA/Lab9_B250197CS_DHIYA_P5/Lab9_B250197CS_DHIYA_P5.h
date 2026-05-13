#ifndef P5_h
#define P5_h

#include <stdio.h>
#include <string.h>

struct list
{
    int id;
    char name[51];
    char dep[51];
};

void Insert(struct list s[], int *f, int *r, int N, int id, char *name, char *dep);
void Delete(struct list s[], int *f, int *r, int N);
void Display_F(struct list s[], int f, int r, int N);
void Display_R(struct list s[], int f, int r, int N);

#endif