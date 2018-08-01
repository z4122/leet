struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
	
};

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
	ListNode *output = new ListNode(0);
	ListNode *output1 = new ListNode(0);
	output1->next = output;
	while (l1 != NULL || l2 != NULL)
	{
		if (l1 == NULL)
		{
			output->next = l2;
			output = output->next;
			l2 = l2->next;
			continue;
		}

		if (l2 == NULL)
		{
			output->next = l1;
			output = output->next;
			l1 = l1->next;
			continue;
		}

		if ((l1->val <= l2->val))
		{
			output->next = l1;
			output = output->next;
			l1 = l1->next;
			continue;
		}
		else if ((l1->val>l2->val))
		{
			output->next = l2;
			output = output->next;
			l2 = l2->next;
			continue;
		}

	}
	return output1->next;
}

ListNode* reverseList(ListNode* head) {
	ListNode* last = NULL;

	while (head!= NULL)
	{
		ListNode *temp = new ListNode(head->val);
		temp->next = last;
		last = temp;
		head = head->next;
	}
	return last;
}