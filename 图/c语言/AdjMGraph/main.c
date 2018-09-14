#include <stdio.h>
#include <stdlib.h>

#define MaxSize 10      //����˳�����������ֵ
#define MaxVertices 10  //���嶥������ֵ
#define MaxEdge 100     //����ߵ�������
#define MaxWeight 10000 //���������ľ���ֵ
#define MaxQueueSize 10 //����ѭ��������������ֵ

typedef char DataType;
typedef int QueueDataType;
typedef char verType;
typedef char verT;


#include "adjMGraph.h"
#include "adjMGraphCreate.h"
#include "traverse.h"
#include "prim.h"
#include "primMine.h"

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


    printf("������ȱ�������Ϊ��\n");
    dFSearchNotConnect(&graph,Visit);

    printf("\n");

    printf("������ȱ�������Ϊ�� \n");
    bFSearchNotConnect(&graph,Visit);   */



    AdjMGraph g;
    char a[] = {'A','B','C','D','E','F','G'};
    EdgeInfo edge[] = { {0,1,50},{1,0,50},{0,2,60},{2,0,60},{1,3,65},{3,1,65},
    {1,4,40},{4,1,40},{2,3,52},{3,2,52},{2,6,45},{6,2,45},{3,4,50},{4,3,50},
    {3,5,30},{5,3,30},{3,6,42},{6,3,42},{4,5,70},{5,4,70} };

    int n = 7, e = 20,i; //7�����㣬20����
    /*MinSpanTree closeVertex[7]; //���屣����С������������

    createGraph(&g,a,n,edge,e); //����ͼ
    prim(&g,closeVertex);

    //�����С�������Ķ������к�Ȩֵ����
    printf("��ʼ���� = %c\n", closeVertex[0].vertex);
    for(i=1;i<n;i++)
        printf("���� = %c   �ߵ�Ȩֵ = %d\n", closeVertex[i].vertex,closeVertex[i].weight);*/

    PrimTree tree[7]; //���屣����С������������

    createGraph(&g,a,n,edge,e); //����ͼ
    primMine(&g,tree);

    //�����С�������Ķ������к�Ȩֵ����
    printf("��ʼ���� = %c\n", tree[0].vertex);
    for(i=1;i<n;i++)
        printf("���� = %c   �ߵ�Ȩֵ = %d\n", tree[i].vertex,tree[i].weight);


    return 0;
}
