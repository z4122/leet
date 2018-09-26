894. All Possible Full Binary Trees


A full binary tree is a binary tree where each node has exactly 0 or 2 children.

Return a list of all possible full binary trees with N nodes.  Each element of the answer is the root node of one possible tree.

Each node of each tree in the answer must have node.val = 0.

You may return the final list of trees in any order.



class Solution {
public:
    vector<TreeNode*> allPossibleFBT(int N) {
        if(N == 0) return {};
        
        vector<vector<TreeNode*>> dp(N + 1);
        dp[1] = {new TreeNode(0)};
        
        for(int i = 1; i <= N; i += 2) {
            for(int j = 1; j < i; j += 2) {
                for(const auto& l: dp[j]) {
                    for(const auto& r: dp[i - 1 - j]) {
                        TreeNode* node = new TreeNode(0);
                        node->left = l;
                        node->right = r;
                        dp[i].push_back(node);
                    }
                }
            }
        }
        
        return dp[N];
    }
};


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
    vector<TreeNode*> allPossibleFBT(int N) {
        vector<TreeNode*> ret;
        
        if(N==1)
        {
            TreeNode* temp = new TreeNode(0);
            ret.push_back(temp);
            return ret;
        }
        
        for(int i = 1;i<N;i+=2)
        {
            vector<TreeNode*> left,right;
            left = allPossibleFBT(i);
            right = allPossibleFBT(N-i-1);
            for(int j = 0;j<left.size();j++)
            {
                
                for(int k = 0;k<right.size();k++)
                {
                    TreeNode* temp = new TreeNode(0);
                    temp->left = left[j];
                    temp->right = right[k];
                    ret.push_back(temp);
                }               
            }
        }
        
        return ret;
    }
};