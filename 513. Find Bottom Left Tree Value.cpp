
513. Find Bottom Left Tree Value




Given a binary tree, find the leftmost value in the last row of the tree.

Example 1:
Input:

    2
   / \
  1   3

Output:
1
Example 2: 
Input:

        1
       / \
      2   3
     /   / \
    4   5   6
       /
      7

Output:
7
Note: You may assume the tree (i.e., the given root node) is not NULL.







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
void Dfs(TreeNode* root, int maxdepth, int currentdepth, vector<int>& output)
{
    
	if (currentdepth == maxdepth)
		output.push_back(root->val);
	if (root->left != NULL)
	{
		Dfs(root->left, maxdepth, currentdepth+1, output);
	}
	if (root->right != NULL)
	{
		Dfs(root->right, maxdepth, currentdepth+1, output);
	}
}

    int findmaxdepth(TreeNode* temp)
    {
        if (temp == NULL)
            return 0;
        else
        {
            int ldepth = findmaxdepth(temp->left);
            int rdepth = findmaxdepth(temp->right);
            return ldepth > rdepth ? ldepth + 1 : rdepth + 1;
        }
    }

int findBottomLeftValue(TreeNode* root) {
	vector<int> output;
	int maxdepth = findmaxdepth(root);
    //printf("深度%d\n",maxdepth);
	Dfs(root, maxdepth, 1, output);
	return output[0];
}
};