#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "output.h"

/* Set the key of the current item */
void setKey(char *k) {
  printf("* %s\n", k);
  free(k);
}

/* Set up the current item's value container */
void newString(char *v) {
  printf("> %s\n", v);
  free(v);
}

void newList(int len) {
  printf("L %u\n", len);
}

void newSet(int len) {
  printf("S %u\n", len);
}

void newZset(int len) {
  printf("Z %u\n", len);
}

void newHash(int len) {
  printf("H %u\n", len);
}

/* Add data to current value */
void addToList(char *v) {
  printf("  * %s\n", v);
  free(v);
}

void addToSet(char *v) {
  printf("  * %s\n", v);
  free(v);
}

void addToZset(char *k, double *v) {
  printf("  K %s\n", k);
  printf("  V %f\n", *v);
  free(k); free(v);
}

void addToHash(char *k, char *v) {
  printf("  K %s\n", k);
  printf("  V %s\n", v);
  free(k); free(v);
}

/* Process this and then deallocate it. */
void finishProcessing(void) {
  printf(".\n");
}
