vector<int> postorderTraversal(TreeNode* root) {
	unordered_set<TreeNode*> visited;
	stack<TreeNode*> s;
	vector<int> res;
	if(!root) return res;
	s.emplace(root);
	while(!s.empty()){
		TreeNode* cur = s.top();
		if(cur->left && !visited.count(cur->left)){
			s.emplace(cur->left);
		}
		else if(cur->right && !visited.count(cur->right)){
			s.emplace(cur->right);
		}
		else{
			s.pop();
			visited.emplace(cur);
			res.emplace_back(cur->val);
		}
	}
	return res;
}