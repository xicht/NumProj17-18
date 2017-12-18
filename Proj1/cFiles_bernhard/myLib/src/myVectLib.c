/*!
 * \author  Lukas Moser
 * \date
 * \brief
 */

#include <myVectLib.h>
#include <assert.h>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <stdbool.h>
#include <time.h>

struct myVector
{
    double *a;
    int n;
};

void myVectCheck(const struct myVector *a)
{
    assert(a != NULL);
    assert(a->a != NULL);
    assert(a->n > 0);
}

struct myVector *myVectNew(const int n)
{
    struct myVector *new;

    assert(n > 0);
    new = calloc(1, sizeof(struct myVector));
    assert(new != NULL);
    new->n = n;
    new->a = calloc(n, sizeof(double));

    return new;
}

void myVectDel(struct myVector *a)
{
    myVectCheck(a);

    a->n = -1;
    free(a->a);
}

int myVectLen(const struct myVector *a)
{
    myVectCheck(a);
    return a->n;
}

void myVectSetLen(struct myVector *a, const int n)
{
    int i = 0;
    myVectCheck(a);

    a->a = realloc(a->a, n);
    assert(a->a != NULL);
    for(i = a->n; i < n; i++)
    {
        a->a[i] = 0;
    }

    a->n = n;
}
double myVectRead(const struct myVector *a, const int n)
{
    myVectCheck(a);
    assert(n > 0);
    assert(a->n >= n);

    return a->a[n-1];
}

void myVectWrite(struct myVector *a, int n, double d)
{
    myVectCheck(a);
    assert(n > 0);
    assert(a->n >= n);

    a->a[n-1] = d;
}

void myVectPrint(const char *s, const struct myVector *a)
{
    int i = 0;
    myVectCheck(a);
    assert(s != NULL);

    printf("myVector %s\n", s);
    for(i = 0; i < a->n; i++)
    {
        printf("%s%d = %f\n", s, i+1, a->a[i]);
    }
}

void myVectScan(const char *s, struct myVector *a)
{
    int i = 0;
    myVectCheck(a);
    assert(s != NULL);

    printf("myVector %s eingeben\n", s);
    for(i = 0; i < a->n; i++)
    {
        printf("%s%d = ", s, i+1);
        scanf("%lf", &a->a[i]);
    }
}

void myVectRand(struct myVector *a)
{
    int i = 0;

    myVectCheck(a);

    srand(clock()*rand());
    rand();

    for(i = 0; i < a->n; i++)
    {
        do{a->a[i] = (double)(rand()%1000) - rand()/(double)rand();}while(isnan(a->a[i]) || isinf(a->a[i]));
        if(rand()%2) a->a[i] *= -1;
    }
}


bool myVectIsSorted(struct myVector *a)
{
    unsigned int i = 0;
    bool is_sorted = true;

    myVectCheck(a);

    for(i = 0; i < a->n - 1; i++)
    {
        if(a->a[i] >= a->a[i+1])
        {
            is_sorted = false;
        }
    }

    return is_sorted;
}

