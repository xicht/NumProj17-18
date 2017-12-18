#include <stdlib.h>
#include <assert.h>

void mySortBubble(double *data, unsigned int n)
{
    unsigned int i = 0, k = 0;
    unsigned int swapped = 0;
    double tmp = 0;

    assert(data != NULL);
    assert(n > 0);

    do
    {
        swapped = 0;
        for(i = 0; i < n-k-1; i++)
        {
            if(data[i] > data[i+1])
            {
                tmp = data[i];
                data[i] = data[i+1];
                data[i+1] = tmp;
                swapped = 1;
            }
        }
        k++;
    }while((n-k != 0) && swapped);
}
