#include <stdio.h>
#include <stdlib.h>
#define MaxSize 100
typedef int DataType;
#include "seqlist.h"


int main(void)
{
    printf("Hello world!\n");

    SeqList *seqList;
    int i,x,size;

    listInit(seqList);

    for(i=0;i<10;i++)
    {
        listInsert(seqList,i,i+1);
    }

    size = listLength(seqList);
    printf("size is %d\n",size);

    listGet(seqList,6,&x);
    printf("x in 6 is %d\n", x);

    listDelete(seqList,7,&x);
    printf("delete element is %d\n",x);

    size = listLength(seqList);
    printf("size is %d\n",size);

    listEdit(seqList,6,1000);

    listGet(seqList,6,&x);
    printf("x in 6 is %d\n", x);

    return 0;
}
