/*!
 * \author  Lukas Moser
 * \date
 * \brief
 */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
#ifdef ECLIPSE_DEBUG
    setvbuf(stdout, NULL, 0, _IONBF);
#endif
    return EXIT_SUCCESS;
}
