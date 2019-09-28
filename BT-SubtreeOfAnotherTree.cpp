/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

bool isSame(TreeNode* s, TreeNode* t){
	if(!s&&!t) return true;
	else if(!s&&t||!t&&s) return false;
	else{
		if(s->val == t->val){
			return isSame(s->left, t->left) && isSame(s->right, t->right);
		}
		else{
			return false;
		}
	}
}
bool isSubtree(TreeNode* s, TreeNode* t) {
	if(!s&&!t) return true;
	else if(!s&&t||!t&&s) return false;
	else{
		if(s->val == t->val){
			if(isSame(s, t)) return true;
		}
	}
	return isSubtree(s->left, t) || isSubtree(s->right, t);
}
