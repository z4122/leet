    bool hasCycle(ListNode *head) {
        if(head==NULL)
            return 0;
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast->next&&fast->next->next)
        {
            fast = fast->next->next;
            slow = slow->next;
            if(fast==slow)
                return 1;
        }
        return 0;
    }