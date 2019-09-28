
TN* findLCA(TN* root, TN* p, TN* q){
	if(!root) return NULL;
	if(root == p || root == q) return root;
	int count = 0;
	TN* tmp;
	for(auto nei : root->neis){
		if(findLCA(nei, p, q) != NULL){
			tmp = nei;
			count++;
		}
	}
	if(count == 0) return NULL;
	else if(count == 1) return tmp;
	else return root;
	 
}