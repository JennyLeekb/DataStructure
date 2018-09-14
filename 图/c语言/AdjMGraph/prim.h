#ifndef __PRIM_H__
#define __PRIM_H__


typedef struct
{
    verType vertex;  //����
    int weight;     //����Ϊ��ʼ�ߵ�Ȩֵ
}MinSpanTree;


//ʹ��prim�㷨������Ȩͼ����С������closeVertex
void prim(AdjMGraph *graph,MinSpanTree closeVertex[])
{
    verType x;
    int n = graph->vertices.size;
    int *lowCost = (int *)malloc(sizeof(int)*n);
    int minCost,i,j,k;

    for(i=1; i<n; i++)
        lowCost[i] = graph->edge[0][i]; //��ʼ��

    //�Ӷ���0����������С������
    listGet(&graph->vertices,0,&x);  //ȡ����0
    closeVertex[0].vertex = x;      //���涥��0
    lowCost[0] = -1;                //��Ƕ���0

    for(i=1; i<n; i++)
    {
        //Ѱ�ҵ�ǰ��СȨֵ�ı�����Ӧ�Ļ�β����k
        minCost = MaxWeight;
        for(j=1; j<n; j++)
        {
            if(lowCost[j]<minCost && lowCost[j]>0)
            {
                minCost = lowCost[j];
                k = j;
            }
        }

        listGet(&graph->vertices,k,&x); //ȡ��β����k
        closeVertex[i].vertex = x;      //���满β����k
        closeVertex[i].weight = minCost; //������Ӧ��Ȩֵ
        lowCost[k] = -1; //��Ƕ���k

        //����Ҫ���뼯��U�Ķ���k�޸�lowCost�е���ֵ
        for(j=1; j<n; j++)
        {
            if(graph->edge[k][j] < lowCost[j])
                lowCost[j] = graph->edge[k][j];
        }

    }


}


#endif // __PRIM_H__
