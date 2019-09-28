//---------------BT case LC 865

class Solution {
	TreeNode* LCA(TreeNode* root, TreeNode* p, TreeNode* q){
		if(!root) return nullptr;
		if(root == p || root == q) return root;
		TreeNode* left = LCA(root->left, p, q);
		TreeNode* right = LCA(root->right, p, q);
		if(left == nullptr && right == nullptr) return nullptr;
		else if(left && right) return root;
		else return left ? left : right;
	}
public:
	TreeNode* subtreeWithAllDeepest(TreeNode* root) {
		if(!root) return nullptr;
		queue<TreeNode*> q;
		q.emplace(root);
		TreeNode* leftMost = nullptr;
		TreeNode* rightMost = nullptr;
		while(!q.empty()){
			int n = q.size();
			for(int i = 0; i < n; i++){
				TreeNode* cur = q.front();
				q.pop();
				if(i == 0) leftMost = cur;    
				if(i == n - 1) rightMost = cur;
				if(cur->left) q.emplace(cur->left);
				if(cur->right) q.emplace(cur->right);
			}
		}
		if(leftMost == rightMost) return leftMost;
		else return LCA(root, leftMost, rightMost);
		
	}
};
// n-ary case


class Solution {
	TreeNode* LCA(TreeNode* root, TreeNode* p, TreeNode* q){
		if(!root) return nullptr;
		if(root == p || root == q) return root;
		
		int count = 0;
		TreeNode* tmp;
		for(auto nei : root->neighbors){
			if(LCA(nei)){
				count++;
				tmp = nei;
			}
		}
		if(count == 0) return nullptr;
		else if(count == 1) return tmp;
		else return root;
	}
public:
	TreeNode* subtreeWithAllDeepest(TreeNode* root) {
		if(!root) return nullptr;
		queue<TreeNode*> q;
		q.emplace(root);
		TreeNode* leftMost = nullptr;
		TreeNode* rightMost = nullptr;
		while(!q.empty()){
			int n = q.size();
			for(int i = 0; i < n; i++){
				TreeNode* cur = q.front();
				q.pop();
				if(i == 0) leftMost = cur;    
				if(i == n - 1) rightMost = cur;
				for(auto nei : cur->neighbors){
					q.emplace(nei);
				}
			}
		}
		if(leftMost == rightMost) return leftMost;
		else return LCA(root, leftMost, rightMost);
		
	}
};
