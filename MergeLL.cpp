ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
	if(!l1) return l2;
	if(!l2) return l1;
	ListNode* cur1 = l1;
	ListNode* cur2 = l2;
	ListNode* res;
	if(cur1->val < cur2->val){
		res = cur1;
		cur1 = cur1->next;
	}else{
		res = cur2;
		cur2 = cur2->next;
	}
	ListNode* cur = res;
	while(cur1 && cur2){
		if(cur1->val < cur2->val){
			cur->next = cur1;
			cur1 = cur1->next;
			cur = cur->next;
		}
		else{
			cur->next = cur2;
			cur2 = cur2->next;
			cur = cur->next;
		}
	}
	if(cur1){
		cur->next = cur1;
	}else{
		cur->next = cur2;
	}
	return res;
}


struct compare{
	bool operator()(ListNode* a, ListNode* b){
		return a->val > b->val;
		// smaller value on top
	}
};
ListNode* mergeKLists(vector<ListNode*>& lists) {
	priority_queue<ListNode*, vector<ListNode*>, compare> pq;
	for(auto head : lists){
		if(head) pq.emplace(head);
	}
	if(pq.empty()) return NULL;
	ListNode* res = pq.top();
	pq.pop();
	if(res->next) pq.emplace(res->next);
	ListNode* cur = res;
	while(!pq.empty()){
		cur->next = pq.top();
		cur = cur->next;
		pq.pop();
		if(cur->next) pq.emplace(cur->next);
	}
	return res;
}