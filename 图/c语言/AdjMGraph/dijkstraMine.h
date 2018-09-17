#ifndef __DIJKSTRAMINE_H__
#define __DIJKSTRAMINE_H__


//寻找v0下标对应顶点到其余各点之前的距离
//n为顶点个数
//path数组用于存放查找到的最短路径
//vertex保存最短路径的寻找顶点过程
void dijkstraMine(AdjMGraph *graph,int v0,int n,int path[],DataType vertex[])
{
    int s[n];
    int i,index,temper,j;
    int minPath;
    //初始化s集合
    //修改s中的数组为v0到其余各点的路径，有直接路径为直接路径，无直接路径为无穷大

    for(i=0;i<n;i++)
    {
        s[i] = graph->edge[v0][i];
    }
    s[v0] = -1;

    //挑选出s集合中最短的路径
    path[v0] = -1;
    vertex[0] = graph->vertices.list[v0];
    for(j=1;j<n;j++)   //重复n-1次找到最短路径
    {
        minPath = MaxWeight;
        for(i=0;i<n;i++)
        {
            if(s[i] < minPath && s[i] != -1)
            {
                minPath = s[i];
                index = i;
            }
        }

        path[index] = minPath;  //保存最短路径
        vertex[j] = graph->vertices.list[index];

        //修改s中的值（即修改源点到其他顶点之前的值）
        s[index] = -1;
        for(i=0;i<n;i++)
        {
            temper = minPath + graph->edge[index][i]; //经过刚才找到的点到其他点的距离
            if(temper < s[i])
                s[i] = temper;
        }
    }

}


#endif // __DIJKSTRAMINE_H__
