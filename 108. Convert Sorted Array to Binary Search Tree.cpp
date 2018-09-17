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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.size()==0)
            return NULL;
        
        int mid = nums.size()/2;
        
        TreeNode* root = new TreeNode(nums[mid]);
        if(nums.size()==1)
            return root;
        

        
        vector<int> left(nums.begin(),nums.begin()+mid);
        vector<int> right(nums.begin()+mid+1,nums.end());
        
        TreeNode* ltree = sortedArrayToBST(left);
        TreeNode* rtree = sortedArrayToBST(right);
    
      
        
        root->left = ltree;
        root->right = rtree;
        
        return root; 
    }
};