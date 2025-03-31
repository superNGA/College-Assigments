//=========================================================================
//                      BINARY SEARCH TREE
//=========================================================================
// by      : Rohan Prajapati
// created : 16/03/2025
// 
// purpose : Insertion, Deletion, Display & Seaching in binary search tree
//-------------------------------------------------------------------------
#pragma once
#include <stdbool.h>

typedef long long int   int64_t;
typedef long int        int32_t;
typedef short int       int16_t;
typedef char int8_t;

// 24 bytes
typedef struct Node
{
    int64_t      m_iData;  // 0x08
    struct Node* m_pRight; // 0x10
    struct Node* m_pLeft;  // 0x18
}Node;

typedef struct BinarySearchTree_t
{
    Node*   m_pHead;
    int32_t m_iHeight;
    bool    m_bIsEmpty;
    // 3 bytes left.
}Bst_t;


bool BST_initialize(Bst_t* pTree);
bool BST_insertData(Bst_t* pTree, int data);
void BST_findLeafNodeForData(Node* pHead, int data, Node** pNodeOut);
void BST_searchData(Node* pHead, int64_t dataToSearch, Node ** pNodeOut);
void BST_findParentForData(Node* pHead, int64_t dataToSearch, Node ** pNodeOut);
bool BST_deleteData(Bst_t* pTree, int64_t dataToDelete);
void BST_printTree(Node* pHead);
void BST_findHeight(Node* pHead, int* pHeightOut);