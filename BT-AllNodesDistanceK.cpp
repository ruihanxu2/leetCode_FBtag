/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution_ {
public:
	void findBelow(TreeNode* root, int K, vector<int>& res){
		if(!root) return;
		if(K == 0){
			res.emplace_back(root->val);
			return;
		}
		findBelow(root->left, K - 1, res);
		findBelow(root->right, K - 1, res);
		
	}
	int postOrder(TreeNode* root, int K, TreeNode* target, vector<int>& res){
		if(!root) return -1;
		if(root == target){
			findBelow(root, K, res);
			return 1;
		}
		int left = postOrder(root->left, K, target, res);
		int right = postOrder(root->right, K, target, res);
		
		if(left == -1 && right == -1){
			//not in this branch
			return -1;
		}
		else if(left == -1){
			//in right branch
			if(right == K) res.emplace_back(root->val);
			else if(right < K){
				findBelow(root->left, K-right-1, res);
			}
			return right + 1;
		}
		else{
			//in left branch
			if(left == K) res.emplace_back(root->val);
			else if(left < K){
				findBelow(root->right, K-left-1, res);
			}
			return left + 1;
		}
	}
	vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
		vector<int> res;
		postOrder(root, K, target, res);
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
class Solution {
   
	unordered_map<TreeNode*, TreeNode*> parent;
	void preorder(TreeNode* node){
		if(node->left) {
			parent[node->left] = node;
			preorder(node->left);
		}
		if(node->right){
			parent[node->right] = node;
			preorder(node->right);
		}
		
	}
public:
	
	vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
		vector<int> res;// node vals
		if(!root) return res;
		preorder(root);// get parents
		queue<TreeNode*> q;
		q.emplace(target);
		unordered_set<TreeNode*> visited;
		while(!q.empty()){
			int n =  q.size();
			for(int i = 0; i < n; i++){
				
				TreeNode* cur = q.front();
				q.pop();
				visited.insert(cur);
				if(k == 0){
					res.emplace_back(cur->val);
					continue;
				} 
				if(cur->left && !visited.count(cur->left)) q.emplace(cur->left);
				if(cur->right&& !visited.count(cur->right)) q.emplace(cur->right);
				if(parent.count(cur)&& !visited.count(parent[cur])) q.emplace(parent[cur]);
				
			}
			if(k == 0) return res;
			k--;
		}
		
		
		return res;
		
	}
};