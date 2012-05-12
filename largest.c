/* Output module that keeps track of the 100 largest values. */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "heap.h"
#include "output.h"

heap topn;
int heapCount;

void initOutput(void) {
  heap_create(&topn, 0, NULL);
  heapCount = 0;
}

/* Set the key of the current item */
void setKey(char *k) {
  free(k);
}

/* Set up the current item's value container */
void newString(char *v) {
  int *len = malloc(sizeof(int));
  *len = strlen(v);
  heap_insert(&topn, len, v);
  heapCount++;

  if (heapCount > 3) {
    char *evicted; int *temp;
    heap_delmin(&topn, (void**)&temp, (void**)&evicted);
    free(evicted); free(temp);
  }
}

void newList(int len) {
  
}

void newSet(int len) {
  
}

void newZset(int len) {
  
}

void newHash(int len) {
  
}

/* Add data to current value */
void addToList(char *v) {
  free(v);
}

void addToSet(char *v) {
  free(v);
}

void addToZset(char *k, double *v) {
  free(k); free(v);
}

void addToHash(char *k, char *v) {
  free(k); free(v);
}

/* Process this and then deallocate it. */
void finishProcessing(void) {
  char *evicted; int *temp;
  while (heap_delmin(&topn, (void**)&temp, (void**)&evicted)) {
    printf("[%i] %s\n", *temp, evicted);
    free(temp); free(evicted);
  }
}
