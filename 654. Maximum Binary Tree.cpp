654. Maximum Binary Tree


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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        int index = 0;
        int maxnumber = 0;
        
        if(nums.size()==0)
            return NULL;
        for(int i = 0;i<nums.size();i++)
        {
            if(nums[i]>maxnumber){
                maxnumber = nums[i];
                index = i;   
            }
        }
        
        vector<int> a = vector<int>(nums.begin(),nums.begin()+index);
        vector<int> b = vector<int>(nums.begin()+index+1,nums.end());
        TreeNode* left = constructMaximumBinaryTree(a);
        TreeNode* right = constructMaximumBinaryTree(b);
        
        TreeNode* root = new TreeNode(maxnumber);
        
        root->left = left;
        root->right = right;
        
        return root;
    }
};