// recursive inorder + scan O(n) O(n)
// iterative inorder, stop after finded
// O(k)

class Solution {
public:
	int closestValue(TreeNode* root, double target) {
		int res = root->val;
		while(root){
			res = abs(res - target) < abs(root->val - target) ? res : root->val;
			root = root->val < target ? root->right:root->left;
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