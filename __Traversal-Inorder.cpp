void dfs(vector<int> &res, TreeNode* node){
	if(node -> left) dfs(res, node->left);
	
	res.emplace_back(node->val);
	
	if(node -> right) dfs(res, node->right);
}
vector<int> inorderTraversal_recur(TreeNode* root) {
	vector<int> res;
	if(!root) return res;
	dfs(res, root);
	return res;
}
// -------------- iter--------

void pushToStack(stack<TreeNode*>& s, TreeNode *node){
	while(node){
		s.emplace(node);
		node = node->left;
	}
}
vector<int> inorderTraversal(TreeNode* root) {
	stack<TreeNode*> s;
	vector<int> res;
	pushToStack(s, root);
	while(!s.empty()){
		TreeNode* tmp = s.top();
		s.pop();
		res.emplace_back(tmp->val);
		pushToStack(s, tmp->right);
		
	}
	return res;
}