#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#define MaxSize 10      //定义顺序表数组的最大值
#define MaxVertices 10  //定义顶点的最大值
#define MaxEdge 100     //定义边的最大个数
#define MaxWeight 10000 //定义无穷大的具体值
#define MaxQueueSize 10 //定义循环队列数组的最大值

typedef char DataType;
typedef int QueueDataType;
typedef char verType;
typedef char verT;


#include "adjMGraph.h"
#include "adjMGraphCreate.h"
#include "traverse.h"
#include "prim.h"
#include "primMine.h"
#include "dijkstra.h"

void Visit(DataType item)
{
    printf("%c   ",item);
}

int main()
{
    /*AdjMGraph graph;
    DataType vex[] = {'a','b','c','d','e'};
    EdgeInfo edge[] = {{0,1,10},{0,4,20},{1,3,30},{2,1,40},{3,2,50}};
    int n = 5, e = 5;
    int i,j;

    createGraph(&graph,vex,n,edge,e); //生成图
    deleteEdge(&graph,0,4); //删除边<0,4>

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
    }


    printf("深度优先遍历序列为：\n");
    dFSearchNotConnect(&graph,Visit);

    printf("\n");

    printf("广度优先遍历序列为： \n");
    bFSearchNotConnect(&graph,Visit);   */



    /*AdjMGraph g;
    char a[] = {'A','B','C','D','E','F','G'};
    EdgeInfo edge[] = { {0,1,50},{1,0,50},{0,2,60},{2,0,60},{1,3,65},{3,1,65},
    {1,4,40},{4,1,40},{2,3,52},{3,2,52},{2,6,45},{6,2,45},{3,4,50},{4,3,50},
    {3,5,30},{5,3,30},{3,6,42},{6,3,42},{4,5,70},{5,4,70} };

    int n = 7, e = 20,i; //7个顶点，20条边*/
    /*MinSpanTree closeVertex[7]; //定义保存最小生成树的数组

    createGraph(&g,a,n,edge,e); //创建图
    prim(&g,closeVertex);

    //输出最小生成树的顶点序列和权值序列
    printf("初始顶点 = %c\n", closeVertex[0].vertex);
    for(i=1;i<n;i++)
        printf("顶点 = %c   边的权值 = %d\n", closeVertex[i].vertex,closeVertex[i].weight);*/

    /*PrimTree tree[7]; //定义保存最小生成树的数组

    createGraph(&g,a,n,edge,e); //创建图
    primMine(&g,tree);

    //输出最小生成树的顶点序列和权值序列
    printf("初始顶点 = %c\n", tree[0].vertex);
    for(i=1;i<n;i++)
        printf("顶点 = %c   边的权值 = %d\n", tree[i].vertex,tree[i].weight);*/


    AdjMGraph g;
    char a[] = {'A','B','C','D','E','F'};
    EdgeInfo edge[] = { {0,2,5},{0,3,30},{1,0,2},{1,4,8},{2,1,15},
    {2,5,7},{4,3,4},{5,3,10},{5,4,18} };

    int i,n=6,e=9;
    int distance[6],path[9];

    createGraph(&g,a,n,edge,e);

    dijkstra(&g,0,distance,path);

    printf("从顶点%c到其他各点的最短路径为：\n",g.vertices.list[0]);
    for(i=0;i<n;i++)
        printf("到顶点%c的最短路径为%d\n",g.vertices.list[i],distance[i]);

    printf("从顶点%c到其他各个顶点最短路径的前一顶点为：\n",g.vertices.list[0]);
    for(i=0;i<n;i++)
        if(path[i] != -1)
            printf("到顶点%c前一顶点为%c\n",g.vertices.list[i],g.vertices.list[path[i]]);

    return 0;
}
