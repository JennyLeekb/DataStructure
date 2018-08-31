#ifndef __BITREETRAVERSE_H__
#define __BITREETRAVERSE_H__

void preOrder(BiTreeNode *root);
void inOrder(BiTreeNode *root);
void postOrder(BiTreeNode *root);
void printBiTree(BiTreeNode *root,int n);
BiTreeNode *search(BiTreeNode *root,DataType x);
void visit(DataType item);

void visit(DataType item)
{
    printf("%c ",item);
}

//前序遍历，访问操作为visit函数
void preOrder(BiTreeNode *root)
{
    if(root != NULL)
    {
        visit(root->data);
        preOrder(root->leftChild);
        preOrder(root->rightChild);
    }
}

//中序遍历
void inOrder(BiTreeNode *root)
{
    if(root != NULL)
    {
        inOrder(root->leftChild);
        visit(root->data);
        inOrder(root->rightChild);
    }
}

//后序遍历
void postOrder(BiTreeNode *root)
{
    if(root != NULL)
    {
        postOrder(root->leftChild);
        postOrder(root->rightChild);
        visit(root->data);
    }
}


//打印二叉树，凹入表示法
void printBiTree(BiTreeNode *root,int n) //n为缩进层数
{
    int i;

    if(root == NULL) return;

    printBiTree(root->rightChild,n+1);

    //访问根结点
    for(i=0;i<n-1;i++) printf("   ");
    if(n>0)
    {
        printf("---");
        printf("%c\n",root->data);
    }
    printBiTree(root->leftChild,n+1);
}

//查找数据元素
//若查找成功，返回该结点的指针，若查找不成功返回空指针
BiTreeNode *search(BiTreeNode *root,DataType x)
{
    BiTreeNode *find = NULL;

    if(root != NULL)
    {
        if(root->data == x)
            find = root;
        else
        {
            find = search(root->leftChild,x);
            if(find == NULL)
                find = search(root->rightChild,x);
        }
    }

    return find;
}


#endif // __BITREETRAVERSE_H__
