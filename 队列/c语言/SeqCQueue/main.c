#include <stdio.h>
#include <stdlib.h>

typedef char DataType;
#define MaxQueueSize 100

#include "seqcqueue.h"

int main()
{
    int i;
    DataType x;
    printf("Hello world!\n");

    SeqCQueue queue;
    initQueue(&queue);

    appendQueue(&queue,'A');
    appendQueue(&queue,'B');
    appendQueue(&queue,'C');
    appendQueue(&queue,'D');
    appendQueue(&queue,'E');

    for(i=0;i<4;i++)
    {
        deleteQueue(&queue, &x);
        printf("%c  ",x);
    }

    getQueue(&queue, &x);
    printf("%c  \n",x);

    if(queueNotEmpty(&queue))
        printf("���зǿգ�\n");
    else
        printf("�����ѿգ�\n");

    deleteQueue(&queue, &x);
    printf("%c  \n",x);

    if(queueNotEmpty(&queue))
        printf("���зǿգ�\n");
    else
        printf("�����ѿգ�\n");


    return 0;
}
