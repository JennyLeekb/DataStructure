#ifndef __SEQLIST_H__
#define __SEQLIST_H__

typedef struct
{
    DataType list[MaxSize]; //存储数据元素的数组
    int size; //顺序表中当前存储的数据元素个数
}SeqList;

void listInit(SeqList *seqList); //初始化顺序表
int listLength(SeqList *seqList); //求当前元素的个数
int listInsert(SeqList *seqList, int i, DataType x); //插入数据元素
int listDelete(SeqList *seqList, int i, DataType *x); //删除元素
int listGet(SeqList *seqList, int i, DataType *x); //取元素
int listEdit(SeqList *seqList, int i, DataType x); //修改元素

/*
 * 初始化顺序表
 */
void listInit(SeqList *seqList)
{
    seqList->size = 0; //定义初始数据元素个数
}

/*
 * 求当前数据元素个数
 */
int listLength(SeqList *seqList)
{
    return seqList->size;
}

/*
 * 插入数据元素,成功返回1，失败返回-1
 */
int listInsert(SeqList *seqList, int i, DataType x)
{
    int j;
    if(seqList->size >= MaxSize)
    {
        printf("顺序表已满，无法插入！\n");
        return -1;
    }
    if(i < 0 || i > seqList->size)
    {
        printf("参数i不合法！\n");
        return -1;
    }

    for(j = seqList->size; j > i; j--)//后移数据
    {
        seqList->list[j] = seqList->list[j-1];
    }

    seqList->list[i] = x; //插入元素
    seqList->size++;

    return 1;
}

/*
 * 删除元素
 * 删除顺序表中第i个元素，并保存到x中
 * 成功返回1，失败返回-1
 */
int listDelete(SeqList *seqList, int i, DataType *x)
{
    int j;
    if(seqList->size == 0)
    {
        printf("顺序表已空无数据元素可删！\n");
        return -1;
    }

    if(i < 0 || i > seqList->size-1){
        printf("输入参数i错误！\n");
        return -1;
    }

    *x = seqList->list[i];
    for(j = i; j < seqList->size; j++)
    {
        seqList->list[j] = seqList->list[j+1]; //数据迁移
    }

    seqList->size --;

    return 1;
}

/*
 * 取元素
 * 取第i个元素，存于x中
 * 成功返回-1，失败返回1
 */
int listGet(SeqList *seqList, int i, DataType *x)
{
    if(seqList->size == 0)
    {
        printf("顺序表已空！无元素可取！\n");
        return -1;
    }

    if(i < 0 || i > seqList->size-1)
    {
        printf("输入参数i错误\n");
        return -1;
    }

    *x = seqList->list[i];
    return 1;
}

/*
 * 修改元素
 * 修改第i个位置的元素
 * 成功返回1，失败返回-1
 */
int listEdit(SeqList *seqList, int i, DataType x)
{
    if(seqList->size == 0)
    {
        printf("顺序表已空，无元素可修改！\n");
        return -1;
    }

    if(i < 0 || i > seqList->size-1)
    {

        printf("输入参数i错误\n");
        return -1;
    }

    seqList->list[i] = x;
    return 1;
}

#endif // __SEQLIST_H__
