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

//��ʼ��
void initiate(BiTreeNode **root)
{
    *root = (BiTreeNode *)malloc(sizeof(BiTreeNode));
    (*root)->leftChild = NULL;
    (*root)->rightChild = NULL;
}

//�������
//����ǰ���curr�ǿգ�����curr������������Ԫ��ֵΪx���½��
//ԭcurr��ָ�������������Ϊ�²������������
//������ɹ����򷵻��²������ָ�룬���򣬷��ؿ�ָ��
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


//�Ҳ�����
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


//��ɾ������
//��curr�ǿգ���ɾ��currָ���������
//��ɾ���ɹ�����ɾ��������˫�׽�㣬���򷵻ؿ�ָ��
BiTreeNode *deleteLeftTree(BiTreeNode *curr)
{
    if(curr == NULL) return NULL;

    destroy(&curr->leftChild);
    curr->leftChild = NULL;

    return curr;
}

//ɾ��������
BiTreeNode *deleteRightTree(BiTreeNode *curr)
{
    if(curr == NULL) return NULL;

    destroy(&curr->rightChild);
    curr->rightChild = NULL;

    return curr;
}

//����������
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
