515. Find Largest Value in Each Tree Row
You need to find the largest value in each row of a binary tree.

Example:
Input: 

          1
         / \
        3   2
       / \   \  
      5   3   9 

Output: [1, 3, 9]

class Solution {
public:
    
    int findmaxdepth(TreeNode* root)
    {
        if(root == NULL)
            return 0;
        int left = findmaxdepth(root->left)+1;
        int right = findmaxdepth(root->right)+1;
        return left>right?left:right;
    }
    
    void push(TreeNode* head,int currentlength,vector<int>& temp)
    {
        temp[currentlength-1] = max(head->val,temp[currentlength-1]);
        if(head->left!=NULL)
            push(head->left,currentlength+1,temp);
        if(head->right!=NULL)
            push(head->right,currentlength+1,temp);
    }
    
    vector<int> largestValues(TreeNode* root) {
        if(root==NULL)
            return vector<int>(0,0);
        int maxdepth = findmaxdepth(root);
        vector<int> temp(maxdepth,INT_MIN);
        push(root,1,temp);
        return temp;
    }
};