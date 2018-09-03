#ifndef __THREADBITREE_H__
#define __THREADBITREE_H__

typedef struct Node
{
    DataType data;
    int leftThread; //左线索
    struct Node *leftChild; //左孩子
    int rightThread; //右线索
    struct Node *rightChild; //右孩子
    int isRead; //已读标志 1表示已读 0 表示未读
}ThreadBiNode;

void inThread(ThreadBiNode *curr, ThreadBiNode **pre);
void createInThread(ThreadBiNode **root);

//中序线索二叉树
//curr为当前结点的指针，pre为当前结点的中序前驱结点指针
void inThread(ThreadBiNode *curr, ThreadBiNode **pre)
{
    if(curr == NULL) return;

    inThread(curr->leftChild,pre); //中序线索化左子树
    if(curr->leftChild == NULL)
    {
        curr->leftThread = 1;  //建立左线索标记
        curr->leftChild = *pre; //建立左线索指针
    }
    else
        curr->leftThread = 0;

    if(curr->rightChild == NULL)
        curr->rightThread = 1;
    else
        curr->rightThread = 0;

    if((*pre)->rightChild == NULL)
    {
        (*pre)->rightThread = 1; //建立右索引标记
        (*pre)->rightChild = curr; //建立右索引指针
    }
    else
        (*pre)->rightThread = 0;


    *pre = curr;

    inThread(curr->rightChild,pre);

}


//建立中序索引化二叉树
void createInThread(ThreadBiNode **root)
{
    ThreadBiNode *curr, *pre,*threadRoot;

    //建立头结点
    threadRoot = (ThreadBiNode *)malloc(sizeof(ThreadBiNode));

    if((*root) == NULL) //如果是一棵空二叉树
    {
        threadRoot->leftThread = 0;
        threadRoot->leftChild = NULL;
        threadRoot->rightThread = 1;
        threadRoot->rightChild = NULL;
        threadRoot->isRead = 0;
    }
    else
    {
        threadRoot->leftThread = 0; //建立左线索标记
        threadRoot->leftChild = (*root)->leftChild; //建立左线索指针
        threadRoot->rightThread = 1;
        threadRoot->rightChild = NULL;
        threadRoot->isRead = 0;

        curr = threadRoot->leftChild;
        pre = threadRoot;

        inThread(curr,&pre); //线索化二叉树


        pre->rightThread = 1; //中序遍历最后一个结点的右孩子指向头结点
        pre->rightChild = threadRoot;
        threadRoot->rightThread = 1; //头结点的右孩子指向中序遍历最后一个结点
        threadRoot->rightChild = pre;
    }


    *root = threadRoot;
}


#endif // __THREADBITREE_H__
