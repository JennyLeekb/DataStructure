#ifndef __PRIMMINE_H
#define __PRIMMINE_H

typedef struct
{
    verT vertex;
    int weight;
}PrimTree;

void primMine(AdjMGraph *graph, PrimTree tree[]);

//prim�㷨�õ���С������
void primMine(AdjMGraph *graph, PrimTree tree[])
{
    int i,j,k;
    int nextVer; //��һ��������±�
    verT x;
    int lowWeight; //��С��Ȩֵ
    int verNum = graph->vertices.size;  //�������
    int u[verNum]; //����u ���ڱ����Ѿ����ʵĶ��㣬��ֵΪ-1ʱ��ʾ��Ӧ�±�Ķ����Ѿ������ʹ�


    //��0�±�Ķ��㿪ʼ����
    //���Ƚ�0�±�Ķ��㣨A���㣩���ӵı���Ϊֵ����u������
    for(i=0; i<verNum; i++)
        u[i] = graph->edge[0][i];

    u[0] = -1 ; //�����Ѿ�������
    listGet(&graph->vertices, 0, &x);  //��ȡ��ʼ���㲢������������
    tree[0].vertex = x;
    tree[0].weight = -1; //-1��ʾ��ʼ����

    for(i=1; i<verNum; i++)
    {
        lowWeight = MaxWeight;
        //��ȡ��ʼ�����ڽӱ�Ȩֵ��С�Ķ���Ͷ�Ӧ��Ȩֵ
        for(j=1; j<verNum; j++)
        {
            if(u[j] < lowWeight && u[j] != -1)
            {
                lowWeight = u[j];
                nextVer = j;
            }
        }

        //����ȡ��Ȩֵ��С�Ķ���Ͷ�Ӧ��Ȩֵ�����������У������Ϊ�Ѷ�
        listGet(&graph->vertices,nextVer,&x);
        tree[i].vertex = x;
        tree[i].weight = lowWeight;
        u[nextVer] = -1;

        //����ȡ�Ķ�����ڽӱ߼��뵽����u��
        for(k=1; k<verNum; k++)
        {
            if(graph->edge[nextVer][k] < u[k])
                u[k] = graph->edge[nextVer][k];
        }

    }


}




#endif // __PRIMMINE_H
