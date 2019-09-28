vector<int> preorderTraversal(TreeNode* root) {
	stack<TreeNode*> s;
	vector<int> res;
	if(!root) return res;
	s.emplace(root);
	while(!s.empty()){
		TreeNode* cur = s.top();
		s.pop();
		res.emplace_back(cur);
		if(cur->right){
			s.emplace(cur->right);
		}	
		if(cur->left){
			s.emplace(cur->left);
		}
	}
	return res;
}