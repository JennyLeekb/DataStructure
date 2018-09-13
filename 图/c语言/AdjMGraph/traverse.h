#ifndef __TRAVERSE_H__
#define __TRAVERSE_H__

#include "adjMGraph.h"
#include "seqcqueue.h"

void dFSearchConnect(AdjMGraph *graph, int v, int visited[], void Visit(DataType item));
void dFSearchNotConnect(AdjMGraph *graph, void Visit(DataType item));
void bFSearchConnect(AdjMGraph *graph, int v, int visited[],void Visit(DataType item));
void bFSearchNotConnect(AdjMGraph *graph, void Visit(DataType item));

//��ͨͼ��������ȱ���
//v Ϊ��ʼ����
//���� Visited ��ʾ�����Ƿ�Ϊ���ʹ���0 ��ʾδ���ʣ� 1 ��ʾ�Ѿ�����
void dFSearchConnect(AdjMGraph *graph, int v, int visited[], void Visit(DataType item))
{
    int w;
    Visit(graph->vertices.list[v]); //���ʶ���v
    visited[v] = 1; //����Ѿ�������

    w = getFirstVex(graph,v); //��ȡv�ĵ�һ���ڽӶ���
    while(w != -1)
    {
        if(!visited[w])
            dFSearchConnect(graph,w,visited,Visit); //�ݹ���ȱ���
        w = getNextVex(graph,v,w); //��ȡ��һ���ڽӶ���
    }
}


//����ͨͼ��������ȱ���
void dFSearchNotConnect(AdjMGraph *graph, void Visit(DataType item))
{
    int i;
    int *visited = (int *)malloc(sizeof(int)*graph->vertices.size);

    for(i=0; i<graph->vertices.size; i++)
        visited[i] = 0; //��ʼ���Ϊδ����

    for(i=0; i<graph->vertices.size; i++)
        if(!visited[i])
            dFSearchConnect(graph,i,visited,Visit); //��ÿ��������Ϊ��ʼ�������

    free(visited);
}

//��ͨͼ�Ĺ�����ȱ���
//��vΪ��ʼ���㣬���й�����ȱ���
void bFSearchConnect(AdjMGraph *graph, int v, int visited[],void Visit(DataType item))
{
    QueueDataType u,w;
    SeqCQueue queue;

    Visit(graph->vertices.list[v]); //���ʶ���v
    visited[v] = 1;  //��Ƕ���v�Ѿ�������

    initQueue(&queue); //��ʼ������
    appendQueue(&queue,v); //v�����
    while(queueNotEmpty(&queue)) //�����в�Ϊ��ʱ
    {
        deleteQueue(&queue, &u);  //������
        w = getFirstVex(graph,u); //ȡ�õ�һ���ڽӶ���
        while(w != -1) //�ڽӶ������
        {
            if(!visited[w])  //��û�б�����
            {
                Visit(graph->vertices.list[w]); //���ʶ���w
                visited[w] = 1; //���Ϊ�ѷ���
                appendQueue(&queue,w); //�����
            }

            w = getNextVex(graph,u,w); //ȡ��һ���ڽӶ���
        }
    }
}


//����ͨͼ�Ĺ�����ȱ���
void bFSearchNotConnect(AdjMGraph *graph, void Visit(DataType item))
{
    int i;
    int *visited = (int *)malloc(sizeof(int)*graph->vertices.size);

    for(i=0;i<graph->vertices.size;i++)
        visited[i] = 0;

    for(i=0;i<graph->vertices.size;i++)
        if(!visited[i])
            bFSearchConnect(graph,i,visited,Visit);  //��ÿһ��������Ϊ��ʼ������е���

    free(visited);
}


#endif // __TRAVERSE_H__
