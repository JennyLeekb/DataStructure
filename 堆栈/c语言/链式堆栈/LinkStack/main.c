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
    printf("��ǰջ��Ԫ��Ϊ %d \n",x);

    size = stackGetSize(head);
    printf("��ջ�к��� %d ��Ԫ�� \n",size);

    stackPop(head,&x);
    size = stackGetSize(head);
    printf("��ջ�к��� %d ��Ԫ�� \n",size);
    stackPrint(head);

    return 0;
}


