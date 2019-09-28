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
	ListNode* swapPairs(ListNode* head) {
		if(!head) return head;
		int k = 2;
		int len = 0;
		ListNode* cur = head;
		while(cur && len < k){
			len++;
			cur = cur->next;
		}
		if(len == k){
			ListNode* prev = swapPairs(cur);
			while(len-- > 0){
				ListNode* next = head->next;
				head->next = prev;
				prev = head;
				head = next;
			}
			head = prev;
		}
		return head;
	}
};