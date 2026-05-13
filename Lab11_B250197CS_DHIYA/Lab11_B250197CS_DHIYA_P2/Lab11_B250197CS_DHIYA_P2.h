#ifndef P2_H
#define P2_H

struct infus
{
    char name[31];
    int foll;
    int er;
    int posts;
};

void minHeapify(struct infus s[], int n, int i);
void buildMinHeap(struct infus s[], int n);
void heapSort(struct infus s[], int n);

#endif