/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// NLogN, 1
class Solution {
public:
	TreeNode* sortedListToBST(ListNode* head) {
		return helper(head, NULL);
	}
	TreeNode* helper(ListNode* head, ListNode* tail){
		if(head == tail){
			return NULL;
		}
		else if(head->next == tail){
			TreeNode* TN = new TreeNode(head->val);
			return TN;
		}
		
		else{
			//find the mid node
			ListNode* fast = head;
			ListNode* slow = head;
			while(fast!=tail&&fast->next!=tail){
				fast = fast->next->next;
				slow = slow->next;
			}// slow is the mid
			
			TreeNode* TN = new TreeNode(slow->val);
			TN->left = helper(head, slow);
			TN->right = helper(slow->next, tail);
			return TN;
		}
	}
};


// use space to trade time
// N, N

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
	TreeNode* help(int s, int e, vector<int>& ll){
		if(s >= e) return NULL;
		int mid = (s+e)/2;
		TreeNode* node = new TreeNode(ll[mid]);
		node->left = help(s, mid, ll);
		node->right = help(mid + 1, e, ll);
		return node;
	}
	TreeNode* sortedListToBST(ListNode* head) {
		vector<int> ll;
		while(head){
			ll.emplace_back(head->val);
			head = head->next;
		}
		return help(0, ll.size(), ll);
	}
};


// construct the tree with inorder order.
// move the pointer of the head of the linked list
//O(N) O(logn)(call stack)
class Solution {
	ListNode* cur;
	
public:
	TreeNode* helper(int start, int end){
		if(start >= end) return NULL;
		int mid = (start+end) / 2;
		
		TreeNode* left = helper(start, mid);
		
		// 
		TreeNode* root = new TreeNode(cur->val);
		cur = cur -> next;
		root->left = left;
		
		root->right = helper(mid+1, end);
		return root;
		
		
	}
	
	TreeNode* sortedListToBST(ListNode* head) {
		cur = head;
		int len = 0;
		while(head){
			len++;
			head = head->next;
		}
		return helper(0, len);
		
	}
};