#ifndef P2_h
#define P2_h

#include <stdio.h>
#include <string.h>

void Enqueue(int hosp[], int *f, int *b, int N, int id);
void dequeue(int hosp[], int *f, int *b);
void displayQueue(int hosp[], int f, int b);
int isFull(int f, int b, int N);
int isEmpty(int f, int b);

#endif