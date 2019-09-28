bool res = true;
int dfs(TreeNode* root){
	if(!root->left && !root->right) return 0;
	
	int left = 0;
	int right = 0;
	if(root->left) left = dfs(root->left)+1;
	if(root->right) right = dfs(root->right)+1;
	
	if(abs(left - right) > 1) res = false;
	
	return max(left, right);        
}
bool isBalanced(TreeNode* root) {
	if(!root) return true;
	dfs(root);
	return res;
}
