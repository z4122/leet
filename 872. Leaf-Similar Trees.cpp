872. Leaf-Similar Trees

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
    
    void storeLeaf(TreeNode* head,vector<int>& temp)
    {
        if(head==NULL)
            return;
        if((head->left==NULL&&head->right==NULL))
        {
            temp.push_back(head->val);
        }
        storeLeaf(head->left,temp);
        storeLeaf(head->right,temp);
    }
    
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> temp1,temp2;
        storeLeaf(root1,temp1);
        storeLeaf(root2,temp2);
        if(temp1.size()==temp2.size()){
            for(int i = 0;i<temp1.size();i++)
                if(temp1[i]!=temp2[i])
                    return false;
        }
        else return false;
        
        return true;
    }
};