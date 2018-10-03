109. Convert Sorted List to Binary Search Tree

//有更好的解法

class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if(head == NULL) return NULL;
        return buildBST(head, NULL);
    }
    TreeNode* buildBST(ListNode* head, ListNode* tail)
    {
        ListNode* fast = head;
        ListNode* slow = head;
        if(head==tail) return NULL;
        while(fast!=tail&&fast->next!=tail)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        TreeNode* root = new TreeNode(slow->val);
        root->left = buildBST(head, slow);
        root->right = buildBST(slow->next, tail);
        return root;
    }
};


class Solution {
public:
    
    TreeNode* recur(int index,int begin,int end,vector<int>&nums)
    {
        if(begin>end)
            return NULL;
        
        TreeNode* head = new TreeNode(nums[index]);
        if(begin==end)
            return head;
        
        head->left = recur((begin+index-1)/2,begin,index-1,nums);
        head->right = recur((index+1+end)/2,index+1,end,nums);
        
        return head;
    }
    
    TreeNode* sortedListToBST(ListNode* head) {
        if(head==NULL)
            return NULL;
        vector<int> nums;
        while(head!=NULL){
            nums.push_back(head->val);
            head=head->next;   
        }
        int len = nums.size();
        return recur(len/2,0,len-1,nums);     
    }
};