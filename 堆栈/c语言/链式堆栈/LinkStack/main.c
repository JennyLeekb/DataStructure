#include <stdio.h>
#include <stdlib.h>

typedef int DataType;
#include "linkstack.h"

int main()
{
    printf("Hello world!\n");

    int i,x,size;
    LSNode *head;

    stackInit(&head);
    stackNotEmpty(head);
    for(i = 0; i < 10; i++)
    {
        stackPush(head,i);
    }
    stackNotEmpty(head);
    stackPrint(head);

    stackTop(head,&x);
    printf("当前栈顶元素为 %d \n",x);

    size = stackGetSize(head);
    printf("堆栈中含有 %d 个元素 \n",size);

    stackPop(head,&x);
    size = stackGetSize(head);
    printf("堆栈中含有 %d 个元素 \n",size);
    stackPrint(head);

    return 0;
}


