#ifndef __SEQSTACK_H__
#define __SEQSTACK_H__

typedef struct
{
    DataType stack[MaxSize];
    int top; //ָ��ջ������һ�����ݴ����ջ��λ�ã�
}SeqStack;

void stackInit(SeqStack *seqStack); //��ʼ����ջ
int stackNotEmpty(SeqStack *seqStack); //��ջ�ǿ��ж�
int stackGetSize(SeqStack *seqStack); //��ȡ��ջ�е�Ԫ�ظ���
int stackPush(SeqStack *seqStack, DataType e); //��ջ����
int stackPop(SeqStack *seqStack, DataType *x); //��ջ����
int stackTop(SeqStack *seqStack, DataType *x); //ȡջ��Ԫ��
void stackPrint(SeqStack *seqStack); //��ӡ��ջ����������

/*
 * ��ʼ����ջ
 */
void stackInit(SeqStack *seqStack)
{
    seqStack->top = 0;
}

/*
 * ��ջ�ǿ��ж�
 * �ǿշ���1���շ���-1
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
 * ��ȡ��ջ�е�Ԫ�ظ���
 */
int stackGetSize(SeqStack *seqStack)
{
    return seqStack->top;
}

/*
 * ��ջ����
 * �ɹ�����1��ʧ�ܷ���-1
 */
int stackPush(SeqStack *seqStack, DataType e)
{
    if(seqStack->top > MaxSize)
    {
        printf("˳���ջ�������޷���ջ��\n");
        return -1;
    }

    seqStack->stack[seqStack->top] = e;
    seqStack->top ++;

    return 1;
}

/*
 * ��ջ����
 * �ɹ�����1��ʧ�ܷ���-1
 */
int stackPop(SeqStack *seqStack, DataType *x)
{
    if(seqStack->top <= 0)
    {
        printf("˳���ջΪ�գ��޷���ջ��\n");
        return -1;
    }

    *x = seqStack->stack[--seqStack->top];
    return 1;
}

/*
 * ȡջ��Ԫ��
 * �ɹ�����1��ʧ�ܷ���-1
 */
int stackTop(SeqStack *seqStack, DataType *x)
{
    if(seqStack->top <= 0)
    {
        printf("˳���ջΪ�գ��޷���ջ��\n");
        return -1;
    }

    *x = seqStack->stack[seqStack->top-1];
    return 1;
}

/*
 * ��ӡ��ջ����������
 * int��������ʱ������
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
