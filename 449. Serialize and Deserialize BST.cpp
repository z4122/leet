/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
string serialize(TreeNode* root) {
	string ret;
	if (root == NULL)
		return ret;

	string left = serialize(root->left);
	string right = serialize(root->right);

	ret += to_string(root->val);

	ret += '_';

	ret += left;
	ret += right;
	return ret;
}
449. Serialize and Deserialize BST


Serialization is the process of converting a data structure or object into a sequence of bits so that it can be stored in a file or memory buffer, or transmitted across a network connection link to be reconstructed later in the same or another computer environment.

Design an algorithm to serialize and deserialize a binary search tree. There is no restriction on how your serialization/deserialization algorithm should work. You just need to ensure that a binary search tree can be serialized to a string and this string can be deserialized to the original tree structure.

The encoded string should be as compact as possible.

Note: Do not use class member/global/static variables to store states. Your serialize and deserialize algorithms should be stateless.



// Decodes your encoded data to tree.
TreeNode* deserialize(string data) {

	if (data.size() == 0)
		return NULL;

	TreeNode* head;
	int headval = 0, leftindex = 0, rightindex = 0;
	int tempval = INT_MIN;

	if (data[leftindex] != '-') {
		while (data[leftindex] != '_')
		{
			headval = headval * 10 + data[leftindex] - '0';
			leftindex++;
		}
	}
	else{
		leftindex++;
		while (data[leftindex] != '_')
		{
			headval = headval * 10 + data[leftindex] - '0';
			leftindex++;
		}
		headval *= -1;
	}


	leftindex++;

	rightindex = leftindex;
	while (tempval <= headval && rightindex<data.size())
	{
		tempval = 0;
		if (data[rightindex] != '-')
		{
			while (data[rightindex] != '_')
			{
				tempval = tempval * 10 + data[rightindex] - '0';
				rightindex++;
			}
			rightindex++;
		}
		else
		{
			rightindex++;
			while (data[rightindex] != '_')
			{
				tempval = tempval * 10 + data[rightindex] - '0';
				rightindex++;
			}
			rightindex++;
			tempval *= -1;
		}

	}

	if(tempval>headval){
		if (tempval != INT_MIN) {
			if (tempval <= 0)
				rightindex--;
			while (tempval != 0)
			{
				rightindex--;
				tempval /= 10;
			}

			rightindex--;
		}
	}

	head = new TreeNode(headval);

	head->left = deserialize(data.substr(leftindex, rightindex-leftindex));
	head->right = deserialize(data.substr(rightindex, data.size() - rightindex));

	return head;
}
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));