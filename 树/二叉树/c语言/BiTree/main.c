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

    printf("前序遍历:  ");
    preOrder(root->leftChild);
    printf("\n中序遍历： ");
    inOrder(root->leftChild);
    printf("\n后序遍历： ");
    postOrder(root->leftChild);

    find = search(root,'G');
    if(find == NULL)
        printf("\n数据元素不在树中！\n");
    else
        printf("\n数据元素在树中！\n");

    destroy(&root);

    return 0;
}
