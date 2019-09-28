//bfs
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
	vector<int> rightSideView(TreeNode* root) {
		queue<TreeNode*> q;
		if(root) q.emplace(root);
		vector<int> res;
		while(!q.empty()){
			int n = q.size();
			for(int i = 0; i < n; i ++){
				TreeNode* cur = q.front();
				q.pop();
				if(i == n - 1){
					res.emplace_back(cur->val);
				}
				if(cur->left) q.emplace(cur->left);
				if(cur->right) q.emplace(cur->right);
			}
		}
		return res;
	}
};

//dfs
lass Solution {
private:
	vector<int> res;
	void dfs(int level, TreeNode* node){
		if(!node) return;
		if(level == res.size()){
			res.emplace_back(node->val);
		}
		else{
			res[level] = node->val;
		}
		
		dfs(level + 1, node->left);
		dfs(level + 1, node->right);
	}
public:
	vector<int> rightSideView(TreeNode* root) {
		dfs(0, root);
		return res;
	}
};