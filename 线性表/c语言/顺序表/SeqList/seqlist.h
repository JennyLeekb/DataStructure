#ifndef __SEQLIST_H__
#define __SEQLIST_H__

typedef struct
{
    DataType list[MaxSize]; //�洢����Ԫ�ص�����
    int size; //˳����е�ǰ�洢������Ԫ�ظ���
}SeqList;

void listInit(SeqList *seqList); //��ʼ��˳���
int listLength(SeqList *seqList); //��ǰԪ�صĸ���
int listInsert(SeqList *seqList, int i, DataType x); //��������Ԫ��
int listDelete(SeqList *seqList, int i, DataType *x); //ɾ��Ԫ��
int listGet(SeqList *seqList, int i, DataType *x); //ȡԪ��
int listEdit(SeqList *seqList, int i, DataType x); //�޸�Ԫ��

/*
 * ��ʼ��˳���
 */
void listInit(SeqList *seqList)
{
    seqList->size = 0; //�����ʼ����Ԫ�ظ���
}

/*
 * ��ǰ����Ԫ�ظ���
 */
int listLength(SeqList *seqList)
{
    return seqList->size;
}

/*
 * ��������Ԫ��,�ɹ�����1��ʧ�ܷ���-1
 */
int listInsert(SeqList *seqList, int i, DataType x)
{
    int j;
    if(seqList->size >= MaxSize)
    {
        printf("˳����������޷����룡\n");
        return -1;
    }
    if(i < 0 || i > seqList->size)
    {
        printf("����i���Ϸ���\n");
        return -1;
    }

    for(j = seqList->size; j > i; j--)//��������
    {
        seqList->list[j] = seqList->list[j-1];
    }

    seqList->list[i] = x; //����Ԫ��
    seqList->size++;

    return 1;
}

/*
 * ɾ��Ԫ��
 * ɾ��˳����е�i��Ԫ�أ������浽x��
 * �ɹ�����1��ʧ�ܷ���-1
 */
int listDelete(SeqList *seqList, int i, DataType *x)
{
    int j;
    if(seqList->size == 0)
    {
        printf("˳����ѿ�������Ԫ�ؿ�ɾ��\n");
        return -1;
    }

    if(i < 0 || i > seqList->size-1){
        printf("�������i����\n");
        return -1;
    }

    *x = seqList->list[i];
    for(j = i; j < seqList->size; j++)
    {
        seqList->list[j] = seqList->list[j+1]; //����Ǩ��
    }

    seqList->size --;

    return 1;
}

/*
 * ȡԪ��
 * ȡ��i��Ԫ�أ�����x��
 * �ɹ�����-1��ʧ�ܷ���1
 */
int listGet(SeqList *seqList, int i, DataType *x)
{
    if(seqList->size == 0)
    {
        printf("˳����ѿգ���Ԫ�ؿ�ȡ��\n");
        return -1;
    }

    if(i < 0 || i > seqList->size-1)
    {
        printf("�������i����\n");
        return -1;
    }

    *x = seqList->list[i];
    return 1;
}

/*
 * �޸�Ԫ��
 * �޸ĵ�i��λ�õ�Ԫ��
 * �ɹ�����1��ʧ�ܷ���-1
 */
int listEdit(SeqList *seqList, int i, DataType x)
{
    if(seqList->size == 0)
    {
        printf("˳����ѿգ���Ԫ�ؿ��޸ģ�\n");
        return -1;
    }

    if(i < 0 || i > seqList->size-1)
    {

        printf("�������i����\n");
        return -1;
    }

    seqList->list[i] = x;
    return 1;
}

#endif // __SEQLIST_H__
