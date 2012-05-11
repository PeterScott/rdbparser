#ifndef __OUTPUT_H
#define __OUTPUT_H

/* Set the key of the current item */
void setKey(char *k);

/* Set up the current item's value container */
void newString(char *v);
void newList(int len);
void newSet(int len);
void newZset(int len);
void newHash(int len);

/* Add data to current value */
void addToList(char *v);
void addToSet(char *v);
void addToZset(char *k, double *v);
void addToHash(char *k, char *v);

/* Process this and then deallocate it. */
void finishProcessing(void);

#endif
