#ifndef __SEQCQUEUE_H__
#define __SEQCQUEUE_H__

typedef struct
{
    DataType queue[MaxQueueSize];
    int rear;   //��βָ��
    int front;  //��ͷָ��
    int count;  //������
}SeqCQueue;

//��ʼ��ѭ������
void initQueue(SeqCQueue *queue)
{
    queue->rear = 0;    //��ͷ��βָ���ʼָ�� 0 �±�
    queue->front = 0;
    queue->count = 0;
}

//�����Ƿ�ǿ�
int queueNotEmpty(SeqCQueue *queue)
{
    if(queue->count != 0)
        return 1;
    else
        return 0;
}

//�����
int appendQueue(SeqCQueue *queue, DataType x)
{
    if(queue->count > 0 && queue->front == queue->rear) //��������
    {
        printf("���������޷�����!\n");
        return 0;
    }

    queue->queue[queue->rear] = x; //��β����Ԫ��
    queue->rear = (queue->rear+1) % MaxQueueSize; //��βָʾ���� 1
    queue->count ++;

    return 1;
}


//������
int deleteQueue(SeqCQueue *queue, DataType *x)
{
    if(queue->count == 0)
    {
        printf("����Ϊ�գ�\n");
        return 0;
    }

    *x = queue->queue[queue->front]; //ȡ��ͷԪ��
    queue->front = (queue->front + 1) % MaxQueueSize; //��ͷָ���1
    queue->count --;

    return 1;
}

//ȡ��ͷԪ��
int getQueue(SeqCQueue *queue, DataType *x)
{
    if(queue->count == 0)
    {
        printf("����Ϊ�գ�\n");
        return 0;
    }

    *x = queue->queue[queue->front]; //ȡ��ͷԪ��

    return 1;
}


#endif // __SEQCQUEUE_H__
