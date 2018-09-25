863. All Nodes Distance K in Binary Tree


We are given a binary tree (with root node root), a target node, and an integer value K.

Return a list of the values of all nodes that have a distance K from the target node.  The answer can be returned in any order.

 

Example 1:

Input: root = [3,5,1,6,2,0,8,null,null,7,4], target = 5, K = 2

Output: [7,4,1]

Explanation: 
The nodes that are a distance 2 from the target node (with value 5)
have values 7, 4, and 1.



Note that the inputs "root" and "target" are actually TreeNodes.
The descriptions of the inputs above are just serializations of these objects.
 

Note:

The given tree is non-empty.
Each node in the tree has unique values 0 <= node.val <= 500.
The target node is a node in the tree.
0 <= K <= 1000.


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
    
    void Print(TreeNode* head,int k,vector<int>& ret)
    {
        if(k==0){
            ret.push_back(head->val);
            return;
        }
        if(k<0)
            return;
        if(head->left!=NULL) Print(head->left,k-1,ret);
        if(head->right!=NULL) Print(head->right,k-1,ret);
    }
    
    int dfs(TreeNode* root,TreeNode* target,int k,vector<int>& ret)
    {
        if(root==target){
            Print(target,k,ret);
            return 1;
        }
        
        int left = 0,right = 0;
        if(root->left!=NULL) left = dfs(root->left,target,k,ret);
        if(root->right!=NULL) right = dfs(root->right,target,k,ret);
        
        if(left!=0&&root->right!=NULL) Print(root->right,k-left-1,ret);
        if(right!=0&&root->left!=NULL) Print(root->left,k-right-1,ret);
        
        
        if(left!=0||right!=0){
            if(max(left,right)==k)
                ret.push_back(root->val);
            return max(left,right)+1;

        }    
        return 0;
    }
    
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        vector<int> ret;
        if(root==NULL)
            return ret;
        dfs(root,target,K,ret);
        return ret;
    }
};