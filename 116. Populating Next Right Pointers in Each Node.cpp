116. Populating Next Right Pointers in Each Node


Given a binary tree

struct TreeLinkNode {
  TreeLinkNode *left;
  TreeLinkNode *right;
  TreeLinkNode *next;
}
Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.

Initially, all next pointers are set to NULL.

Note:

You may only use constant extra space.
Recursive approach is fine, implicit stack space does not count as extra space for this problem.
You may assume that it is a perfect binary tree (ie, all leaves are at the same level, and every parent has two children).
Example:

Given the following perfect binary tree,

     1
   /  \
  2    3
 / \  / \
4  5  6  7
After calling your function, the tree should look like:

     1 -> NULL
   /  \
  2 -> 3 -> NULL
 / \  / \
4->5->6->7 -> NULL

/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if(!root)
            return;
        if(root->left)
            root->left->next = root->right;
        if(root->next && root->right)
            root->right->next = root->next->left;
        connect(root->left);
        connect(root->right);
    }
};

/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        queue<TreeLinkNode*> last,now;
        TreeLinkNode* temp;
        last.push(root);
        
        if(root==NULL)
            return;
        
        while(!last.empty())
        {
            temp = last.front();
            while(!last.empty())
            {
                temp->next = last.front();
                temp = last.front();
                last.pop();
                
                if(temp->left!=NULL) now.push(temp->left);
                if(temp->right!=NULL) now.push(temp->right);
            }
            temp->next = NULL;
            last = now;
            queue<TreeLinkNode*>().swap(now);
        }
    }
};