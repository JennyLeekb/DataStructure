#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef int DataType;

#include "linlist.h"


int main()
{
    printf("Hello world!\n");

    SLNode *head;
    int i,listSize,e;

    listInit(&head);
    for(i = 0; i < 10; i++)
    {
        listInsert(head,i,i+1);
    }

    listSize = listLength(head);
    printf("list size is %d \n",listSize);

    listGet(head,8,&e);
    printf("data in 8 is %d \n",e);

    listDelete(head,4,&e);

    listSize = listLength(head);
    printf("list size is %d \n",listSize);

    listEdit(head,7,1000);

    listPrint(head);

    destroy(&head);

    return 0;
}
