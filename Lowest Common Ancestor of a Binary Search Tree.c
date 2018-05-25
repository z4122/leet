/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val; 
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
    int temp_p = 0,temp_q = 0,temp = 0;
    struct TreeNode* root_temp = root;
    while(root->val!=p->val)
    {
        if(p->val < root->val)
        {
            root = root->left;
            temp_p = temp_p*2+1;
        }
        else
        {
            root = root->right;
            temp_p = temp_p*2+2;
        }
    }
    
    root = root_temp;
    
    while(root->val!=q->val)
    {
        if(q->val < root->val)
        {
            root = root->left;
            temp_q = temp_q*2+1;
        }
        else
        {
            root = root->right;
            temp_q = temp_q*2+2;
        }
    }
    
    while(temp_q!=temp_p) 
    {
        if(temp_q>temp_p)
            temp_q = (temp_q-1)/2;
        else
            temp_p = (temp_p-1)/2;
    }
    
    root = root_temp;



	while (root->val != p->val)
	{
        if (temp == temp_p)
			return root;
		if (p->val < root->val)
		{
			root = root->left;
			temp = temp * 2 + 1;
		}
		else
		{
			root = root->right;
			temp = temp * 2 + 2;
		}
		
	}
    return root;
}