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
	long prev_ = LONG_MIN;
	bool res = true;
public:
	// inorder recur
	void inorder(TreeNode * node){
		if(node -> left) inorder(node->left);
		if(prev_>= node->val) res = false;
		prev_ = node->val;
		if(node -> right) inorder(node->right);
	}
	bool isValidBST(TreeNode* root) {
		if(!root) return true ;
		inorder(root);
		
		return res;
		
	}
	
	//inorder iterative
	bool isValidBST_inorderIter(TreeNode* root) {
		
		stack<TreeNode*> s;
		long prev = LONG_MIN;
		
		while(root){
			s.emplace(root);
			root = root -> left;
		}
		while(!s.empty()){
			TreeNode* tmp = s.top();
			s.pop();
			if(tmp->val <= prev) return false;
			prev = tmp->val;
			tmp = tmp->right;
			while(tmp){
				s.emplace(tmp);
				tmp = tmp->left;
			}
		}
		return true;
		
	}
	
	
	//preorder recur
	bool helper(TreeNode* node, long  lb, long  ub){
		
		if(node->val <= lb || node->val >= ub) return false;
		
		bool left = true;
		bool right = true;
		if(node->left) left = helper(node->left, lb , node->val);
		if(node->right) right = helper(node->right, node->val, ub);
		return left && right;
	}
	
	bool isValidBST_preorder(TreeNode* root) {
		if(!root) return true;
		return helper(root, LONG_MIN, LONG_MAX);
	}
	
	//pre order iter
	bool isValidBST_(TreeNode* root) {
		long lb = LONG_MIN, ub = LONG_MAX;
		stack<TreeNode*> s;
		stack<long> lower;
		stack<long> upper;
		if(!root) return true;
		s.emplace(root);
		lower.emplace(lb);
		upper.emplace(ub);
		while(!s.empty()){
			TreeNode* cur = s.top();
			s.pop();
			lb = lower.top();
			lower.pop();
			ub = upper.top();
			upper.pop();
			
			if(cur -> val >= ub || cur->val <= lb){
				return false;
			}
			if(cur -> right){
				s.emplace(cur->right);
				lower.emplace(cur->val);
				upper.emplace(ub);
			}
			if(cur -> left){
				s.emplace(cur->left);
				lower.emplace(lb);
				upper.emplace(cur->val);
			}
			
		}
		return true;
	}
	
	
};