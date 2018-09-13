#include <stdio.h>
#include <stdlib.h>

#define MaxSize 10      //����˳�����������ֵ
#define MaxVertices 10  //���嶥������ֵ
#define MaxWeight 10000 //���������ľ���ֵ
typedef char DataType;


#include "adjMGraph.h"
#include "adjMGraphCreate.h"


int main()
{
    AdjMGraph graph;
    DataType vex[] = {'a','b','c','d','e'};
    EdgeInfo edge[] = {{0,1,10},{0,4,20},{1,3,30},{2,1,40},{3,2,50}};
    int n = 5, e = 5;
    int i,j;

    createGraph(&graph,vex,n,edge,e); //����ͼ
    deleteEdge(&graph,0,4); //ɾ����<0,4>

    printf("���㼯��Ϊ��\n");
    for(i=0; i<graph.vertices.size; i++)
        printf("%c   ",graph.vertices.list[i]);
    printf("\n");

    printf("Ȩֵ����Ϊ��\n");
    for(i=0; i<graph.vertices.size; i++)
    {
        for(j=0; j<graph.vertices.size; j++)
            printf("%5d   ",graph.edge[i][j]);
        printf("\n");
    }


    return 0;
}
