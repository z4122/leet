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
ListNode* deleteDuplicates(ListNode* head) {
	ListNode *last = head, *now = head;
	int temp;
	vector<int> output;
    
	if (head != NULL)
	{
		now = head->next;
	}
    else
        return NULL;

	temp = head->val;
    
    if(now==NULL)
        return head;
	while (now != NULL)
	{
		if (temp == now->val)
		{
			while (temp == now->val)
            {
				now = now->next;
                if(now == NULL)
                    break;
                    
            }
            if(now == NULL)
                break;
		}
		else
			output.push_back(temp);
		temp = now->val;
		if (now->next == NULL)
			output.push_back(temp);
		now = now->next;
	}
    if(output.empty())
        return NULL;
	now = head;
	now->val = output[0];
	for (int i = 1;i<output.size();i++)
	{
		now = now->next;
		now->val = output[i];
	}
	now->next = NULL;

	return head;
}
};