#ifndef __DIJKSTRA_H__
#define __DIJKSTRA_H__


//��ȨͼG���±�V0���㵽�����������̾���distance �� ���·���±�path
void dijkstra(AdjMGraph *graph, int v0,int distance[], int path[])
{
    int n = graph->vertices.size;
    int *s = (int *)malloc(sizeof(int)*n);
    int minDis, i, j, u;

    //��ʼ��
    for(i=0; i<n; i++)
    {
        distance[i] = graph->edge[v0][i];
        s[i] = 0;
        if(i != v0 && distance[i] < MaxWeight)
            path[i] = v0;
        else
            path[i] = -1;
    }

    s[v0] = 1; //��Ƕ���v0�Ѿ��Ӽ���T���뼯��S��

    //�ӵ�ǰ��δ�ҵ����·���Ķ��㼯����ѡȡ�������·���Ķ���u
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

        //�Ѿ����ٴ���·��ʱ���㷨����
        if(minDis == MaxWeight) return;

        s[u] = 1; //��Ƕ���u�Ѿ��Ӽ���T���뵽����s��
        //�޸Ĵ�v0�������������̾�������·��
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
