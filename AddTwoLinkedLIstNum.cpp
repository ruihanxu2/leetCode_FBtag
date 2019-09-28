ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
	ListNode* head = new ListNode(0);
	ListNode* cur = head;
	int carry = 0;
	while(l1 || l2 || carry){
		if(l1){
			carry += l1->val;
			l1 = l1->next;
		}
		if(l2){
			carry+=l2->val;
			l2 = l2->next;
		}
		cur->val = carry % 10;
		carry/=10;
		if(l1 || l2 || carry){
			cur->next = new ListNode(0);
			cur = cur->next;
		}
	}
	return head;
}