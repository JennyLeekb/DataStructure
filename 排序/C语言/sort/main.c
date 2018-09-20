#include <stdio.h>
#include <stdlib.h>

#include "sort.h"

int main()
{
    /*DataType test[6] = {64,5,7,89,6,24};
    int n = 6,i;

    insertSort(test,n);

    printf("直接插入排序的结果为：\n");
    for(i=0;i<n;i++)
        printf("%d  ",test[i].key);*/


    /*DataType test[12] = {65,34,25,87,12,38,56,46,14,77,92,23};
    int n = 12,i;
    int d[3] = {6,3,1};
    int numOfD = 3;

    shellSort(test,n,d,numOfD);

    printf("希尔排序的结果为：\n");
    for(i=0;i<n;i++)
        printf("%d  ",test[i].key);*/

    /*DataType test[12] = {65,34,25,87,12,38,56,46,14,77,92,23};
    int n = 12,i;

    selectSort(test,n);

    printf("直接选择排序的结果为：\n");
    for(i=0;i<n;i++)
        printf("%d  ",test[i].key);*/

    /*DataType test[8] = {{10},{50},{32},{5},{76},{9},{40},{88} };
    int n = 8,i;

    heapSort(test,n);

    printf("堆排序的结果：\n");
    for(i=0;i<n;i++)
        printf("%d  ",test[i].key);*/

    DataType test[8] = {{38},{5},{19},{26},{49},{97},{1},{66} };
    int n = 8,i;

    bubleSort(test,n);

    printf("冒泡排序的结果：\n");
    for(i=0;i<n;i++)
        printf("%d  ",test[i].key);

    return 0;
}
