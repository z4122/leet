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
    
    
    
    TreeNode* increasingBST(TreeNode* root) {
        vector<int> num;
        stack<TreeNode*> stacktree;
        TreeNode* temp = root;
        while(!stacktree.empty()||temp!=NULL)
        {
            while(temp!=NULL)
            {
                stacktree.push(temp);
                temp = temp->left;
            }
            
            temp = stacktree.top();
            num.push_back(temp->val);
            stacktree.pop();
            temp = temp->right;
        }
        
        TreeNode* head = new TreeNode(num[0]);
        TreeNode* t1 = head;
        for(int i = 1;i<num.size();i++)
        {
            TreeNode* t2 = new TreeNode(num[i]);
            t1->right = t2;
            t1 = t2;
        }
        return head;
    }
};