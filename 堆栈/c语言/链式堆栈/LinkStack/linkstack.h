#ifndef __LINKSTACK_H__
#define __LINKSTACK_H__
#include <malloc.h>

typedef struct snode{
    DataType data;
    struct snode *next;
}LSNode;

void stackInit(LSNode **head); //��ʼ����ջ
int stackNotEmpty(LSNode *head); //��ջ�ǿ��ж�
int stackGetSize(LSNode *head); //��ȡ��ջ�е�Ԫ�ظ���
int stackPush(LSNode *head, DataType x); //��ջ����
int stackPop(LSNode *head, DataType *x); //��ջ����
int stackTop(LSNode *head, DataType *x); //ȡջ��Ԫ��
void stackPrint(LSNode *head); //��ӡ��ջ����������
void destroy(LSNode *head); //������̬����ռ�


/*
 * ��ʼ����ջ
 */
void stackInit(LSNode **head)
{
    *head = (LSNode *)malloc(sizeof(LSNode));  //��ͷָ������ַ
    (*head)->next = NULL;
}

/*
 * ��ջ�ǿ��ж�
 * �շ���-1���ǿշ���1
 */
int stackNotEmpty(LSNode *head)
{
    if(head->next == NULL)
    {
        printf("��ջΪ�գ�\n");
        return -1;
    }
    else
    {
        printf("��ջ��Ϊ�գ�\n");
        return 1;
    }
}

/*
 * ��ȡ��ջ�е�Ԫ�ظ���
 * ���ض�ջ��Ԫ�ظ���
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
 * ��ջ����
 * �ɹ�����1��ʧ�ܷ���-1
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
 * ��ջ����
 * �ɹ�����1��ʧ�ܷ���-1
 */
int stackPop(LSNode *head, DataType *x)
{
    LSNode *p;
    if(head->next == NULL)
    {
        printf("��ջΪ�գ���Ԫ�ؿɳ�ջ��\n");
        return -1;
    }

    p = head->next;
    *x = p->data;
    head->next = p->next;

    free(p);

    return 1;
}

/*
 * ȡջ��Ԫ��
 * �ɹ�����1��ʧ�ܷ���-1
 */
int stackTop(LSNode *head, DataType *x)
{
    if(head->next == NULL)
    {
        printf("��ջΪ�գ���Ԫ�ؿ�ȡ��\n");
        return -1;
    }

    *x = head->next->data;
    return 1;
}

/*
 * ��ӡ��ջ����������
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
 * ������̬����ռ�
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
