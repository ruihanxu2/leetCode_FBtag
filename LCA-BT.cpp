//---------------Recur
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
	if(!root) return NULL;
	if(root == p || root == q) return root;
	
	TreeNode* left = lowestCommonAncestor(root->left, p, q);
	TreeNode* right = lowestCommonAncestor(root->right, p, q);
	if(!left && !right) return NULL;
	else if(left && right) return root;
	else if(left) return left;
	else return right;
}


//---------------Iter: postorder traversal
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
	TreeNode *cur=root,*last=nullptr;
	vector<TreeNode*> pathp,pathq,temp;
	
	while (pathp.empty() || pathq.empty()) {
		
		// standard post-order iterative tree traversal
		if (cur) {
			temp.push_back(cur);
			if (temp.back()==p) pathp=temp; // check and set path for p
			if (temp.back()==q) pathq=temp; // check and set path for q
			cur=cur->left;
		} else {
			if (temp.back()->right && temp.back()->right != last) {
				cur=temp.back()->right;
			} else {
				last=temp.back();
				temp.pop_back();
			}
		}
	}
	
	// compare paths and get lowest common ancestor
	int n=min(pathp.size(),pathq.size());
	for (int i=1; i<n; i++) {
		if (pathp[i]!=pathq[i]) return pathp[i-1];
	}
	return pathp[n-1];
}