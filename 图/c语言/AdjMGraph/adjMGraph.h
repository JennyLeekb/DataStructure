#ifndef __ADJMGRAPH_H__
#define __ADJMGRAPH_H__

#include "seqlist.h"

typedef struct
{
    SeqList vertices; //顺序表存放顶点
    int edge[MaxVertices][MaxVertices]; //二位数组存放边（邻接矩阵存放边）
    int numsOfEdge; //边的条数
}AdjMGraph; //图的结构体定义

void init(AdjMGraph *graph, int n);
void insertVertex(AdjMGraph *graph,DataType vertex);
void insertEdge(AdjMGraph *graph, int v1, int v2, int weight);
void deleteEdge(AdjMGraph *graph, int v1, int v2);
int getFirstVex(AdjMGraph *graph, int v);
int getNextVex(AdjMGraph *graph, int v1, int v2);


//初始化有n个顶点的顶点顺序表和邻接矩阵
void init(AdjMGraph *graph, int n)
{
    int i,j;
    for(i=0; i<n; i++)  //邻接矩阵初始化
    {
        for(j=0; j<n; j++)
        {
            if(i == j)
                graph->edge[i][j] = 0;  //邻接矩阵对角线为0
            else
                graph->edge[i][j] = MaxWeight; //其它先初始化为最大值
        }
    }

    graph->numsOfEdge = 0;
    listInit(&graph->vertices);  //存放顶点的顺序表初始化
}


//在图中增加一个顶点
void insertVertex(AdjMGraph *graph,DataType vertex)
{
    listInsert(&graph->vertices,graph->vertices.size,vertex); //在顺序表尾部插入顶点
}

//在图中增加一条有向边<v1,v2>，边的权值为weight
void insertEdge(AdjMGraph *graph, int v1, int v2, int weight)
{
    if(v1<0 || v1>=graph->vertices.size || v2<0 || v2>=graph->vertices.size)
    {
        printf("参数错误！\n");
        return;
    }

    graph->edge[v1][v2] = weight;
    graph->numsOfEdge ++;
}

//在图中取消一条有向边
void deleteEdge(AdjMGraph *graph, int v1, int v2)
{
    if(v1<0 || v1>=graph->vertices.size || v2<0 || v2>=graph->vertices.size)
    {
        printf("参数错误！\n");
        return;
    }

    if(graph->edge[v1][v2] == MaxWeight || v1==v2)
    {
        printf("该边不存在!\n");
        return;
    }

    graph->edge[v1][v2] = MaxWeight;
    graph->numsOfEdge --;
}

//获取顶点v的第一个邻接顶点
int getFirstVex(AdjMGraph *graph, int v)
{
    int col;

    if(v<0 || v>=graph->vertices.size)
    {
        printf("参数错误!\n");
        return -1;
    }

    for(col=0; col<graph->vertices.size;col++)
    {
        if(graph->edge[v][col] != 0 && graph->edge[v][col] != MaxWeight)
            return col;
    }

    return -1;
}

//获取顶点v1的邻接顶点v2的下一个邻接顶点
int getNextVex(AdjMGraph *graph, int v1, int v2)
{
    int column;

    if(v1<0 || v1>=graph->vertices.size || v2<0 || v2>=graph->vertices.size)
    {
        printf("参数错误！\n");
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
