


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */




 struct TreeNode* build(int* preorder, int* inorder, int preindex, int startinindex, int endinindex,int size)
 {
	 struct TreeNode *rootnode = (struct TreeNode*)malloc(sizeof(struct TreeNode));

	 rootnode->val = preorder[preindex];
	 rootnode->right = NULL;
	 rootnode->left = NULL;
	 if (startinindex>endinindex)
		 return NULL;
	 int inindex = 0;
	 
	 for (int i = 0; i<size; i++)
	 {
		 if (inorder[i] == preorder[preindex])
		 {
			 inindex = i;
			 break;
		 }
	 }
	 int leftlen = inindex - startinindex;
	 int rightlen = endinindex - inindex;

	 if (leftlen>0)
		 rootnode->left = build(preorder, inorder, preindex + 1, startinindex, inindex - 1,size);
	 if (rightlen>0)
		 rootnode->right = build(preorder, inorder, preindex + leftlen + 1, inindex + 1, endinindex,size);
	 return rootnode;

 }

 struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize) {
	 struct TreeNode *rootnode = NULL;
	
	 rootnode = build(preorder, inorder, 0, 0, preorderSize - 1,preorderSize);

	 return rootnode;

 }