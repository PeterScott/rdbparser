/* Output module that keeps track of the 100 largest values. */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "iheap.h"
#include "output.h"

struct iheap topn;
int heapCount;
char *oldKey = NULL;

void initOutput(void) {
  iheap_init(&topn);
  heapCount = 0;
}

/* Set the key of the current item */
void setKey(char *k) {
  if (oldKey != NULL) free(oldKey);
  oldKey = k;
}

/* Set up the current item's value container */
void newString(char *v) {
  struct iheap_node *n = malloc(sizeof(struct iheap_node));
  iheap_node_init(n, strlen(v), strdup(oldKey));
  iheap_insert(&topn, n);
  heapCount++;

  if (heapCount > 3) {
    n = iheap_take(&topn);
    free(iheap_node_value(n)); free(n);
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
  struct iheap_node *n;
  while (!iheap_empty(&topn)) {
    n = iheap_take(&topn);
    evicted = iheap_node_value(n);
    printf("[%i] %s\n", n->key, evicted);
    free(evicted); free(n);
  }
}
