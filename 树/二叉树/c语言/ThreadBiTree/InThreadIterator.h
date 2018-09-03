#ifndef __INTHREADITERATOR_H__
#define __INTHREADITERATOR_H__

void searchData(ThreadBiNode *root, DataType data, ThreadBiNode **node);
void threadIterateForward(ThreadBiNode *root, ThreadBiNode *start);

//在线索二叉树中查找数据
void searchData(ThreadBiNode *root, DataType data, ThreadBiNode **node)
{
    if(root == NULL)
        return;

    if(root->data == data)
    {
        *node = root;
        return;
    }

    if(root->leftThread == 1 && root->rightThread == 1 )
        return;

    if(root->leftThread == 0)
        searchData(root->leftChild,data,node);
    if(root->rightThread == 0)
        searchData(root->rightChild,data,node);
}

//中序遍历，向前遍历二叉树
void threadIterateForward(ThreadBiNode *root, ThreadBiNode *start)
{
    ThreadBiNode *p;
    if(root == NULL || start == NULL)
        return;

    p = start;
    p->isRead = 1;

    while(p != root)
    {
        if(p->rightThread == 1)
        {
            if(!p->rightChild->isRead)
            {
                printf("%c -> ",p->data);
            }
            p->isRead = 1;
            p = p->rightChild;
        }
        else
        {
            if(p ->leftThread == 1)
            {
                printf("%c -> ",p->data);
                p->isRead = 1;
                p = p->rightChild;
            }
            else
            {
                if(p->leftChild->isRead)
                {
                    printf("%c -> ",p->data);
                    p->isRead = 1;
                    p = p->rightChild;
                }
                else
                    p = p->leftChild;
            }
        }
    }
}


#endif // __INTHREADITERATOR_H__
