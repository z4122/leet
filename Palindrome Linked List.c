/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        int num = 0;
        int divide = 0;
        ListNode *temp = head;
        ListNode *reverse = head;
        
        if(head==NULL)
            return true;
        
        while(head!=NULL)
        {
            num++;
            head = head->next;
        }
        head = temp;
        
        if(num==1)
            return true;
        
        divide = num/2;
        
        head = head->next;
        reverse->next = NULL;
        divide--;
        
        while(divide--)
        {
            temp = head;
            head = head->next;
            temp->next = reverse;
            reverse = temp;
        }
        
        if(num%2==0)
        {
            while(head!=NULL)
            {
                if(reverse->val==head->val)
                {
                    reverse = reverse->next;
                    head = head->next;
                }         
                else
                    return false;
            }
        }
        else
        {
            head = head->next;
            while(head!=NULL)
            {
                if(reverse->val==head->val)
                {
                    reverse = reverse->next;
                    head = head->next;
                }         
                else
                    return false;
            }
        }
        return true;
        
    }
};