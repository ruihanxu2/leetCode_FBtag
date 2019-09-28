/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
	stack<TreeNode*> s;
	void pushToStack(TreeNode* node){
		while(node){
			s.emplace(node);
			node = node->left;
		}
	}
public:
	BSTIterator(TreeNode* root) {
		pushToStack(root);
	}
	
	/** @return the next smallest number */
	int next() {
		TreeNode* cur = s.top();
		s.pop();
		pushToStack(cur->right);
		return cur->val;
		
	}
	
	/** @return whether we have a next smallest number */
	bool hasNext() {
		return !s.empty();
	}
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */