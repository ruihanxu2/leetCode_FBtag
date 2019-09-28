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
	int dfs(TreeNode* node){
		if(!node) return 0;
		int left = 0;
		int right = 0;
		left = max(left, dfs(node->left));
		right = max(right, dfs(node->right));
		
		int curMax = left + right + node->val;
		res = max(res, curMax);
		return max(right + node->val, left + node->val);
	}
	int res = INT_MIN;
public:
	
	int maxPathSum(TreeNode* root) {
		dfs(root);
		return res;
	}
};