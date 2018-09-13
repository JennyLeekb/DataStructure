#ifndef __ADJMGRAPHCREATE_H__
#define __ADJMGRAPHCREATE_H__

#include "adjMGraph.h"

typedef struct
{
    int row; //行下标
    int col; //列下标
    int weight; //权值
}EdgeInfo;


//在图中插入n个顶点信息vex和e条边信息edge
void createGraph(AdjMGraph *graph, DataType vex[], int n, EdgeInfo edge[], int e)
{
    int i,k;

    init(graph,n); //初始化

    for(i=0; i<n; i++)
        insertVertex(graph,vex[i]);  //插入顶点

    for(k=0;k<e;k++)
        insertEdge(graph,edge[k].row,edge[k].col,edge[k].weight); //插入边
}


#endif // __ADJMGRAPHCREATE_H__
