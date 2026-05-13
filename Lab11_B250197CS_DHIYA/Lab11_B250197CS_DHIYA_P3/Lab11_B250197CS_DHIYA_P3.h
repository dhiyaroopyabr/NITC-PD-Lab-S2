#ifndef P3_H
#define P3_H

struct ticket
{
    int id;
    int prio;
    int time;
};

void insert(struct ticket s[], int *n, struct ticket snew);
int extractMax(struct ticket s[], int *n);
void display(struct ticket s[], int n);
void maxHeapify(struct ticket s[], int n, int i);
int check(struct ticket a, struct ticket b);
#endif