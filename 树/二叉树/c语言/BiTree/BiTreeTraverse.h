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

//ǰ����������ʲ���Ϊvisit����
void preOrder(BiTreeNode *root)
{
    if(root != NULL)
    {
        visit(root->data);
        preOrder(root->leftChild);
        preOrder(root->rightChild);
    }
}

//�������
void inOrder(BiTreeNode *root)
{
    if(root != NULL)
    {
        inOrder(root->leftChild);
        visit(root->data);
        inOrder(root->rightChild);
    }
}

//�������
void postOrder(BiTreeNode *root)
{
    if(root != NULL)
    {
        postOrder(root->leftChild);
        postOrder(root->rightChild);
        visit(root->data);
    }
}


//��ӡ�������������ʾ��
void printBiTree(BiTreeNode *root,int n) //nΪ��������
{
    int i;

    if(root == NULL) return;

    printBiTree(root->rightChild,n+1);

    //���ʸ����
    for(i=0;i<n-1;i++) printf("   ");
    if(n>0)
    {
        printf("---");
        printf("%c\n",root->data);
    }
    printBiTree(root->leftChild,n+1);
}

//��������Ԫ��
//�����ҳɹ������ظý���ָ�룬�����Ҳ��ɹ����ؿ�ָ��
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
