#ifndef __LINLIST_H__
#define __LINLIST_H__
#include <malloc.h>

typedef struct Node
{
    DataType data; //�����������������
    struct Node *next; //ָ����ָ����һ������ָ��
}SLNode;

void listInit(SLNode **head); //�������ʼ��
int listLength(SLNode *head); //������ĳ���
int listInsert(SLNode *head, int i, DataType x); //���������в�������
int listDelete(SLNode *head, int i, DataType *x); //ɾ��Ԫ��
int listEdit(SLNode *head, int i, DataType x); //�޸ĵ������е�����
int listGet(SLNode *head, int i, DataType *x); //��ȡ�������е�����
void listPrint(SLNode *head); //��ӡ������
void destroy(SLNode **head); //���ٵ�����

/*
 * �������ʼ��
 */
void listInit(SLNode **head)
{
    *head = (SLNode *) malloc(sizeof(SLNode));
    (*head)->next = NULL;
}

/*
 * ������ĳ���
 * ���ص�������
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
 * ���������в�������
 * �ɹ�����1��ʧ�ܷ���-1
 */
int listInsert(SLNode *head, int i, DataType x)
{
    int j,listSize;
    SLNode *p,*newNode;

    listSize = listLength(head);

    if(i < 0 || i > listSize)
    {
        printf("����i����!\n");
        return -1;
    }

    p = head;
    for(j = 0; j < i; j++)
    {
        p = p->next;
    }

    newNode = (SLNode *)malloc(sizeof(SLNode));
    newNode->data = x; //�½�������ַ����ֵ

    newNode->next = p->next;
    p->next = newNode;
    return 1;
}

/*
 * ɾ��Ԫ��
 * �ɹ�����1��ʧ�ܷ���-1
 */
int listDelete(SLNode *head, int i, DataType *x)
{
    int j,listSize;
    SLNode *p,*q;

    listSize = listLength(head);
    if(i < 0 || i > (listSize-1))
    {
        printf("����i����!\n");
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

    free(q); //�ͷű�ɾ���ĵ�

    return 1;
}

/*
 * �޸ĵ������е�����
 * �ɹ�����1��ʧ�ܷ���-1
 */
int listEdit(SLNode *head, int i, DataType x)
{
    SLNode *p;
    int j,listSize;

    listSize = listLength(head);
    if(i < 0 || i > (listSize-1))
    {
        printf("����i����!\n");
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
 * ��ȡ�������е�����
 * �ɹ�����1��ʧ�ܷ���-1
 */
int listGet(SLNode *head, int i, DataType *x)
{
    SLNode *p;
    int j,listSize;

    listSize = listLength(head);
    if(i < 0 || i > (listSize-1))
    {
        printf("����i����!\n");
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
 * ��ӡ������
 * �������������͵�ʱ����
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
 * ���ٵ�����
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
