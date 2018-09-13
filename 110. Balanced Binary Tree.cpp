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
    
    
    int find(TreeNode* root,int& flag)
    {
        if(root==NULL)
            return 0;
        
        int left = find(root->left,flag);
        int right = find(root->right,flag);
        
        if(left+1<right||right+1<left)
            flag=0;
        
        return max(left,right)+1;
    }
    
    bool isBalanced(TreeNode* root) {
        int flag = 1;
        find(root,flag);
        
        if(flag==1)
            return true;
        else
            return false;
    }
};