#ifndef __TRAVERSE_H__
#define __TRAVERSE_H__

#include "adjMGraph.h"
#include "seqcqueue.h"

void dFSearchConnect(AdjMGraph *graph, int v, int visited[], void Visit(DataType item));
void dFSearchNotConnect(AdjMGraph *graph, void Visit(DataType item));
void bFSearchConnect(AdjMGraph *graph, int v, int visited[],void Visit(DataType item));
void bFSearchNotConnect(AdjMGraph *graph, void Visit(DataType item));

//连通图的深度优先遍历
//v 为初始顶点
//数组 Visited 表示顶点是否为访问过，0 表示未访问， 1 表示已经访问
void dFSearchConnect(AdjMGraph *graph, int v, int visited[], void Visit(DataType item))
{
    int w;
    Visit(graph->vertices.list[v]); //访问顶点v
    visited[v] = 1; //标记已经被访问

    w = getFirstVex(graph,v); //获取v的第一个邻接顶点
    while(w != -1)
    {
        if(!visited[w])
            dFSearchConnect(graph,w,visited,Visit); //递归深度遍历
        w = getNextVex(graph,v,w); //获取下一个邻接顶点
    }
}


//非连通图的深度优先遍历
void dFSearchNotConnect(AdjMGraph *graph, void Visit(DataType item))
{
    int i;
    int *visited = (int *)malloc(sizeof(int)*graph->vertices.size);

    for(i=0; i<graph->vertices.size; i++)
        visited[i] = 0; //初始标记为未访问

    for(i=0; i<graph->vertices.size; i++)
        if(!visited[i])
            dFSearchConnect(graph,i,visited,Visit); //以每个顶点作为初始顶点调用

    free(visited);
}

//连通图的广度优先遍历
//以v为初始顶点，进行广度优先遍历
void bFSearchConnect(AdjMGraph *graph, int v, int visited[],void Visit(DataType item))
{
    QueueDataType u,w;
    SeqCQueue queue;

    Visit(graph->vertices.list[v]); //访问顶点v
    visited[v] = 1;  //标记顶点v已经被访问

    initQueue(&queue); //初始化队列
    appendQueue(&queue,v); //v入队列
    while(queueNotEmpty(&queue)) //当队列不为空时
    {
        deleteQueue(&queue, &u);  //出队列
        w = getFirstVex(graph,u); //取得第一个邻接顶点
        while(w != -1) //邻接顶点存在
        {
            if(!visited[w])  //若没有被访问
            {
                Visit(graph->vertices.list[w]); //访问顶点w
                visited[w] = 1; //标记为已访问
                appendQueue(&queue,w); //入队列
            }

            w = getNextVex(graph,u,w); //取下一个邻接顶点
        }
    }
}


//非连通图的广度优先遍历
void bFSearchNotConnect(AdjMGraph *graph, void Visit(DataType item))
{
    int i;
    int *visited = (int *)malloc(sizeof(int)*graph->vertices.size);

    for(i=0;i<graph->vertices.size;i++)
        visited[i] = 0;

    for(i=0;i<graph->vertices.size;i++)
        if(!visited[i])
            bFSearchConnect(graph,i,visited,Visit);  //以每一个顶点作为初始顶点进行调用

    free(visited);
}


#endif // __TRAVERSE_H__
