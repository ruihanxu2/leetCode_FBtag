bool isCompleteTree(TreeNode* root) {
	queue<TreeNode*> q;
	bool seenNULL = false;
	q.emplace(root);
	while(!q.empty()){
		TreeNode* cur = q.front();
		q.pop();
		if(!cur){
			seenNULL = true;
		}else{
			if(seenNULL) return false;
			q.emplace(cur->left);
			q.emplace(cur->right);
		}
	}
	return true;
}
// count
bool isCompleteTree_(TreeNode* root) {
	vector<TreeNode*> q;
	int i = 0;
	q.emplace_back(root);
	while(i < q.size() && q[i]){
		q.emplace_back(q[i]->left);
		q.emplace_back(q[i]->right);
		i++;
	}
	while(i < q.size() && !q[i]){
		i++;
	}
	return i == q.size();
}
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

