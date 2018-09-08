101. Symmetric Tree

Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

For example, this binary tree [1,2,2,3,4,4,3] is symmetric:

    1
   / \
  2   2
 / \ / \
3  4 4  3
But the following [1,2,2,null,3,null,3] is not:
    1
   / \
  2   2
   \   \
   3    3
Note:
Bonus points if you could solve it both recursively and iteratively.

我的解法
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
    
    void recur(TreeNode* head)
    {
        if(head==NULL)
            return;
        TreeNode* temp = head->left;   
        head->left = head->right;
        head->right = temp;
        recur(head->left);
        recur(head->right);
    }
    
    void print(TreeNode* head,vector<int>& output)
    {
        if(head!=NULL)
            output.push_back(head->val);
        else
        {
            output.push_back(0);
            return;
        }
        print(head->left,output);
        print(head->right,output);
    }
    
    bool isSymmetric(TreeNode* root) {
        vector<int> temp1,temp2;
        print(root,temp1);
        recur(root);
        print(root,temp2);
        for(int i = 0;i<temp1.size();i++)
        {
            if(temp1[i]!=temp2[i])
                return 0;
        }
        return 1;
    }
};

更好的解法
class Solution {
public:
    bool isSymmetric(TreeNode* root){
        if(!root)   return 1;
        return isMirror(root->left,root->right);
    }
    
    bool isMirror(TreeNode *l,TreeNode *r){
        if(!l && !r)    return 1;
        if(!l || !r)    return 0;
        if(l->val!=r->val)  return 0;
        return isMirror(l->left,r->right) && isMirror(l->right,r->left);
    }
};

