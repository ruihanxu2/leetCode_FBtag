//利用next pointer进行bfs
Node* connect(Node* root){
	Node* res = root;
	Node* dummyHead = new Node(0);
	while(root){
		Node* cur = dummyHead;
		dummyHead->next = NULL; // set to null to terminate
		while(root){
			if(root->left){
				cur->next = root->left;
				cur = cur->next;
			}
			if(root->right){
				cur->next = root->right;
				cur = cur->next;
			}
			root = root->next;
		}
		root = dummyHead->next;
	}
	delete dummyHead;
	return res;
}