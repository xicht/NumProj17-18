#ifndef MYVECTLIB_H_
#define MYVECTLIB_H_

#include <stdbool.h>

typedef struct myVector myVector_t;

void myVectCheck(const myVector_t *a);
myVector_t *myVectNew(int n);
void myVectDel(myVector_t *a);
int myVectLen(const myVector_t *a);
void myVectSetLen(myVector_t *a, int n);
double myVectRead(const myVector_t *a, const int n);
void myVectWrite(myVector_t *a, int n, double d);
void myVectPrint(const char *s, const myVector_t *a);
void myVectScan(const char *s, myVector_t *a);
bool myVectIsSorted(struct myVector *a);
void myVectRand(struct myVector *a);

#endif
