617. Merge Two Binary Trees


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
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        TreeNode* temp;
        if(t1==NULL||t2==NULL)
        {
            if(t1==NULL&&t2==NULL)
            {
                temp = NULL;
            }
            else if(t1==NULL)
            {
                temp = t2;
                temp->left = mergeTrees(NULL,t2->left);
                temp->right = mergeTrees(NULL,t2->right);
            }
            else if(t2==NULL)
            {
                temp = t1;
                temp->left = mergeTrees(t1->left,NULL);
                temp->right = mergeTrees(t1->right,NULL);
            }
        }
        else
        {
            temp = new TreeNode(t1->val+t2->val);
            temp->left = mergeTrees(t1->left,t2->left);
            temp->right = mergeTrees(t1->right,t2->right);
        }
        
        return temp;
            
    }
};