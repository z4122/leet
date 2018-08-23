#include <stdio.h>

BinaryTreeNode* Convert(BinaryTreeNode* pRootOfTree)
{
    BinaryTreeNode* pLastNodeInList = nullptr;
    ConvertNode(pRootOfTree,&pLastNodeInList);



}


void ConvertNode(BinaryTreeNode* root,BinaryTreeNode ** pLastNodeInList)
{
    if(pNode==nullptr)
        return;
    BinaryTreeNode* current = root;
    if(root->left!=nullptr)
        ConvertNode(root->left,pLastNodeInList);
    
    current->left = *pLastNodeInList;
    (*pLastNodeInList)->right = current;
    *pLastNodeInList = current;

    if(root->right!=nullptr)
        ConvertNode(root->right,pLastNodeInList);

}