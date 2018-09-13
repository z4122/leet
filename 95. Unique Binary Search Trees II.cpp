95. Unique Binary Search Trees II


Given an integer n, generate all structurally unique BST's (binary search trees) that store values 1 ... n.

Example:

Input: 3
Output:
[
  [1,null,3,2],
  [3,2,null,1],
  [3,1,null,null,2],
  [2,1,3],
  [1,null,2,null,3]
]
Explanation:
The above output corresponds to the 5 unique BST's shown below:

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3



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
   vector<TreeNode*> generate(int leftn, int rightn)
{
	vector<TreeNode*> ret;

	if (leftn > rightn) {
		ret.push_back(NULL);
		return ret;
	}

	if (leftn == rightn) {
		ret.push_back(new TreeNode(leftn));
		return ret;
	}

	for (int subscript = leftn; subscript <= rightn; subscript++)
	{
		vector<TreeNode*> left = generate(leftn, subscript-1);
		vector<TreeNode*> right = generate(subscript + 1, rightn);
		for (int i = 0; i<left.size(); i++)
			for (int j = 0; j<right.size(); j++)
			{
				TreeNode* root = new TreeNode(subscript);
				root->left = left[i];
				root->right = right[j];
				ret.push_back(root);
			}
	}
	return ret;

}


vector<TreeNode*> generateTrees(int n) {
	vector<TreeNode*> temp;
	if (n == 0)
		return temp;

	return generate(1, n);
}
};