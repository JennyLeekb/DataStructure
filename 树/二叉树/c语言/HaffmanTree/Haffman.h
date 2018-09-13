#ifndef __HAFFMAN_H__
#define __HAFFMAN_H__
#include "malloc.h"

#define MaxN 20

typedef char DataType;

typedef struct Node
{
    DataType data;
    int weight;
    struct Node *leftChild;
    struct Node *rightChild;
    struct Node *parent; //˫�׽��
    int code[1]; //����������
}HaffNode;

HaffNode *createLeaveNode(DataType data,int weight,HaffNode *leftChild, HaffNode *rightChild, HaffNode *parent);
HaffNode *createParentNode(DataType data,int weight,HaffNode *leftChild, HaffNode *rightChild);
HaffNode *getHaffTree(DataType datas[],int weights[],int len);
void getHaffCode(DataType data,HaffNode *root,int code[],int *len);
void getHaffNode(DataType data, HaffNode *root,HaffNode **node);
HaffNode *getAndDelMin(HaffNode nodes[],int *len);
void addNum(HaffNode nodes[], int *len, HaffNode node);
void init(DataType datas[],int weights[],HaffNode nodes[],int len);

//����Ҷ�ӽ��
HaffNode *createLeaveNode(DataType data, int weight, HaffNode *leftChild, HaffNode *rightChild, HaffNode *parent)
{
    HaffNode *node;
    node = (HaffNode *)malloc(sizeof(HaffNode));
    node->data = data;
    node->weight = weight;
    node->leftChild = leftChild;
    node->rightChild = rightChild;
    node->parent = parent;
    node->code[0] = -1;
    return node;
}

//���ɷ�Ҷ�ӽ��
HaffNode *createParentNode(DataType data,int weight,HaffNode *leftChild, HaffNode *rightChild)
{
    HaffNode *parent;
    parent = (HaffNode *)malloc(sizeof(HaffNode));
    parent->data = data;
    parent->weight = weight;
    parent->leftChild = leftChild;
    parent->rightChild = rightChild;
    parent->parent = NULL;
    parent->code[0] = -1;
    leftChild->parent = parent;
    leftChild->code[0] = 0;
    rightChild->parent = parent;
    rightChild->code[0] = 1;
    return parent;
}

//����Ȩֵ���ɹ�������
HaffNode *getHaffTree(DataType datas[],int weights[],int len)
{
    HaffNode *root,*left,*right;
    HaffNode nodes[len];
    int temp;

    init(datas,weights,nodes,len);

    while(len > 1)
    {
        left = getAndDelMin(nodes, &len); //��ȡ��Сֵ
        right = getAndDelMin(nodes,&len); //��ȡ��Сֵ

        temp = left->weight + right->weight;
        root = createParentNode('\0',temp,left,right);

        addNum(nodes,&len,*root);
    }

    return root;
}

//��ȡ����������
void getHaffCode(DataType data,HaffNode *root,int code[],int *len)
{
   HaffNode *p;
   int i;
   getHaffNode(data,root,&p);


   i=0;
   while(p != root)
   {
       code[i] = p->code[0];
       p = p->parent;
       i++;
    printf("code is %d\n",p->code[0]);
    if(p == NULL)
   {
       printf("data is wrong!\n");
       return;
   }
   }

   *len = i;
}


//�����ַ���ȡ��Ӧ�Ĺ��������Ľ��
void getHaffNode(DataType data, HaffNode *root,HaffNode **node)
{
    if(root == NULL) return;
    getHaffNode(data,root->leftChild,node);
    if(root->data == data)
    {
        *node = root;
        return;
    }
    getHaffNode(data,root->rightChild,node);

}



//��ʼ�� ������ת��Ϊ���
void init(DataType datas[],int weights[],HaffNode nodes[],int len)
{
    int i;
    HaffNode *temp;
    for(i=0;i<len;i++)
    {
        temp = createLeaveNode(datas[i],weights[i],NULL,NULL,NULL);
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
