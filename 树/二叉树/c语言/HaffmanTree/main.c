#include <stdio.h>
#include <stdlib.h>

#include "Haffman.h"

int main()
{
    int weights[4] = {7,1,3,5};
    DataType datas[4] = {'A','B','C','D'};
    int len = 4;
    HaffNode *root,*node;
    int i,codeLen;
    int code[MaxN];

    printf("Hello world!\n");

    root = getHaffTree(datas,weights,len);
    getHaffNode('A',root,&node);
    while(node != root)
    {
        printf("%d\n",node->code[0]);
        node = node->parent;
    }

    /*printf("B code is :\n");
    for(i=0;i<codeLen;i++)
        printf("%d",code[i]);*/
    return 0;
}
