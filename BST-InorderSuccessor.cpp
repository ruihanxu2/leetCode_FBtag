
TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
		if(!root||!p) return NULL;
		TreeNode* res = NULL;
		while(root){
			if(root->val <= p->val){
				root = root ->right;
			}
			else{
				res = root;
				root = root->left;
			}
		}
		return res;
		
	}

class Solution {
public:
	void pushToStack(TreeNode* root, stack<TreeNode*>& s){
		while(root){
			s.emplace(root);
			root = root -> left;
		}
	}
	TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
		if(!root || !p) return NULL;
		stack<TreeNode*> s;
		pushToStack(root, s);
		while(!s.empty()){
			TreeNode* cur = s.top();
			s.pop();
			pushToStack(cur->right, s);
			if(cur == p){
				if(s.empty()) return NULL;
				return s.top();
			}
		}
		return NULL;
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