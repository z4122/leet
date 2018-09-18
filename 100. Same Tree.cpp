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
    
    void print(TreeNode* root,string& v)
    {
        stack<TreeNode*> s;
        TreeNode* temp = root;
        while(!s.empty()||temp!=NULL)
        {
            while(temp!=NULL)
            {
                v+=to_string(temp->val);
                s.push(temp);
                temp = temp->left;
            }
            v+=" ";
            temp = s.top();
            s.pop();
            temp = temp->right;
            
        }
    }
    
    bool isSameTree(TreeNode* p, TreeNode* q) {
        string temp1,temp2;
        
        print(p,temp1);
        print(q,temp2);
        
        if(temp1.size()!=temp2.size())
            return false;
        for(int i = 0;i<temp1.size();i++)
        {
            if(temp1[i]!=temp2[i])
                return false;
        }
        return true;
    }
};

//下面的解法更好
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if((!p && q) || (!q && p)) return false;
        if(!p && !q) return true;
        
        return p->val==q->val && isSameTree(p->left,q->left) && isSameTree(p->right, q->right);
    }
};