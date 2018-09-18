814. Binary Tree Pruning

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* pruneTree(TreeNode* root) {     
        
        if(root==NULL)
            return NULL;
        
        TreeNode* left = pruneTree(root->left);
        TreeNode* right = pruneTree(root->right);
        
        root->left=left;
        root->right = right;
        
        if(left==NULL&&right==NULL&&root->val==0)
            root = NULL;
 
        return root;
    }
};