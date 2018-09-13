#ifndef __ADJMGRAPHCREATE_H__
#define __ADJMGRAPHCREATE_H__

#include "adjMGraph.h"

typedef struct
{
    int row; //���±�
    int col; //���±�
    int weight; //Ȩֵ
}EdgeInfo;


//��ͼ�в���n��������Ϣvex��e������Ϣedge
void createGraph(AdjMGraph *graph, DataType vex[], int n, EdgeInfo edge[], int e)
{
    int i,k;

    init(graph,n); //��ʼ��

    for(i=0; i<n; i++)
        insertVertex(graph,vex[i]);  //���붥��

    for(k=0;k<e;k++)
        insertEdge(graph,edge[k].row,edge[k].col,edge[k].weight); //�����
}


#endif // __ADJMGRAPHCREATE_H__
