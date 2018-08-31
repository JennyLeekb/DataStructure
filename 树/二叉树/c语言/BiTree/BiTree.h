#ifndef __BITREE_H__
#define __BITREE_H__

typedef struct Node
{
    DataType data;
    struct Node *leftChild;
    struct Node *rightChild;
}BiTreeNode;


void initiate(BiTreeNode **root);
BiTreeNode *insertLeftNode(BiTreeNode *curr, DataType x);
BiTreeNode *insertRightNode(BiTreeNode *curr, DataType x);
BiTreeNode *deleteLeftTree(BiTreeNode *curr);
BiTreeNode *deleteRightTree(BiTreeNode *curr);
void destroy(BiTreeNode **root);

//初始化
void initiate(BiTreeNode **root)
{
    *root = (BiTreeNode *)malloc(sizeof(BiTreeNode));
    (*root)->leftChild = NULL;
    (*root)->rightChild = NULL;
}

//左插入结点
//若当前结点curr非空，则在curr的左子树插入元素值为x的新结点
//原curr所指向结点的左子树成为新插入结点的左子树
//若插入成功，则返回新插入结点的指针，否则，返回空指针
BiTreeNode *insertLeftNode(BiTreeNode *curr, DataType x)
{
    BiTreeNode *s, *t;

    if(curr == NULL) return NULL;

    t = curr->leftChild;
    s = (BiTreeNode *)malloc(sizeof(BiTreeNode));
    s->data = x;
    s->leftChild = t;
    s->rightChild = NULL;

    curr->leftChild = s;
    return s;
}


//右插入结点
BiTreeNode *insertRightNode(BiTreeNode *curr, DataType x)
{
    BiTreeNode *s, *t;

    if(curr == NULL) return NULL;

    t = curr->rightChild;
    s = (BiTreeNode *)malloc(sizeof(BiTreeNode));
    s->data = x;
    s->leftChild = NULL;
    s->rightChild = t;

    curr->rightChild = s;

    return s;
}


//左删除子树
//若curr非空，则删除curr指向的左子树
//若删除成功返回删除子树的双亲结点，否则返回空指针
BiTreeNode *deleteLeftTree(BiTreeNode *curr)
{
    if(curr == NULL) return NULL;

    destroy(&curr->leftChild);
    curr->leftChild = NULL;

    return curr;
}

//删除右子树
BiTreeNode *deleteRightTree(BiTreeNode *curr)
{
    if(curr == NULL) return NULL;

    destroy(&curr->rightChild);
    curr->rightChild = NULL;

    return curr;
}

//撤销二叉树
void destroy(BiTreeNode **root)
{
    if(((*root) != NULL) && ((*root)->leftChild != NULL))
    {
        destroy(&(*root)->leftChild);
    }

    if(((*root) != NULL) && ((*root)->rightChild != NULL))
    {
        destroy(&(*root)->rightChild);
    }

    free(*root);
}



#endif // __BITREE_H__
