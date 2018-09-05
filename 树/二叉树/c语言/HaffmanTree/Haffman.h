#ifndef __HAFFMAN_H__
#define __HAFFMAN_H__
#include "malloc.h"

typedef char DataType;

typedef struct Node
{
    int weight;
    struct Node *leftChild;
    struct Node *rightChild;
}HaffNode;

HaffNode *getHaffNode(int weight,HaffNode *leftChild, HaffNode *rightChild);
HaffNode *getHaffTree(int weights[],int len);
HaffNode *getAndDelMin(HaffNode nodes[],int *len);
void addNum(HaffNode nodes[], int *len, HaffNode node);
void init(int weights[],HaffNode nodes[],int len);

//���ɽ��
HaffNode *getHaffNode(int weight,HaffNode *leftChild, HaffNode *rightChild)
{
    HaffNode *node;
    node = (HaffNode *)malloc(sizeof(HaffNode));
    node->weight = weight;
    node->leftChild = leftChild;
    node->rightChild = rightChild;
    return node;
}


//����Ȩֵ���ɹ�������
HaffNode *getHaffTree(int weights[],int len)
{
    HaffNode *root,*left,*right;
    HaffNode nodes[len];
    int temp;

    init(weights,nodes,len);

    while(len > 1)
    {
        left = getAndDelMin(nodes, &len); //��ȡ��Сֵ
        right = getAndDelMin(nodes,&len); //��ȡ��Сֵ

        temp = left->weight + right->weight;
        root = getHaffNode(temp,left,right);

        addNum(nodes,&len,*root);
    }

    return root;
}

//��ʼ�� ������ת��Ϊ���
void init(int weights[],HaffNode nodes[],int len)
{
    int i;
    HaffNode *temp;
    for(i=0;i<len;i++)
    {
        temp = getHaffNode(weights[i],NULL,NULL);
        nodes[i] = *temp;
    }
}

//��ȡ��Сֵ��������Сֵ��������ɾ��
//ͨ��len����ʶ����
HaffNode *getAndDelMin(HaffNode nodes[],int *len)
{
    int m,i,j;
    HaffNode *minNode;

    m = nodes[0].weight;
    j = 0;
    minNode = (HaffNode *)malloc(sizeof(HaffNode));

    for(i=0;i<(*len);i++)
    {
        if(nodes[i].weight < m)
        {
             m = nodes[i].weight;
             j = i;
        }
    }

    *minNode = nodes[j];

    for(i=j;i<(*len);i++)
    {
        nodes[i] = nodes[i+1];
    }

    (*len) = (*len)-1;

    return minNode;
}

//���������������
void addNum(HaffNode nodes[], int *len, HaffNode node)
{
    nodes[(*len)] = node;
    *len = *len + 1;
}


#endif // __HAFFMAN_H__
