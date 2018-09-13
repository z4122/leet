199. Binary Tree Right Side View

Given a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.

Example:

Input: [1,2,3,null,5,null,4]
Output: [1, 3, 4]
Explanation:

   1            <---
 /   \
2     3         <---
 \     \
  5     4       <---


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
    vector<int> rightSideView(TreeNode* root) {
      
        stack<pair<TreeNode*,int>> s;
        pair<TreeNode*,int> temp;
        vector<int> output;
        s.push(make_pair(root,1));
          if(root==NULL)
            return output;
        while(!s.empty())
        {
            temp = s.top();
            if(temp.second>output.size())
                output.push_back(temp.first->val);
            s.pop();
            if(temp.first->left!=NULL)
                s.push(make_pair(temp.first->left,temp.second+1));
            if(temp.first->right!=NULL)
                s.push(make_pair(temp.first->right,temp.second+1));
        }
        return output;
    }
};