#ifndef P1_H
#define P1_H

struct loan
{
    int cibil;
    int loan;
};

void heapSort(struct loan s[], int n);
void buildMinHeap(struct loan s[], int n);
void minHeapify(struct loan s[], int n, int i);

#endif