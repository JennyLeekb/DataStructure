#ifndef __PRIMMINE_H
#define __PRIMMINE_H

typedef struct
{
    verT vertex;
    int weight;
}PrimTree;

void primMine(AdjMGraph *graph, PrimTree tree[]);

//prim算法得到最小生成树
void primMine(AdjMGraph *graph, PrimTree tree[])
{
    int i,j,k;
    int nextVer; //下一个顶点的下标
    verT x;
    int lowWeight; //最小的权值
    int verNum = graph->vertices.size;  //顶点个数
    int u[verNum]; //集合u 用于保存已经访问的顶点，当值为-1时表示对应下标的顶点已经被访问过


    //从0下标的顶点开始走起
    //首先将0下标的顶点（A顶点）连接的边作为值传入u集合中
    for(i=0; i<verNum; i++)
        u[i] = graph->edge[0][i];

    u[0] = -1 ; //自身已经被访问
    listGet(&graph->vertices, 0, &x);  //获取初始顶点并加入生成树中
    tree[0].vertex = x;
    tree[0].weight = -1; //-1表示起始顶点

    for(i=1; i<verNum; i++)
    {
        lowWeight = MaxWeight;
        //获取初始顶点邻接边权值最小的顶点和对应的权值
        for(j=1; j<verNum; j++)
        {
            if(u[j] < lowWeight && u[j] != -1)
            {
                lowWeight = u[j];
                nextVer = j;
            }
        }

        //将获取的权值最小的顶点和对应的权值加入生成树中，并标记为已读
        listGet(&graph->vertices,nextVer,&x);
        tree[i].vertex = x;
        tree[i].weight = lowWeight;
        u[nextVer] = -1;

        //将获取的顶点的邻接边加入到集合u中
        for(k=1; k<verNum; k++)
        {
            if(graph->edge[nextVer][k] < u[k])
                u[k] = graph->edge[nextVer][k];
        }

    }


}




#endif // __PRIMMINE_H
