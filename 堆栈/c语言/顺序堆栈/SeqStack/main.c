#include <stdio.h>
#include <stdlib.h>

typedef int DataType;
#define MaxSize 1000
#include "seqstack.h"


int main()
{
    printf("Hello world!\n");

    int i,size;
    int e;
    SeqStack seqStack;
    SeqStack *s = &seqStack;

    stackInit(s);

    if(stackNotEmpty(s) == 1)
    {
        printf("stack not empty! \n");
    }
    else
    {
        printf("stack is empty! \n");
    }

    for(i = 0; i < 10; i++)
    {
        stackPush(s,i+1);
    }

    if(stackNotEmpty(s) == 1)
    {
        printf("stack not empty! \n");
    }
    else
    {
        printf("stack is empty! \n");
    }

    size = stackGetSize(s);
    printf("stack size is %d \n",size);

    stackPop(s,&e);
    printf("stack data in top is %d \n",e);

    stackTop(s,&e);
    printf("after pop,stack data in top is %d \n",e);

    stackPrint(s);

    return 0;
}
