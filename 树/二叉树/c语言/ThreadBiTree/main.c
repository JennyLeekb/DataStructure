#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef char DataType;
#include "ThreadBiTree.h"
#include "InThreadIterator.h"

//������������㺯��
ThreadBiNode *createTreeNode(DataType item, ThreadBiNode *left, ThreadBiNode *right)
{
    ThreadBiNode *s;
    s = (ThreadBiNode *)malloc(sizeof(ThreadBiNode));
    s->data = item;
    s->leftChild = left;
    s->rightChild = right;
    s->isRead = 0;

    return s;
}

//����������
void createTree(ThreadBiNode *root)
{
    ThreadBiNode *a, *b, *c, *d, *e, *f, *g;

    g = createTreeNode('G',NULL,NULL);
    d = createTreeNode('D',NULL,g);
    b = createTreeNode('B',d,NULL);
    e = createTreeNode('E',NULL,NULL);
    f = createTreeNode('F',NULL,NULL);
    c = createTreeNode('C',e,f);
    a = createTreeNode('A',b,c);

    root->leftChild = a;
}


int main()
{
    ThreadBiNode *root,*start;
    printf("Hello world!\n");

    root = (ThreadBiNode *)malloc(sizeof(ThreadBiNode));
    start = root;
    root->leftChild = NULL;
    root->rightChild = NULL;

    createTree(root); //���������
    createInThread(&root); //��������������

    searchData(root,'A',&start);
    printf("****** %c \n",start->data);
    threadIterateForward(root,start);

    return 0;
}

