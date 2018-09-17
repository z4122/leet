/**
257. Binary Tree Paths

Given a binary tree, return all root-to-leaf paths.

Note: A leaf is a node with no children.

Example:

Input:

   1
 /   \
2     3
 \
  5

Output: ["1->2->5", "1->3"]

Explanation: All root-to-leaf paths are: 1->2->5, 1->3

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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ret;
        if(root==NULL)
            return ret;
        
        vector<string>left;
        vector<string>right;
        
        if(root->left!=NULL) left = binaryTreePaths(root->left);
        if(root->right!=NULL) right = binaryTreePaths(root->right);
        
        string temp;
        stringstream tempstream;
        tempstream<<root->val;
        tempstream>>temp;
        string t = temp;
        for(int i = 0;i<left.size();i++)
        {
            temp = t;
            temp+="->";
            temp+=left[i];
            ret.push_back(temp);
            temp.clear();
        }
        for(int i = 0;i<right.size();i++)
        {
            temp = t;
            temp+="->";
            temp+=right[i];
            ret.push_back(temp);
            temp.clear();
        }
        
        if(ret.size()==0)
        {
            temp = t;
            ret.push_back(temp);
        }
        return ret;
    }
};