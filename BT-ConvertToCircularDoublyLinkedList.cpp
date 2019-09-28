/*
// Definition for a Node.
class Node {
public:
	int val;
	Node* left;
	Node* right;

	Node() {}

	Node(int _val, Node* _left, Node* _right) {
		val = _val;
		left = _left;
		right = _right;
	}
};
*/
class Solution_recur {
	// right -> next node in in-order
	// left -> prev node in inorder
	// head->left = tail
	// tail->right = head
	Node* head = NULL; // node to return 
	Node* tail= NULL; // last node
	void helper(Node* root){
		if(!root) return;
		helper(root->left);
		//-------
		if(head == NULL){
			head = root;
		}
		root->left = tail;
		
		if(tail){
			tail->right = root;
		}
		
		tail = root;
		//-------
		helper(root->right);
	}
	
public:
	Node* treeToDoublyList(Node* root) {
		if(!root) return NULL;
		helper(root);
		head->left = tail;
		tail->right = head;
		return head;
	}
};


class Solution {
	// right -> next node in in-order
	// left -> prev node in inorder
	// head->left = tail
	// tail->right = head
	void pushToStack(stack<Node*>& s, Node* cur){
		while(cur){
			s.emplace(cur);
			cur = cur->left;
		}
	}
public:
	Node* treeToDoublyList(Node* root) {
		if(!root) return root;
		Node* head = NULL;
		Node* tail = NULL;
		stack<Node*> s;
		pushToStack(s, root);
		while(!s.empty()){
			Node* cur = s.top();
			s.pop();
			//--------
			if(!head){
				head = cur;
			}
			cur->left = tail;
			
			if(tail){
				tail->right = cur; 
			}
			tail = cur;
			// ---------
			pushToStack(s, cur->right);
		}
		head->left = tail;
		tail ->right = head;
		return head;
	}
};