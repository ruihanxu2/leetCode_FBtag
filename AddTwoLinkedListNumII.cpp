// 6->1->2
// 2->2
// 6->3->4(res)
class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		stack<int> s1, s2;
		while(l1){
			s1.emplace(l1->val);
			l1 = l1->next;
		}
		while(l2){
			s2.emplace(l2->val);
			l2 = l2->next;
		}
		int carry = 0;
		ListNode* prev = NULL;
		while(!s1.empty() || !s2.empty() || carry){
			if(!s1.empty()){
				carry+=s1.top();
				s1.pop();
			}
			if(!s2.empty()){
				carry+=s2.top();
				s2.pop();
			}
			int cur = carry % 10;
			carry/=10;
			ListNode* newNode = new ListNode(cur);
			newNode->next = prev;
			prev = newNode;
		}
		return prev;
		
	}
};
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */