#ifndef __ADJMGRAPH_H__
#define __ADJMGRAPH_H__

#include "seqlist.h"

typedef struct
{
    SeqList vertices; //˳����Ŷ���
    int edge[MaxVertices][MaxVertices]; //��λ�����űߣ��ڽӾ����űߣ�
    int numsOfEdge; //�ߵ�����
}AdjMGraph; //ͼ�Ľṹ�嶨��

void init(AdjMGraph *graph, int n);
void insertVertex(AdjMGraph *graph,DataType vertex);
void insertEdge(AdjMGraph *graph, int v1, int v2, int weight);
void deleteEdge(AdjMGraph *graph, int v1, int v2);
int getFirstVex(AdjMGraph *graph, int v);
int getNextVex(AdjMGraph *graph, int v1, int v2);


//��ʼ����n������Ķ���˳�����ڽӾ���
void init(AdjMGraph *graph, int n)
{
    int i,j;
    for(i=0; i<n; i++)  //�ڽӾ����ʼ��
    {
        for(j=0; j<n; j++)
        {
            if(i == j)
                graph->edge[i][j] = 0;  //�ڽӾ���Խ���Ϊ0
            else
                graph->edge[i][j] = MaxWeight; //�����ȳ�ʼ��Ϊ���ֵ
        }
    }

    graph->numsOfEdge = 0;
    listInit(&graph->vertices);  //��Ŷ����˳����ʼ��
}


//��ͼ������һ������
void insertVertex(AdjMGraph *graph,DataType vertex)
{
    listInsert(&graph->vertices,graph->vertices.size,vertex); //��˳���β�����붥��
}

//��ͼ������һ�������<v1,v2>���ߵ�ȨֵΪweight
void insertEdge(AdjMGraph *graph, int v1, int v2, int weight)
{
    if(v1<0 || v1>=graph->vertices.size || v2<0 || v2>=graph->vertices.size)
    {
        printf("��������\n");
        return;
    }

    graph->edge[v1][v2] = weight;
    graph->numsOfEdge ++;
}

//��ͼ��ȡ��һ�������
void deleteEdge(AdjMGraph *graph, int v1, int v2)
{
    if(v1<0 || v1>=graph->vertices.size || v2<0 || v2>=graph->vertices.size)
    {
        printf("��������\n");
        return;
    }

    if(graph->edge[v1][v2] == MaxWeight || v1==v2)
    {
        printf("�ñ߲�����!\n");
        return;
    }

    graph->edge[v1][v2] = MaxWeight;
    graph->numsOfEdge --;
}

//��ȡ����v�ĵ�һ���ڽӶ���
int getFirstVex(AdjMGraph *graph, int v)
{
    int col;

    if(v<0 || v>=graph->vertices.size)
    {
        printf("��������!\n");
        return -1;
    }

    for(col=0; col<graph->vertices.size;col++)
    {
        if(graph->edge[v][col] != 0 && graph->edge[v][col] != MaxWeight)
            return col;
    }

    return -1;
}

//��ȡ����v1���ڽӶ���v2����һ���ڽӶ���
int getNextVex(AdjMGraph *graph, int v1, int v2)
{
    int column;

    if(v1<0 || v1>=graph->vertices.size || v2<0 || v2>=graph->vertices.size)
    {
        printf("��������\n");
        return -1;
    }

    for(column=v2+1; column<graph->vertices.size; column++)
    {
        if(graph->edge[v1][column] != 0 && graph->edge[v1][column] != MaxWeight)
            return column;
    }

    return -1;
}


#endif // __ADJMGRAPH_H__
