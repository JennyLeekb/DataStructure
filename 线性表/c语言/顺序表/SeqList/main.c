#include <stdio.h>
#include <stdlib.h>
#define MaxSize 100
typedef int DataType;
#include "seqlist.h"

void testSeqList();
int q1(SeqList *seqList, DataType *x);
int q2(SeqList *seqList);
void reserve(SeqList *seqList, int src, int des);
int q3(SeqList *seqList, DataType x);
int q4(SeqList *seqList, DataType s, DataType t);
int q5(SeqList *seqList);
void q6(SeqList *list1, SeqList *list2,SeqList *list);

int main(void)
{
    printf("Hello world!\n");

    SeqList list,list1,list2;
    int i;

    listInit(&list);
    listInit(&list1);
    listInit(&list2);

    for(i=0;i<10;i++)
    {
        listInsert(&list1,i,i);
    }
    listPrint(&list1);

    for(i=0;i<10;i++)
    {
        listInsert(&list2,i,i+3);
    }
    listPrint(&list2);

    /*q1(&list,&x);
    printf("x is %d \n",x);
    listPrint(&list);*/

    /*q2(&list);
    listPrint(&list);*/

    /*q3(&list, 0);
    listPrint(&list);*/

    /*q4(&list,2,5);
    listPrint(&list);*/

    /*q5(&list);
    listPrint(&list);*/

    q6(&list1,&list2,&list);
    listPrint(&list);


    return 0;
}


/*
 * 测试顺序表
 */
void testSeqList()
{
    SeqList list;

    SeqList *seqList = &list;
    int i,x,size;

    listInit(seqList);

    for(i=0;i<11;i++)
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
}


/*
 * 从顺序表中删除具有最小值的元素，并由函数返回删除的元素的值
 * 空出的元素的位置由最后一个元素填补，若顺序表为空则显示出错信息并推出运行
 */
 int q1(SeqList *seqList, DataType *x)
 {
    DataType min;
    int i,size,pos,last;
    size = listLength(seqList); //获取顺序表大小

    if(size == 0)
    {
        printf("顺序表为空！\n");
        return -1;
    }

    min = seqList->list[0];
    pos = 0;
    for(i=1;i<size;i++)
    {
        if(seqList->list[i] < min)
        {
            min = seqList->list[i];
            pos = i;
        }
     }

    *x = min;
    seqList->list[pos] = seqList->list[size-1]; //最后一个元素填补删除的元素
    listDelete(seqList,size-1,&last); //将最后一个元素删除

    return 1;
 }


 /*
  * 设计一个高效算法，将顺序表中的所有元素逆置，要求算法的空间复杂度为O(1)
  */
int q2(SeqList *seqList)
{
    int src,des,size;
    size = listLength(seqList);
    if(size == 0)
    {
        printf("顺序表为空！\n");
        return -1;
    }
    src = 0;
    des = size -1;
    while(src < des)
    {
        reserve(seqList,src,des);
        src ++;
        des --;
    }

    return 1;
}

/*
 * 逆置
 */
void reserve(SeqList *seqList, int src, int des)
{
    DataType temp;
    temp = seqList->list[src];
    seqList->list[src] = seqList->list[des];
    seqList->list[des] = temp;
}


/*
 * 长度为n的顺序表，编写一个时间复杂度为O(n),空间复杂度为O(1)的算法，
 * 该算法删除顺序表中所有值为x的元素
 */
int q3(SeqList *seqList, DataType x)
{
    int i,k,size,newSize;
    size = seqList->size;
    if(size == 0)
    {
        printf("顺序表为空！\n");
        return -1;
    }

    k = 0;
    newSize = 0;
    for(i=0;i<size;i++)
    {
        if(seqList->list[i] != x)
        {
            seqList->list[k] = seqList->list[i];
            k ++;
            newSize ++;
        }
    }
    seqList->size = newSize;

    return 1;
}

/*
 * 从顺序表中删除其值在给定值s与t之间(要求s<t)的所有元素，
 * 如果s或t给的不合理或者顺序表为空则显示出错信息并退出运行
 */
int q4(SeqList *seqList, DataType s, DataType t)
{
    int size,i,k,newSize;
    size = seqList->size;
    if(s >= t)
    {
        printf("参数错误！\n");
        return -1;
    }
    if(size == 0)
    {
        printf("顺序表为空！\n");
        return -1;
    }

    k = 0;
    newSize = 0;
    for(i=0;i<size;i++)
    {
        if(seqList->list[i] <= s || seqList->list[i] >= t)
        {
            seqList->list[k] = seqList->list[i];
            k++;
            newSize++;
        }
    }

    seqList->size = newSize;

    return 1;
}


/*
 * 从顺序表中删除所有重复的元素，使顺序表元素不重复。
 */
 int q5(SeqList *seqList)
 {
    int i,j,k,size;
    DataType temp;

    size = seqList->size;
    if(size == 0)
    {
        printf("顺序表为空！\n");
        return-1;
    }


    for(i=0;i<size;i++)
    {
        temp = seqList->list[i];
        k = i+1;
        for(j=i+1;j<size;j++)
        {
            if(seqList->list[j] != temp)
            {
                seqList->list[k] = seqList->list[j];
                k++;
            }
        }
        size = k;
    }

    seqList->size = size;
    return 1;
 }

/*
 * 将两个有序表合并成一个新的有序表
 */
 void q6(SeqList *list1, SeqList *list2, SeqList *list)
 {
     int i,j,k,size1,size2;

     size1 = list1->size;
     size2 = list2->size;

     if(size1)

     i=j=k=0;
     while(i<size1 && j < size2)
     {
         if(list1->list[i] <= list2->list[j])
         {
            listInsert(list,k,list1->list[i]);
            i++;
         }
         else
         {
            listInsert(list,k,list2->list[j]);
            j++;
         }
         k++;
     }

     if(k != (size1+size2)){
        if(i == size1)
        {
            while(j<size2){
                listInsert(list,k,list2->list[j]);
                k++;
                j++;
            }
        }
        else if(j == size2){
            while(i<size1){
                listInsert(list,k,list1->list[i]);
                k++;
                i++;
            }
        }
     }

 }


