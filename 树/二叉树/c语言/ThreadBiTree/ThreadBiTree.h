#ifndef __THREADBITREE_H__
#define __THREADBITREE_H__

typedef struct Node
{
    DataType data;
    int leftThread; //������
    struct Node *leftChild; //����
    int rightThread; //������
    struct Node *rightChild; //�Һ���
    int isRead; //�Ѷ���־ 1��ʾ�Ѷ� 0 ��ʾδ��
}ThreadBiNode;

void inThread(ThreadBiNode *curr, ThreadBiNode **pre);
void createInThread(ThreadBiNode **root);

//��������������
//currΪ��ǰ����ָ�룬preΪ��ǰ��������ǰ�����ָ��
void inThread(ThreadBiNode *curr, ThreadBiNode **pre)
{
    if(curr == NULL) return;

    inThread(curr->leftChild,pre); //����������������
    if(curr->leftChild == NULL)
    {
        curr->leftThread = 1;  //�������������
        curr->leftChild = *pre; //����������ָ��
    }
    else
        curr->leftThread = 0;

    if(curr->rightChild == NULL)
        curr->rightThread = 1;
    else
        curr->rightThread = 0;

    if((*pre)->rightChild == NULL)
    {
        (*pre)->rightThread = 1; //�������������
        (*pre)->rightChild = curr; //����������ָ��
    }
    else
        (*pre)->rightThread = 0;


    *pre = curr;

    inThread(curr->rightChild,pre);

}


//��������������������
void createInThread(ThreadBiNode **root)
{
    ThreadBiNode *curr, *pre,*threadRoot;

    //����ͷ���
    threadRoot = (ThreadBiNode *)malloc(sizeof(ThreadBiNode));

    if((*root) == NULL) //�����һ�ÿն�����
    {
        threadRoot->leftThread = 0;
        threadRoot->leftChild = NULL;
        threadRoot->rightThread = 1;
        threadRoot->rightChild = NULL;
        threadRoot->isRead = 0;
    }
    else
    {
        threadRoot->leftThread = 0; //�������������
        threadRoot->leftChild = (*root)->leftChild; //����������ָ��
        threadRoot->rightThread = 1;
        threadRoot->rightChild = NULL;
        threadRoot->isRead = 0;

        curr = threadRoot->leftChild;
        pre = threadRoot;

        inThread(curr,&pre); //������������


        pre->rightThread = 1; //����������һ�������Һ���ָ��ͷ���
        pre->rightChild = threadRoot;
        threadRoot->rightThread = 1; //ͷ�����Һ���ָ������������һ�����
        threadRoot->rightChild = pre;
    }


    *root = threadRoot;
}


#endif // __THREADBITREE_H__
