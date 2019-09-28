
class Solution_recursive {
	void dfs(TreeNode* node, vector<string>& res, string cur){
		if(!node->left && !node->right) {
			cur+=to_string(node->val);
			res.emplace_back(cur);
		}
		else{
			cur += to_string(node->val) + "->";
			if(node->left) dfs(node->left, res, cur);
			if(node->right) dfs(node->right, res, cur);
		}
	}
	
public:
	vector<string> binaryTreePaths(TreeNode* root) {
		vector<string> res;
		if(!root) return res;
		dfs(root, res, "");
		return res;
	}
};

class Solution_iter {
public:
	vector<string> binaryTreePaths(TreeNode* root) {
		vector<string> res;
		if(!root) return res;
		stack<TreeNode*> s;
		stack<string> paths;
		s.emplace(root);
		paths.emplace(to_string(root->val));
		while(!s.empty()){
			TreeNode* cur = s.top();
			string curPath = paths.top();
			s.pop();
			paths.pop();
			if(!cur->left && !cur->right){
				res.emplace_back(curPath);
			}
			else{
				if(cur->right){
					s.emplace(cur->right);
					paths.emplace(curPath+"->"+to_string(cur->right->val));
				} 
				if(cur->left) {
					s.emplace(cur->left);
					paths.emplace(curPath+"->"+to_string(cur->left->val));
					
				}
			}
			
		}
		return res;
		
	}
};





/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */