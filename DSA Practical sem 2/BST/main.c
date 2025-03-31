#include <stdio.h>
#include "../Timer.h"
#include "BST.h"

int main(void)
{
    StartTimer();
    
    Bst_t tree;
    Bst_t* pTree = &tree;
    BST_initialize(pTree);
    BST_insertData(pTree, 10);
    BST_insertData(pTree, 5);
    BST_insertData(pTree, 15);
    BST_insertData(pTree, 4);
    BST_insertData(pTree, 6);
    BST_insertData(pTree, 3);
    BST_insertData(pTree, 113);
    BST_insertData(pTree, 123);
    BST_insertData(pTree, 1);

    Node*   pTargetNode = NULL;
    int64_t iTarget     = 113;
    BST_searchData(pTree->m_pHead, iTarget, &pTargetNode);
    if (pTargetNode != NULL) { 
        printf("[ %lld ] found @ [ %p ]\n", iTarget, pTargetNode);
    } else {
        printf("[ %lld ] doesn't exist in given tree\n", iTarget);
    }

    pTargetNode = NULL;
    BST_findParentForData(pTree->m_pHead, 4, &pTargetNode);
    if (BST_deleteData(pTree, iTarget))
    {
        printf("deleted\n");
        printf("%p\n", pTree->m_pHead->m_pRight->m_pRight);
        printf("%p\n", pTree->m_pHead->m_pRight->m_pLeft);
    }
    else
    {
        printf("FAiled delete\n");
    }

    BST_printTree(pTree->m_pHead);
    
    int height = 0;
    BST_findHeight(pTree->m_pHead, &height);
    printf("Height : %d\n", height);

    EndTimer();
    return 0;
}