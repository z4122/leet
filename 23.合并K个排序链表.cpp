23.合并K个排序链表

合并 k 个排序链表，返回合并后的排序链表。请分析和描述算法的复杂度。

示例:

输入:
[
  1->4->5,
  1->3->4,
  2->6
]
输出: 1->1->2->3->4->4->5->6


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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        return partition(lists,0,lists.size()-1);
    }
    ListNode* partition(vector<ListNode*>& lists,int start,int end){
        if(start==end){
            return lists[start];
        }
        if(start<end){
            int mid=(start+end)/2;
            ListNode* l1=partition(lists,start,mid);
            ListNode* l2=partition(lists,mid+1,end);
            return mergeTwoLists(l1,l2);
        }
        return NULL;
    }
    
    ListNode* mergeTwoLists(ListNode* l1,ListNode* l2){
        if(l2==NULL) return l1;
        if(l1==NULL) return l2;
        
        if(l1->val>l2->val){
            ListNode* temp=l2;
            temp->next = mergeTwoLists(l1,l2->next);
            return temp;
        }
        else{
            ListNode* temp = l1;
            temp->next = mergeTwoLists(l1->next,l2);
            return temp;
        }
    }
};