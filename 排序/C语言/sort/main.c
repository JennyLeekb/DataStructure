#include <stdio.h>
#include <stdlib.h>

#include "sort.h"

int main()
{
    DataType test[6] = {64,5,7,89,6,24};
    int n = 6,i;

    insertSort(test,n);

    printf("直接插入排序的结果为：\n");
    for(i=0;i<n;i++)
        printf("%d  ",test[i].key);

    return 0;
}
