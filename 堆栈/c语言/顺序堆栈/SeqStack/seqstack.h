#ifndef __SEQSTACK_H__
#define __SEQSTACK_H__

typedef struct
{
    DataType stack[MaxSize];
    int top; //指向栈顶（下一个数据存入堆栈的位置）
}SeqStack;

void stackInit(SeqStack *seqStack); //初始化堆栈
int stackNotEmpty(SeqStack *seqStack); //堆栈非空判断
int stackGetSize(SeqStack *seqStack); //获取堆栈中的元素个数
int stackPush(SeqStack *seqStack, DataType e); //入栈操作
int stackPop(SeqStack *seqStack, DataType *x); //出栈操作
int stackTop(SeqStack *seqStack, DataType *x); //取栈顶元素
void stackPrint(SeqStack *seqStack); //打印堆栈中所有数据

/*
 * 初始化堆栈
 */
void stackInit(SeqStack *seqStack)
{
    seqStack->top = 0;
}

/*
 * 堆栈非空判断
 * 非空返回1，空返回-1
 */
int stackNotEmpty(SeqStack *seqStack)
{
    if(seqStack->top <= 0){
        return -1;
    }
    else
    {
        return 1;
    }
}

/*
 * 获取堆栈中的元素个数
 */
int stackGetSize(SeqStack *seqStack)
{
    return seqStack->top;
}

/*
 * 入栈操作
 * 成功返回1，失败返回-1
 */
int stackPush(SeqStack *seqStack, DataType e)
{
    if(seqStack->top > MaxSize)
    {
        printf("顺序堆栈已满，无法入栈！\n");
        return -1;
    }

    seqStack->stack[seqStack->top] = e;
    seqStack->top ++;

    return 1;
}

/*
 * 出栈操作
 * 成功返回1，失败返回-1
 */
int stackPop(SeqStack *seqStack, DataType *x)
{
    if(seqStack->top <= 0)
    {
        printf("顺序堆栈为空，无法出栈！\n");
        return -1;
    }

    *x = seqStack->stack[--seqStack->top];
    return 1;
}

/*
 * 取栈顶元素
 * 成功返回1，失败返回-1
 */
int stackTop(SeqStack *seqStack, DataType *x)
{
    if(seqStack->top <= 0)
    {
        printf("顺序堆栈为空，无法出栈！\n");
        return -1;
    }

    *x = seqStack->stack[seqStack->top-1];
    return 1;
}

/*
 * 打印堆栈中所有数据
 * int类型数据时候适用
 */
void stackPrint(SeqStack *seqStack)
{
    int e,p;
    p = seqStack->top;
    while(p > 0)
    {
        p--;
        e = seqStack->stack[p];
        printf("%d -> ",e);
    }
    printf("\n");
}

#endif // __SEQSTACK_H__
