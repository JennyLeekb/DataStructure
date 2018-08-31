#include <stdio.h>
#include <stdlib.h>

typedef char DataType;
#include "BiTree.h"
#include "BiTreeTraverse.h"



int main()
{
    printf("Hello world!\n");

    BiTreeNode *root,*p,*find;

    initiate(&root);

    p = insertLeftNode(root,'A');
    p = insertLeftNode(p,'B');
    p = insertLeftNode(p,'D');
    p = insertRightNode(p,'G');
    p = insertRightNode(root->leftChild,'C');
    insertLeftNode(p,'E');
    insertRightNode(p,'F');

    printBiTree(root,0);

    printf("ǰ�����:  ");
    preOrder(root->leftChild);
    printf("\n��������� ");
    inOrder(root->leftChild);
    printf("\n��������� ");
    postOrder(root->leftChild);

    find = search(root,'G');
    if(find == NULL)
        printf("\n����Ԫ�ز������У�\n");
    else
        printf("\n����Ԫ�������У�\n");

    destroy(&root);

    return 0;
}
