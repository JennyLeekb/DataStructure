#include <stdio.h>
#include <stdlib.h>

#include "Haffman.h"

int main()
{
    int weights[4] = {7,1,3,5};
    int len = 4;
    HaffNode *root;

    printf("Hello world!\n");

    root = getHaffTree(weights,len);


    return 0;
}
