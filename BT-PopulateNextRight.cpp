/*
// Definition for a Node.
class Node {
public:
	int val;
	Node* left;
	Node* right;
	Node* next;

	Node() {}

	Node(int _val, Node* _left, Node* _right, Node* _next) {
		val = _val;
		left = _left;
		right = _right;
		next = _next;
	}
};
*/
class Solution_ {
public:
	Node* connect(Node* root) {
		Node* dummy = new Node(0, nullptr, nullptr, nullptr);
		Node* node = root;
		while(node){
			Node* cur = dummy;
			while(node){
				if(node->left) {
					cur->next = node->left;
					cur = cur->next;
				}
				if(node->right) {
					cur->next = node->right;
					cur = cur->next;
				}
				node = node->next;
			}
			node = dummy->next;
			dummy->next = nullptr;
			
		}
		return root;
	}
};

class Solution {
public:
	Node* connect(Node* root) {
		if(!root) return nullptr;
		queue<Node*> q;
		q.emplace(root);
		while(!q.empty()){
			int n = q.size();
			for(int i = 0; i < n; i++){
				auto p = q.front();
				q.pop();
				p->next = (i != n - 1) ? q.front() : nullptr;
				if(p->left) q.emplace(p->left);
				if(p->right) q.emplace(p->right);
			}
		}
		return root;
	}
};