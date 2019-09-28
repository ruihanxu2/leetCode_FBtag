/*
// Definition for a Node.
class Node {
public:
	int val;
	Node* next;
	Node* random;

	Node() {}

	Node(int _val, Node* _next, Node* _random) {
		val = _val;
		next = _next;
		random = _random;
	}
};
*/


class Solution_ {
public:
	Node* copyRandomList(Node* head) {
		if(!head) return nullptr;
		unordered_map<Node*, Node*> m;
		m[head] = new Node(head->val, nullptr, nullptr);
		Node* cur = head;
		Node* next;
		while(cur -> next){
			next = cur->next;
			m[next] = new Node(next->val, nullptr, nullptr);
			m[cur]->next = m[next];
			cur = cur->next;
		}
		cur = head;
		while(cur){
			if(cur->random) m[cur]->random = m[cur->random];
			cur = cur->next;
		}
		return m[head];

	}
};

class Solution {
public:
	Node* copyRandomList(Node* head) {
		if(!head) return NULL;
		Node* cur = head;
		Node* next;
		// interleave
		while(cur){
			Node* newNode = new Node(cur->val, NULL, NULL);
			newNode->next = cur->next;
			cur->next = newNode;
			cur = newNode->next;
		}
		//copy rand
		cur = head;
		while(cur){
			if(cur -> random){
				cur->next->random = cur->random->next;
			}
			cur = cur->next->next;
		}
		// recover link
		Node* res = head->next;
		cur = head;
		Node* curNew = head->next;
		while(cur){
			cur->next = cur->next->next;
			curNew -> next = curNew->next ? curNew->next->next : NULL;
			cur = cur->next;
			curNew = curNew->next;
		}
		return res;
	}
};