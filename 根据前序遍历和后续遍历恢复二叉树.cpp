106. Construct Binary Tree from Inorder and Postorder Traversal

class Solution {
public:
    
    TreeNode* recur(vector<int>& inorder,vector<int>& postorder,int ibegin,int iend,int j)
    {
        if(ibegin>iend||j<0)
            return NULL;
        
        TreeNode* head;
        int index = 0;
        int temp = 0;
        
        for(int i = ibegin;i<=iend;i++)
        {
            if(inorder[i]==postorder[j]){
                head = new TreeNode(inorder[i]);
                index = i;
                break;
            }
        }
        
        int rightnum = iend-index;
        int leftnum = index-ibegin;
        
        
        head->left=recur(inorder,postorder,ibegin,index-1,j-rightnum-1);
        head->right = recur(inorder,postorder,index+1,iend,j-1);
        
        return head;
    }
    
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(inorder.size()==0||postorder.size()==0)
            return NULL;
        
        int temp = *(--postorder.end());
    
        for(int i = 0;i<inorder.size();i++){
            if(inorder[i]==temp){    
                break;
            }
        }
        
        
        return recur(inorder,postorder,0,inorder.size()-1,postorder.size()-1);
    }
};


//更好的解法，利用了最右边总是右子树的特性进行弹出
class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        TreeNode* root = build(inorder, 0, inorder.size() - 1, postorder);
        return root;
    }
    
    TreeNode* build(vector<int>& inorder, int s1, int e1, vector<int>& postorder) {
        TreeNode* root = nullptr;
        if (s1 <= e1) {                                     //use inroder to check if the root is NULL or not
            root = new TreeNode(postorder.back());
            int root_index = findIndex(inorder, s1, e1, postorder.back());
            postorder.pop_back();
            root->right = build(inorder, root_index + 1, e1, postorder);        //doing right subtree fisrt, because the last term in the cureent postroder vector is always its right subtree's root
            root->left = build(inorder, s1, root_index - 1, postorder);
        }
        return root;
    }
    
    int findIndex(vector<int>& nums, int s, int e, int target) {
        while (s <= e) {
            if (nums[s] == target) break;
            ++s;
        }
        return s;
    }
};