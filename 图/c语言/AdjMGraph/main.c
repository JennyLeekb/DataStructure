#include <stdio.h>
#include <stdlib.h>

#define MaxSize 10      //定义顺序表数组的最大值
#define MaxVertices 10  //定义顶点的最大值
#define MaxEdge 100     //定义边的最大个数
#define MaxWeight 10000 //定义无穷大的具体值
#define MaxQueueSize 10 //定义循环队列数组的最大值

typedef char DataType;
typedef int QueueDataType;


#include "adjMGraph.h"
#include "adjMGraphCreate.h"
#include "traverse.h"

void Visit(DataType item)
{
    printf("%c   ",item);
}

int main()
{
    AdjMGraph graph;
    DataType vex[] = {'a','b','c','d','e'};
    EdgeInfo edge[] = {{0,1,10},{0,4,20},{1,3,30},{2,1,40},{3,2,50}};
    int n = 5, e = 5;
    int i,j;

    createGraph(&graph,vex,n,edge,e); //生成图
    /*deleteEdge(&graph,0,4); //删除边<0,4>

    printf("顶点集合为：\n");
    for(i=0; i<graph.vertices.size; i++)
        printf("%c   ",graph.vertices.list[i]);
    printf("\n");

    printf("权值集合为：\n");
    for(i=0; i<graph.vertices.size; i++)
    {
        for(j=0; j<graph.vertices.size; j++)
            printf("%5d   ",graph.edge[i][j]);
        printf("\n");
    }*/

    printf("深度优先遍历序列为：\n");
    dFSearchNotConnect(&graph,Visit);

    printf("\n");

    printf("广度优先遍历序列为： \n");
    bFSearchNotConnect(&graph,Visit);


    return 0;
}
