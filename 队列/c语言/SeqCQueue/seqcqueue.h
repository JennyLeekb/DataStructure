#ifndef __SEQCQUEUE_H__
#define __SEQCQUEUE_H__

typedef struct
{
    DataType queue[MaxQueueSize];
    int rear;   //队尾指针
    int front;  //队头指针
    int count;  //计数器
}SeqCQueue;

//初始化循环队列
void initQueue(SeqCQueue *queue)
{
    queue->rear = 0;    //队头队尾指针初始指向 0 下标
    queue->front = 0;
    queue->count = 0;
}

//队列是否非空
int queueNotEmpty(SeqCQueue *queue)
{
    if(queue->count != 0)
        return 1;
    else
        return 0;
}

//入队列
int appendQueue(SeqCQueue *queue, DataType x)
{
    if(queue->count > 0 && queue->front == queue->rear) //队列已满
    {
        printf("队列已满无法插入!\n");
        return 0;
    }

    queue->queue[queue->rear] = x; //队尾插入元素
    queue->rear = (queue->rear+1) % MaxQueueSize; //队尾指示器加 1
    queue->count ++;

    return 1;
}


//出队列
int deleteQueue(SeqCQueue *queue, DataType *x)
{
    if(queue->count == 0)
    {
        printf("队列为空！\n");
        return 0;
    }

    *x = queue->queue[queue->front]; //取队头元素
    queue->front = (queue->front + 1) % MaxQueueSize; //队头指针加1
    queue->count --;

    return 1;
}

//取队头元素
int getQueue(SeqCQueue *queue, DataType *x)
{
    if(queue->count == 0)
    {
        printf("队列为空！\n");
        return 0;
    }

    *x = queue->queue[queue->front]; //取队头元素

    return 1;
}


#endif // __SEQCQUEUE_H__
