129. Sum Root to Leaf Numbers

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
    
    vector<string> Dfs(TreeNode* root)
    {
        vector<string> ret;
        if(root->left==NULL&&root->right==NULL){
            string temp = to_string(root->val);
            ret.push_back(temp);
            return ret;
        }
        
        vector<string>left,right;
        if(root->left!=NULL) left = Dfs(root->left);
        if(root->right!=NULL) right = Dfs(root->right);
        
        
        for(int i = 0;i<left.size();i++)
        {
            string temp = to_string(root->val);
            temp+=left[i];
            ret.push_back(temp);
        }
                
        for(int j = 0;j<right.size();j++)
        {
            string temp=to_string(root->val);
            temp+=right[j];
            ret.push_back(temp); 
        }
                
        return ret;
    }
    
    
    int sumNumbers(TreeNode* root) {
        if(root==NULL)
            return 0;
        vector<string> ret;
        ret = Dfs(root);
        int output = 0;
        stringstream s;
        int temp;
        for(int i = 0;i<ret.size();i++)
        {
            s<<ret[i];
            s>>temp;
            s.clear();
            output+=temp;
        }
        return output;
    }
};

int sumNumbers(TreeNode* root) {
        return sumNumbers(root, 0);
    }
    
    int sumNumbers(TreeNode* root, int sum){
        if(!root)
            return 0;
        sum = 10*sum + root->val;
        if(!root->left && !root->right)
            return sum;
        return sumNumbers(root->left, sum) + sumNumbers(root->right, sum);
    }