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
    TreeNode* invertTree(TreeNode* root) {
        stack<TreeNode*> stemp;
        if(root==NULL)
            return NULL;
        TreeNode* headtemp = root;
        TreeNode* temp;
        stemp.push(root);
        while(!stemp.empty())
        {
            headtemp = stemp.top();
            stemp.pop();
            temp = headtemp->right;
            headtemp->right = headtemp->left;
            headtemp->left = temp;
            if(headtemp->right!=NULL)
                stemp.push(headtemp->right);
            if(headtemp->left!=NULL)
                stemp.push(headtemp->left);
        }
        return root;
    }
};