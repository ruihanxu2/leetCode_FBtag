/*
// Definition for a Node.
class Node {
public:
	int val;
	Node* prev;
	Node* next;
	Node* child;

	Node() {}

	Node(int _val, Node* _prev, Node* _next, Node* _child) {
		val = _val;
		prev = _prev;
		next = _next;
		child = _child;
	}
};
*/
class Solution {
public:
	Node* flatten2(Node* head) {
		for(Node* h = head; h; h = h->next){
			if(h->child){
				Node* next = h->next;
				h->next = h->child;
				h->child->prev = h;
				h->child = NULL;
				Node* dummy = h->next;
				while(dummy->next) dummy = dummy->next;
				if(next) next->prev = dummy;
				dummy->next = next;
			}
		}
		return head;
	}
	
	Node* helper(Node* node){
		if(!node) return NULL;
		if(!node->child){
			if(!node->next) return node;
			return helper(node->next);
		}
		
		else{
			Node* next = node->next;
			node->next = node->child;
			node->child->prev = node;
			node->child = NULL;
			Node* end = helper(node->next);
			
			if(next){
				next->prev = end;
				end->next = next;
				return helper(next);
			} 
			return end;
		}

	}
	Node* flatten(Node* head) {
		helper(head);
		return head;
	}
};