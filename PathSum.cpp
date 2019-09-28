bool dfs(TreeNode* root, int curSum){
	if(!root) return false;
	if(!root->left && !root->right){
		if(root->val == curSum) return true;
		else return false;
	}
	
	return dfs(root->left, curSum - root->val) || dfs(root->right, curSum - root->val);
}
bool hasPathSum(TreeNode* root, int sum) {
	return dfs(root, sum);
}