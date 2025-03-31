//=========================================================================
//                      BINARY SEARCH TREE
//=========================================================================
// by      : Rohan Prajapati
// created : 16/03/2025
// 
// purpose : Insertion, Deletion, Display & Seaching in binary search tree
//-------------------------------------------------------------------------
#include "BST.h"
#include <Windows.h>
#include <stdio.h>


//=========================================================================
// bool __fastcall Initialize(Bst_t* pTree)
//=========================================================================
/**
* Initializes the Binary Search Tree
*
* @param pTree : pointer to the Bst_t object
**************************************************************************/
bool BST_initialize(Bst_t* pTree)
{
    pTree->m_pHead = NULL;
    pTree->m_iHeight = 0;
    pTree->m_bIsEmpty = true;

    return true;
}


//=========================================================================
// bool __fastcall InsertData(Bst_t* pTree, int data)
//=========================================================================
/**
* Insert data in Binary Tree
*
* @param pTree : pointer to Bst_t object
* @param data : data to insert
**************************************************************************/
bool BST_insertData(Bst_t* pTree, int data)
{
    // if tree is empty
    if (pTree->m_bIsEmpty == true)
    {
        Node* pNewNode = (Node*)malloc(sizeof(Node));
        if (pNewNode == NULL)
        {
            printf("Failed malloc for data [ %d ]\n", data);
            return false;
        }

        pNewNode->m_iData  = data;
        pNewNode->m_pLeft  = NULL;
        pNewNode->m_pRight = NULL;

        pTree->m_pHead     = pNewNode;
        pTree->m_bIsEmpty  = false;
        pTree->m_iHeight   = 1;
        printf("Successfully insearted [ %d ] as the head\n", data);
        return true;
    }

    // tree already has elements
    Node* pIdealLeaf = NULL;
    BST_findLeafNodeForData(pTree->m_pHead, data, &pIdealLeaf);
    if (pIdealLeaf == NULL)
    {
        printf("Failed to find ideal leaf node for inseartion of [ %d ]\n", data);
        return false;
    }

    Node* pNewNode = (Node*)malloc(sizeof(Node));
    if (pNewNode == NULL)
    {
        printf("Failed malloc for data [ %d ]\n", data);
        return false;
    }

    pNewNode->m_iData = data;
    pNewNode->m_pRight = NULL;
    pNewNode->m_pLeft = NULL;
    if (data > pIdealLeaf->m_iData)
    {
        printf("Insearting on right of [ %lld ] | ", pIdealLeaf->m_iData);
        pIdealLeaf->m_pRight = pNewNode;
    }
    else if (data < pIdealLeaf->m_iData)
    {
        printf("Insearting on left of [ %lld ] | ", pIdealLeaf->m_iData);
        pIdealLeaf->m_pLeft = pNewNode;
    }
    printf("Successfully insearted [ %d ] as a new node\n", data);
    return true;
}


//=========================================================================
// void __fastcall FindLeafNodeForData(Node* pHead, int data, Node** pNodeOut)
//=========================================================================
/**
* Finds the ideal parent node for given data.
*
* @param pHead : pointer to the head node of the Tree
* @param data : data to find parent for
* @param pNodeOut : pointer to pointer of ideal parent node which this function 
* will find, functoin will store the output here.
* NOTE : null this before passing it in.
**************************************************************************/
void BST_findLeafNodeForData(Node* pHead, int data, Node** pNodeOut)
{
    if (*pNodeOut != NULL || pNodeOut == NULL)
        return;

    if (data > pHead->m_iData)
    {
        if (pHead->m_pRight == NULL)
        {
            *pNodeOut = pHead;
            return;
        }
        BST_findLeafNodeForData(pHead->m_pRight, data, pNodeOut);
    }
    else if (data < pHead->m_iData)
    {
        if (pHead->m_pLeft == NULL)
        {
            *pNodeOut = pHead;
            return;
        }
        BST_findLeafNodeForData(pHead->m_pLeft, data, pNodeOut);
    }
}


//=========================================================================
// void __fastcall SearchData(Node* pHead, int dataToSearch, Node** pNodeOut)
//=========================================================================
/**
* Search for data in given tree and returns the adrs of the node
*
* @param pHead : pointer to head of the tree
* @param dataToSeach : target dat
* @param pNodeOut : pointer to poitner to target node. FN stores output here.
* NOTE : null this before passing it in.
**************************************************************************/
void BST_searchData(Node* pHead, int64_t dataToSearch, Node** pNodeOut)
{
    if (pHead == NULL || *pNodeOut != NULL)
        return;

    if (dataToSearch == pHead->m_iData)
    {
        *pNodeOut = pHead;
        return;
    }
    else if (dataToSearch > pHead->m_iData && pHead->m_pRight != NULL)
    {
        BST_searchData(pHead->m_pRight, dataToSearch, pNodeOut);
    }
    else if (dataToSearch < pHead->m_iData && pHead->m_pLeft != NULL)
    {
        BST_searchData(pHead->m_pLeft, dataToSearch, pNodeOut);
    }
}


//=========================================================================
// void BST_findParentForData(Node* pHead, int64_t dataToSearch, Node** pNodeOut)
//=========================================================================
/**
* finds & returns parent node for given data
*
* @param pHead : pointer to the head of the tree
* @param dataToSearch : data whose parents are to be found
* @param pNodeOut : output will be stored here, pass in adrs of a Node*
**************************************************************************/
void BST_findParentForData(Node* pHead, int64_t dataToSearch, Node** pNodeOut)
{
    static Node* pLastNode = NULL;
    if (pHead == NULL || *pNodeOut != NULL)
        return;

    if (pHead->m_iData == dataToSearch)
    {
        printf("Match found | parent data : %lld\n", pLastNode == NULL ? 0 : pLastNode->m_iData);
        *pNodeOut = pLastNode;
        return;
    }
    else if (dataToSearch > pHead->m_iData && pHead->m_pRight != NULL)
    {
        pLastNode = pHead;
        BST_findParentForData(pHead->m_pRight, dataToSearch, pNodeOut);
    }
    else if (dataToSearch < pHead->m_iData && pHead->m_pLeft != NULL)
    {
        pLastNode = pHead;
        BST_findParentForData(pHead->m_pLeft, dataToSearch, pNodeOut);
    }
}


//=========================================================================
// bool BST_deleteData(Bst_t* pTree, int64_t dataToDelete)
//=========================================================================
/**
* Deletes data from given Binary Search Tree
*
* @param pTree : pointer to tree's Bst_t object
* @param dataToDelete : data to delete
**************************************************************************/
bool BST_deleteData(Bst_t* pTree, int64_t dataToDelete)
{
    if (pTree == NULL || pTree->m_bIsEmpty == true)
        return false;

    Node* pTemp = NULL;
    Node* pHead = NULL;
    Node* pParent = NULL;
    bool bIsHeadModified = false;
    bool bIsLeft = false;
    if (dataToDelete == pTree->m_pHead->m_iData)
    {
        printf("Trying to delete head\n");
        bIsHeadModified = true;
        pHead = pTree->m_pHead;
    }
    else
    {
        printf("Not deleting head\n");
        BST_findParentForData(pTree->m_pHead, dataToDelete, &pParent);
        if (pParent != NULL)
            pHead = (pParent->m_pLeft != NULL && pParent->m_pLeft->m_iData == dataToDelete) ? pParent->m_pLeft : pParent->m_pRight;
        else return false;
    }

    int8_t nChildren = (pHead->m_pRight != NULL) + (pHead->m_pLeft != NULL);
    switch (nChildren)
    {
    case 0: // if head has no children then delete the head
        printf("No Children\n");
        if (bIsHeadModified == false)
        {
            pParent->m_pLeft  = NULL;
            pParent->m_pRight = NULL;
        }
        free(pHead);
        return true;

    case 1: // if has only one children
        printf("1 Children\n");
        // if left in NULL then we know that only right child is valid.
        bool bIsRight = (pHead->m_pLeft == NULL);
        pTemp = NULL;
        if (bIsHeadModified)
        {
            if (bIsRight)
            {
                pTemp = pHead->m_pRight;
            }
            else
            {
                pTemp = pHead->m_pLeft;
            }
            free(pHead);
            pHead = pTemp; // <- replacing head with child node
            return true;
        }
        
        bIsLeft = (pParent->m_pLeft != NULL && pParent->m_pLeft->m_iData == dataToDelete);
        if (bIsLeft)
        {
            pParent->m_pLeft = (bIsRight ? pHead->m_pRight : pHead->m_pLeft);
        }
        else
        {
            pParent->m_pRight = (bIsRight ? pHead->m_pRight : pHead->m_pLeft);
        }
        free(pHead);
        return true;
        break;

    case 2: // If has 2 children
        printf("2 Children\n");
        pTemp = pHead->m_pRight;
        // get to node smallest Node
        while (pTemp->m_pLeft != NULL)
        {
            printf("@ %lld\n", pTemp->m_iData);
            pTemp = pTemp->m_pLeft;
        }

        // point the smallest node to the left pointer of the head of the tree
        pTemp->m_pLeft = pHead->m_pLeft;
        if (bIsHeadModified == true) // If we deleted head
        {
            pTemp = pHead;
            pTree->m_pHead = pTree->m_pHead->m_pRight;
            free(pTemp); // free head
            return true;
        }

        // if we modified node other than the Head
        bIsLeft = (pParent->m_pLeft->m_iData == dataToDelete);
        if (bIsLeft)
        {
            pTemp = pParent->m_pLeft;
            pParent->m_pLeft = pParent->m_pLeft->m_pRight;
            free(pTemp);
        }
        else
        {
            pTemp = pParent->m_pRight;
            pParent->m_pRight = pParent->m_pRight->m_pRight;
            free(pTemp);
        }
        return true;

    default:
        return false;
    }

}


#define INDENTATION_FILLER1   "    "
#define INDENTATION_FILLER2   "   |"
#define INDENTATION_FINISHER  "--->"
//=========================================================================
// void BST_printTree(Node* pHead)
//=========================================================================
/**
* Prints out the Binary Search Tree in a indentation seperated manner
*
* @param pHead : pointer to head of the tree
**************************************************************************/
void BST_printTree(Node* pHead)
{
    static int iIndent = -1;
    
    if (pHead == NULL)
        return;

    iIndent++;
    for (int i = 0; i < iIndent - 1; i++)
    {
        printf(INDENTATION_FILLER2);
    }
    if(iIndent) 
    {
        printf(INDENTATION_FINISHER);
    }
    printf("%lld\n", pHead->m_iData);
    BST_printTree(pHead->m_pLeft);
    BST_printTree(pHead->m_pRight);
    
    iIndent--;
}


//=========================================================================
// void FindHeight(Node* pHead, int* pHeightOut)
//=========================================================================
/**
* returns the height of the tree, considering head as 1
*
* @param pHead : pointer to head of the tree
* @param pHeightOut : pointer to 2 byte int. Output stored here.
**************************************************************************/
void BST_findHeight(Node* pHead, int* pHeightOut)
{
    static int iTempStorage = 0;
    iTempStorage++;

    if (iTempStorage > *pHeightOut)
        *pHeightOut = iTempStorage;

    if (pHead == NULL || pHeightOut == NULL)
        return;

    if (pHead->m_pLeft != NULL)
    {
        BST_findHeight(pHead->m_pLeft, pHeightOut);
    }

    if (pHead->m_pRight != NULL)
    {
        BST_findHeight(pHead->m_pRight, pHeightOut);
    }

    iTempStorage--;
}