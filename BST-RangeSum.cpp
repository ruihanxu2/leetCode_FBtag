
class Solution_recur {
public:
	int rangeSumBST(TreeNode* root, int L, int R) {
		if(!root) return 0;
		if(root->val < L){
			return rangeSumBST(root->right, L, R);
		}
		else if(root->val > R){
			return rangeSumBST(root->left, L, R);
		}
		else{
			return root->val + rangeSumBST(root->right, L, R) + rangeSumBST(root->left, L, R);
		}
	}
};


class Solution {
public:
	int rangeSumBST(TreeNode* root, int L, int R) {
		stack<TreeNode*> s;
		int res = 0;
		if(!root) return res;
		s.emplace(root);
		while(!s.empty()){
			TreeNode* cur = s.top();
			s.pop();
			if(cur->val >= L && cur->val <= R){
				res += cur->val;
			}
			if(cur->val < R){
				if(cur->right) s.emplace(cur->right);
			}
			if(cur->val > L){
				if(cur->left) s.emplace(cur->left);
			}
		}
		return res;
	}
};
class Solution_naive {
	int res = 0;
public:
	void dfs(TreeNode* root, int L, int R){
		if(!root) return;
		if(root->val <= R && root->val >= L){
			res+=root->val;
		}
		dfs(root->left, L, R);
		dfs(root->right, L, R);
		
	}
	int rangeSumBST(TreeNode* root, int L, int R) {
		dfs(root,  L, R);
		return res;
	}
};
