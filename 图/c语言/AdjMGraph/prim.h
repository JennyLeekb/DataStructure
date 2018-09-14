#ifndef __PRIM_H__
#define __PRIM_H__


typedef struct
{
    verType vertex;  //顶点
    int weight;     //顶点为起始边的权值
}MinSpanTree;


//使用prim算法建立带权图的最小生成树closeVertex
void prim(AdjMGraph *graph,MinSpanTree closeVertex[])
{
    verType x;
    int n = graph->vertices.size;
    int *lowCost = (int *)malloc(sizeof(int)*n);
    int minCost,i,j,k;

    for(i=1; i<n; i++)
        lowCost[i] = graph->edge[0][i]; //初始化

    //从顶点0出发构造最小生成树
    listGet(&graph->vertices,0,&x);  //取顶点0
    closeVertex[0].vertex = x;      //保存顶点0
    lowCost[0] = -1;                //标记顶点0

    for(i=1; i<n; i++)
    {
        //寻找当前最小权值的边所对应的弧尾顶点k
        minCost = MaxWeight;
        for(j=1; j<n; j++)
        {
            if(lowCost[j]<minCost && lowCost[j]>0)
            {
                minCost = lowCost[j];
                k = j;
            }
        }

        listGet(&graph->vertices,k,&x); //取弧尾顶点k
        closeVertex[i].vertex = x;      //保存弧尾顶点k
        closeVertex[i].weight = minCost; //保存相应的权值
        lowCost[k] = -1; //标记顶点k

        //根据要加入集合U的顶点k修改lowCost中的数值
        for(j=1; j<n; j++)
        {
            if(graph->edge[k][j] < lowCost[j])
                lowCost[j] = graph->edge[k][j];
        }

    }


}


#endif // __PRIM_H__
