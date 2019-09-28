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
	ListNode* reverseLL(ListNode* head){
		ListNode* prev = NULL;
		ListNode* cur = head;
		ListNode* next = NULL;
		while(cur){
			next = cur->next;
			cur->next = prev;
			prev = cur;
			cur = next;
		}
		return prev;
	}
	bool isPalindrome(ListNode* head) {
		int len = 0; 
		ListNode* cur = head;
		while(cur){
			len++;
			cur = cur->next;
		}
		int halfLen = len / 2;
		
		ListNode *half;
		half = head;
		for(int i = 0; i < halfLen; i++){
			half = half->next;
		}
		if(len % 2 == 1){
			half = half->next;
		}
		cur = head;
		half = reverseLL(half);
		for(int i = 0; i < halfLen; i++){
			if(cur->val != half->val){
				return false;
			}
			cur = cur->next;
			half = half->next;
		}
		return true;
	}
};

class Solution_ {
public:
	bool isPalindrome(ListNode* head) {
		if(!head) return true;
		int len = 0;
		ListNode* cur = head;
		while(cur){
			cur = cur->next;
			len++;
		}
		cur = head;
		for(int i = 0; i < len / 2; i++, cur = cur->next){
			int move = len - i;
			ListNode* right = head;
			while(--move){
				right = right -> next;
			}
			
			if(cur->val != right->val) return false;
		}
		return true;
	}
};