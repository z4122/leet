给出一个完全二叉树，求出该树的节点个数。

说明：

完全二叉树的定义如下：在完全二叉树中，除了最底层节点可能没填满外，其余每层节点数都达到最大值，并且最下面一层的节点都集中在该层最左边的若干位置。若最底层为第 h 层，则该层包含 1~ 2h 个节点。

示例:

输入: 
    1
   / \
  2   3
 / \  /
4  5 6

输出: 6

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
    int countNodes(TreeNode* root) {
        if(root==NULL)
            return 0;
        stack<TreeNode*>s;
        s.push(root);
        int height = 0;
        while(!s.empty()){
            TreeNode* temp = s.top();
            s.pop();
            height++;
            if(temp->left!=NULL)    s.push(temp->left);
        }

        int left = 0,right=pow(2,height-1)-1;
        int mid = (left+right)/2;
        TreeNode* temp = root;
        TreeNode *leftnode,*rightnode;
        
        for(int i = height-2;i>=0;i--){
            temp = temp->right;    
        }
        if(temp!=NULL)
            return pow(2,height)-1;
        
        while(left+1<right){
            mid=(left+right)/2;
            temp = root;
            for(int i = height-2;i>=0;i--){
                if(mid&(1<<i)){
                    temp = temp->right;
                }
                else{
                    temp = temp->left;
                }
            }
            if(temp!=NULL)
                left = mid;
            else
                right = mid;
        }
        return left+pow(2,height-1);
    }
};

int countNodes(TreeNode* root) {
           if(root==NULL)
                return 0;
                
            int leftDepth=0;
            int rightDepth=0;
            for(TreeNode* node=root;node!=NULL;node=node->left)
                leftDepth++;
            for(TreeNode* node=root;node!=NULL;node=node->right)
                rightDepth++;
            if(leftDepth==rightDepth)
                return (1<<leftDepth)-1;
            else
                return countNodes(root->left)+countNodes(root->right)+1;
    }