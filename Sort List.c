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
    
   ListNode* quicksort(ListNode* head, ListNode* end)
{
	if (head == end || head == NULL)
		return NULL;
	int temp = head->val;
	ListNode* tempnode = head;
	for (ListNode* i = head->next; i != end; i = i->next)
	{
		if (i->val<temp)
		{
			swap(tempnode->val, i->val);
			tempnode = tempnode->next;
		}
	}
	if (end->val < temp)
		swap(tempnode->val, end->val);

	quicksort(head, tempnode);
	quicksort(tempnode->next, end);
	return head;
}

ListNode* sortList(ListNode* head) {
	ListNode* end = head;
	while (end->next != NULL)
		end = end->next;
	return quicksort(head, end);
}
};