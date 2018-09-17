#ifndef __DIJKSTRAMINE_H__
#define __DIJKSTRAMINE_H__


//Ѱ��v0�±��Ӧ���㵽�������֮ǰ�ľ���
//nΪ�������
//path�������ڴ�Ų��ҵ������·��
//vertex�������·����Ѱ�Ҷ������
void dijkstraMine(AdjMGraph *graph,int v0,int n,int path[],DataType vertex[])
{
    int s[n];
    int i,index,temper,j;
    int minPath;
    //��ʼ��s����
    //�޸�s�е�����Ϊv0����������·������ֱ��·��Ϊֱ��·������ֱ��·��Ϊ�����

    for(i=0;i<n;i++)
    {
        s[i] = graph->edge[v0][i];
    }
    s[v0] = -1;

    //��ѡ��s��������̵�·��
    path[v0] = -1;
    vertex[0] = graph->vertices.list[v0];
    for(j=1;j<n;j++)   //�ظ�n-1���ҵ����·��
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

        path[index] = minPath;  //�������·��
        vertex[j] = graph->vertices.list[index];

        //�޸�s�е�ֵ�����޸�Դ�㵽��������֮ǰ��ֵ��
        s[index] = -1;
        for(i=0;i<n;i++)
        {
            temper = minPath + graph->edge[index][i]; //�����ղ��ҵ��ĵ㵽������ľ���
            if(temper < s[i])
                s[i] = temper;
        }
    }

}


#endif // __DIJKSTRAMINE_H__
