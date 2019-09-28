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
	ListNode* reverseKGroup(ListNode* head, int k) {
		if(!head){
			return head;
		}
		ListNode* cur = head;
		int count = 0;
		while(cur && count < k){
			cur = cur->next;
			count++;
		}
		if(count == k){
			
			ListNode* prev = reverseKGroup(cur, k);
			while(count-- > 0){
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