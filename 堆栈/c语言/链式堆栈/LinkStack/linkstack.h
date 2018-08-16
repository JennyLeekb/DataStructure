#ifndef __LINKSTACK_H__
#define __LINKSTACK_H__
#include <malloc.h>

typedef struct snode{
    DataType data;
    struct snode *next;
}LSNode;

void stackInit(LSNode **head); //初始化堆栈
int stackNotEmpty(LSNode *head); //堆栈非空判断
int stackGetSize(LSNode *head); //获取堆栈中的元素个数
int stackPush(LSNode *head, DataType x); //入栈操作
int stackPop(LSNode *head, DataType *x); //出栈操作
int stackTop(LSNode *head, DataType *x); //取栈顶元素
void stackPrint(LSNode *head); //打印堆栈中所有数据
void destroy(LSNode *head); //撤销动态申请空间


/*
 * 初始化堆栈
 */
void stackInit(LSNode **head)
{
    *head = (LSNode *)malloc(sizeof(LSNode));  //给头指针分配地址
    (*head)->next = NULL;
}

/*
 * 堆栈非空判断
 * 空返回-1，非空返回1
 */
int stackNotEmpty(LSNode *head)
{
    if(head->next == NULL)
    {
        printf("堆栈为空！\n");
        return -1;
    }
    else
    {
        printf("堆栈不为空！\n");
        return 1;
    }
}

/*
 * 获取堆栈中的元素个数
 * 返回堆栈中元素个数
 */
int stackGetSize(LSNode *head)
{
    LSNode *p;
    int stackSize = 0;
    p = head;

    while(p->next != NULL)
    {
        p = p->next;
        stackSize ++;
    }

    return stackSize;
}

/*
 * 入栈操作
 * 成功返回1，失败返回-1
 */
int stackPush(LSNode *head, DataType x)
{
    LSNode *newNode;
    newNode = (LSNode *) malloc(sizeof(LSNode));
    newNode->data = x;
    newNode->next = head->next;
    head->next = newNode;

    return 1;
}

/*
 * 出栈操作
 * 成功返回1，失败返回-1
 */
int stackPop(LSNode *head, DataType *x)
{
    LSNode *p;
    if(head->next == NULL)
    {
        printf("堆栈为空，无元素可出栈！\n");
        return -1;
    }

    p = head->next;
    *x = p->data;
    head->next = p->next;

    free(p);

    return 1;
}

/*
 * 取栈顶元素
 * 成功返回1，失败返回-1
 */
int stackTop(LSNode *head, DataType *x)
{
    if(head->next == NULL)
    {
        printf("堆栈为空，无元素可取！\n");
        return -1;
    }

    *x = head->next->data;
    return 1;
}

/*
 * 打印堆栈中所有数据
 */
void stackPrint(LSNode *head)
{
    LSNode *p;
    p = head;
    while(p->next != NULL)
    {
        p = p->next;
        printf("%d -> ",p->data);
    }
    printf("\n");
}

/*
 * 撤销动态申请空间
 */
void destroy(LSNode *head)
{
    LSNode *p, *q;
    p = head;
    while(p != NULL)
    {
        q = p;
        p = p->next;
        free(q);
    }
}



#endif // __LINKSTACK_H__
