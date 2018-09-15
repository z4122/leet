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
113. Path Sum II

Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.

Note: A leaf is a node with no children.

Example:

Given the below binary tree and sum = 22,

      5
     / \
    4   8
   /   / \
  11  13  4
 /  \    / \
7    2  5   1
Return:

[
   [5,4,11,2],
   [5,8,4,5]
]



public:
    vector<vector<int>> dfs(TreeNode* head,int sum)
    {
        vector<vector<int>> ret,left,right;
        vector<int> temp;
        
        if(head->left==NULL&&head->right==NULL&&sum==head->val){
            temp.push_back(head->val);
            ret.push_back(temp);
            return ret;
        }
        
        if(head->left!=NULL) left = dfs(head->left,sum-head->val);
        if(head->right!=NULL) right = dfs(head->right,sum-head->val);
        
        

        if(left.size()!=0)
        {
            for(int i = 0;i<left.size();i++)
            {
                temp.push_back(head->val);
                temp.insert(temp.end(),left[i].begin(),left[i].end());
                ret.push_back(temp);
                temp.clear();
            }
           
        }
        if(right.size()!=0)
        {
            for(int i = 0;i<right.size();i++)
            {
                temp.push_back(head->val);
                temp.insert(temp.end(),right[i].begin(),right[i].end());
                ret.push_back(temp);
                temp.clear();
            }
           
        }
        
        return ret;
    }
    
    
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> temp;
        if(root==NULL)
            return temp;
        return dfs(root,sum);        
    }
};