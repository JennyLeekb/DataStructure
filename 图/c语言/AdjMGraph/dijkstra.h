#ifndef __DIJKSTRA_H__
#define __DIJKSTRA_H__


//带权图G从下标V0顶点到其他顶点的最短距离distance 和 最短路径下标path
void dijkstra(AdjMGraph *graph, int v0,int distance[], int path[])
{
    int n = graph->vertices.size;
    int *s = (int *)malloc(sizeof(int)*n);
    int minDis, i, j, u;

    //初始化
    for(i=0; i<n; i++)
    {
        distance[i] = graph->edge[v0][i];
        s[i] = 0;
        if(i != v0 && distance[i] < MaxWeight)
            path[i] = v0;
        else
            path[i] = -1;
    }

    s[v0] = 1; //标记顶点v0已经从集合T加入集合S中

    //从当前还未找到最短路径的顶点集合中选取具有最短路径的顶点u
    for(i=1; i<n; i++)
    {
        minDis = MaxWeight;
        for(j=0; j<n; j++)
        {
            if(s[j] == 0 && distance[j] < minDis)
            {
                u = j;
                minDis = distance[j];
            }
        }

        //已经不再存在路径时，算法结束
        if(minDis == MaxWeight) return;

        s[u] = 1; //标记顶点u已经从集合T加入到集合s中
        //修改从v0到其他顶点的最短距离和最短路径
        for(j=0; j<n; j++)
        {
            if(s[j] == 0 && graph->edge[u][j] < MaxWeight &&
               distance[u] + graph->edge[u][j] < distance[j])
            {
                distance[j] = distance[u] + graph->edge[u][j];
                path[j] = u;
            }
        }
    }

}


#endif // __DIJKSTRA_H__
