#include <stdio.h>
#include <stdlib.h>

#include "sort.h"

int main()
{
    /*DataType test[6] = {64,5,7,89,6,24};
    int n = 6,i;

    insertSort(test,n);

    printf("ֱ�Ӳ�������Ľ��Ϊ��\n");
    for(i=0;i<n;i++)
        printf("%d  ",test[i].key);*/


    /*DataType test[12] = {65,34,25,87,12,38,56,46,14,77,92,23};
    int n = 12,i;
    int d[3] = {6,3,1};
    int numOfD = 3;

    shellSort(test,n,d,numOfD);

    printf("ϣ������Ľ��Ϊ��\n");
    for(i=0;i<n;i++)
        printf("%d  ",test[i].key);*/

    DataType test[12] = {65,34,25,87,12,38,56,46,14,77,92,23};
    int n = 12,i;

    selectSort(test,n);

    printf("ֱ��ѡ������Ľ��Ϊ��\n");
    for(i=0;i<n;i++)
        printf("%d  ",test[i].key);

    return 0;
}
