#include <stdio.h>
#include <stdlib.h>

#define MaxSize 10      //����˳�����������ֵ
#define MaxVertices 10  //���嶥������ֵ
#define MaxEdge 100     //����ߵ�������
#define MaxWeight 10000 //���������ľ���ֵ
#define MaxQueueSize 10 //����ѭ��������������ֵ

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

    createGraph(&graph,vex,n,edge,e); //����ͼ
    /*deleteEdge(&graph,0,4); //ɾ����<0,4>

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
    }*/

    printf("������ȱ�������Ϊ��\n");
    dFSearchNotConnect(&graph,Visit);

    printf("\n");

    printf("������ȱ�������Ϊ�� \n");
    bFSearchNotConnect(&graph,Visit);


    return 0;
}
