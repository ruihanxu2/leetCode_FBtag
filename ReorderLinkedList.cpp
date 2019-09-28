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
	void reorderList(ListNode* head) {
		if(!head) return;
		ListNode* mid = findMid(head);
		
		ListNode* l2 = mid->next;
		mid->next = NULL;
		l2 = reverseLL(l2);
		ListNode* l1 = head;
		merge(l1, l2);

	}
	
	ListNode* findMid(ListNode* node){
		ListNode* slow = node;
		ListNode* fast = node;
		while(fast->next && fast->next->next){
			slow = slow->next;
			fast = fast->next->next;
		}
		return slow;
	}
	ListNode* reverseLL(ListNode* node){
		ListNode* prev = NULL;
		ListNode* next = NULL;
		while(node){
			next = node->next;
			node->next = prev;
			prev = node;
			node = next;
		}
		return prev;
		
	}
	void merge(ListNode* l1, ListNode* l2){
		ListNode* next;
		while(l1&& l2){
			next = l1->next;
			l1->next = l2;
			l2 = l2->next;
			l1->next->next = next;
			l1 = next;
		}

	}
};