//Reverse a LL
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
	//recursive
	ListNode* reverseList(ListNode* node) {
		if(!node||!node->next){
			return node;
		}
		ListNode* new_node = reverseList(node->next);
		node->next->next = node;
		node->next = NULL;
		return new_node;
	}
	
	ListNode* reverseList(ListNode* head) {
		if(!head || !head->next) return head;
		ListNode* prev = nullptr;
		ListNode* cur = head;
		ListNode* next = cur->next;
		while(cur){
			next = cur->next;
			cur->next = prev;
			prev = cur;
			cur = next;
		}
		return prev;
	}
};