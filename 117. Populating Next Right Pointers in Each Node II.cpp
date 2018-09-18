117. Populating Next Right Pointers in Each Node II

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
        if(root==NULL)
            return;
        queue<TreeLinkNode*> last,current;
        TreeLinkNode* temp;
        TreeLinkNode* lasttemp;
        last.push(root);
        
        
        for(int i = 0;i<100;i++)
        {   
            if(last.size()==0)
                return;
            else if(last.size()==1)
            {
                temp = last.front();
                last.pop();
                if(temp->left!=NULL) current.push(temp->left);
                if(temp->right!=NULL) current.push(temp->right);
            }
            else
            {
                lasttemp = last.front();
                
                while(!last.empty())
                {
                    temp = last.front();
                    lasttemp->next = temp;
                    last.pop();
                    if(temp->left!=NULL) current.push(temp->left);
                    if(temp->right!=NULL) current.push(temp->right);
                    lasttemp = temp;
                }
            }
            
            last = current;
            current = queue<TreeLinkNode*>();
        }

    }
};