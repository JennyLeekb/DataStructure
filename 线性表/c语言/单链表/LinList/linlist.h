#ifndef __LINLIST_H__
#define __LINLIST_H__
#include <malloc.h>

typedef struct Node
{
    DataType data; //数据域用来存放数据
    struct Node *next; //指针域指向下一个结点的指针
}SLNode;

void listInit(SLNode **head); //单链表初始化
int listLength(SLNode *head); //求单链表的长度
int listInsert(SLNode *head, int i, DataType x); //往单链表中插入数据
int listDelete(SLNode *head, int i, DataType *x); //删除元素
int listEdit(SLNode *head, int i, DataType x); //修改单链表中的数据
int listGet(SLNode *head, int i, DataType *x); //获取单链表中的数据
void listPrint(SLNode *head); //打印单链表
void destroy(SLNode **head); //销毁单链表

/*
 * 单链表初始化
 */
void listInit(SLNode **head)
{
    *head = (SLNode *) malloc(sizeof(SLNode));
    (*head)->next = NULL;
}

/*
 * 求单链表的长度
 * 返回单链表长度
 */
int listLength(SLNode *head)
{
    SLNode *p = head;
    int size = 0;

    while(p->next != NULL)
    {
        p = p->next;
        size ++;
    }

    return size;
}

/*
 * 往单链表中插入数据
 * 成功返回1，失败返回-1
 */
int listInsert(SLNode *head, int i, DataType x)
{
    int j,listSize;
    SLNode *p,*newNode;

    listSize = listLength(head);

    if(i < 0 || i > listSize)
    {
        printf("参数i错误!\n");
        return -1;
    }

    p = head;
    for(j = 0; j < i; j++)
    {
        p = p->next;
    }

    newNode = (SLNode *)malloc(sizeof(SLNode));
    newNode->data = x; //新结点申请地址，赋值

    newNode->next = p->next;
    p->next = newNode;
    return 1;
}

/*
 * 删除元素
 * 成功返回1，失败返回-1
 */
int listDelete(SLNode *head, int i, DataType *x)
{
    int j,listSize;
    SLNode *p,*q;

    listSize = listLength(head);
    if(i < 0 || i > (listSize-1))
    {
        printf("参数i错误!\n");
        return -1;
    }

    p = head;
    for(j = 0; j < i; j++)
    {
        p = p->next;

    }

    q = p->next;
    *x = q->data;
    p->next = q->next;

    free(q); //释放被删除的点

    return 1;
}

/*
 * 修改单链表中的数据
 * 成功返回1，失败返回-1
 */
int listEdit(SLNode *head, int i, DataType x)
{
    SLNode *p;
    int j,listSize;

    listSize = listLength(head);
    if(i < 0 || i > (listSize-1))
    {
        printf("参数i错误!\n");
        return -1;
    }

    p = head;
    for(j = 0; j < i; j++)
    {
        p = p->next;
    }

    p->next->data = x;

    return 1;
}

/*
 * 获取单链表中的数据
 * 成功返回1，失败返回-1
 */
int listGet(SLNode *head, int i, DataType *x)
{
    SLNode *p;
    int j,listSize;

    listSize = listLength(head);
    if(i < 0 || i > (listSize-1))
    {
        printf("参数i错误!\n");
        return -1;
    }

    p = head;
    for(j = 0; j < i; j++)
    {
        p = p->next;
    }

    *x = p->next->data;
    return 1;
}

/*
 * 打印单链表
 * 数据类型是整型的时候用
 */
void listPrint(SLNode *head)
{
    SLNode *p = head;
    while(p != NULL)
    {
        p = p->next;
        printf("%d -> ",p->data);
    }
}

/*
 * 销毁单链表
 */
void destroy(SLNode **head)
{
    SLNode *p,*q;

    p = *head;
    while(p != NULL)
    {
        q = p;
        p = p->next;
        free(q);
    }

    *head = NULL;
}


#endif // __LINLIST_H__
