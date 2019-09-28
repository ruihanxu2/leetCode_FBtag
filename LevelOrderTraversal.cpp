//dfs
void dfs(TreeNode* root, int level, vector<vector<int> >& res){
	if(!root) return;
	if(level == res.size()) res.emplace_back(vector<int>());
	res[level].emplace_back(root->val);
	dfs(root->left, level + 1, res);
	dfs(root->right, level + 1, res);
	
}
vector<vector<int>> levelOrder_dfs(TreeNode* root) {
	vector<vector<int>> res;
	dfs(root, 0, res);
	return res;
}

//bfs
vector<vector<int>> levelOrder(TreeNode* root) {
	vector<vector<int>> res;
	
	queue<TreeNode*> q;
	if(root) q.emplace(root);
	while(!q.empty()){
		vector<int> curLevel;
		int n = q.size();
		for(int i = 0; i < n; i++){
			TreeNode* cur = q.front();
			curLevel.emplace_back(cur->val);
			if(cur->left)q .emplace(cur->left);
			if(cur->right) q.emplace(cur->right);
			q.pop();
			
		}
		res.emplace_back(curLevel);
		
	}
	return res;
}


//zig zag

vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
	vector<vector<int>> res;

	deque<TreeNode*> q;
	bool flag = true;
	if(root) q.emplace_back(root);

	while(!q.empty()){
		vector<int> curLevel;
		int n = q.size();
		for(int i = 0; i < n; i++){
			if(flag){
				TreeNode* cur = q.front();
				curLevel.emplace_back(cur->val);
				if(cur->left) q.emplace_back(cur->left);
				if(cur->right) q.emplace_back(cur->right);
				q.pop_front();
			}
			else{
				TreeNode* cur = q.back();
				curLevel.emplace_back(cur->val);
				if(cur->right) q.emplace_front(cur->right);
				if(cur->left) q.emplace_front(cur->left);
				q.pop_back();

			}


		}
		flag = !flag;
		res.emplace_back(curLevel);

	}
	return res;
}