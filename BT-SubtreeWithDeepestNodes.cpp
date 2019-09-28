
class Solution {
	TreeNode* res;
	int maxLevel = -1;
public:
	int postOrder(TreeNode* node, int level){
		if(!node->left && !node->right){
			if(level > maxLevel){
				res = node;
				maxLevel = level;
			}
			return level;
		}
		int left = 0, right = 0;
		if(node->left) left = postOrder(node->left, level + 1);
		if(node->right) right = postOrder(node->right, level + 1);
		
		if(left == right && left == maxLevel){
			res = node;
			return left;
		}
		else{
			return max(left, right);
		}
	}
	TreeNode* subtreeWithAllDeepest(TreeNode* root) {
		if(!root) return NULL;
		postOrder(root, 0);
		return res;
	}
};


//another methode is to use a map to recode <node*, depth>
//get the deepest level value
//post order again...

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */