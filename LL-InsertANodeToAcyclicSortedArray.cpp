Node* insert(Node* head, int insertVal) {
	Node* insert = new Node(insertVal, NULL);
	Node* cur = head;
	if(!head) return insert;
	while(cur->next != head){
		if(cur->val <= insertVal && cur->next->val >= insertVal){
			Node* tmp = cur->next;
			cur->next = insert;
			insert->next = tmp;
			return head;
		}
		if(cur->val > cur->next->val && (cur->val <= insertVal || cur->next->val >= insertVal)){
			Node* tmp = cur->next;
			cur->next = insert;
			insert->next = tmp;
			return head;
		}
		cur = cur -> next;
	}
	//insert before head;
	Node* tmp = cur->next;
	cur->next = insert;
	insert->next = tmp;
	return head;
}

/*
// Definition for a Node.
class Node {
public:
int val;
Node* next;

Node() {}

Node(int _val, Node* _next) {
	val = _val;
	next = _next;
}
};
*/