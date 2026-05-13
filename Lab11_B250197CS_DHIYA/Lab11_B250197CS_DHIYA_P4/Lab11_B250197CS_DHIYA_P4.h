#ifndef P4_H
#define P4_H

struct hosp 
{
    char name[31];
    int level;
    int time;
};

void extractMax(struct hosp s[], int *n);
void display(struct hosp s[], int n);
void insert(struct hosp s[], int *n, struct hosp snew);
void maxHeapify(struct hosp s[], int n, int i);
int check(struct hosp a, struct hosp b);

#endif