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
	TreeNode* helper(int lb, int ub, vector<int>& preorder, int& pos){
		if(pos == preorder.size()) return NULL;
		int val = preorder[pos];
		if(val < lb || val > ub) return NULL;
		
		pos++;
		TreeNode* node  = new TreeNode(val);
		node->left = helper(lb, val, preorder, pos);
		node->right = helper(val, ub, preorder, pos);
		return node;
	}
	TreeNode* bstFromPreorder(vector<int>& preorder) {
		int pos = 0;
		return helper(INT_MIN, INT_MAX, preorder, pos);
	}
};


class Solution{
public:
	TreeNode* bstFromPreorder(vector<int>& preorder) {
		//iter
		stack<TreeNode*> s;
				if(preorder.empty()) return NULL;
				int pos = 0;
				TreeNode* res = new TreeNode(preorder[pos++]);
				while(pos < preorder.size()){
					int cur = s.top()->val;
					if(preorder[pos] < cur){
						TreeNode* newNode = new TreeNode(preorder[pos++]);
						s.emplace(newNode);
					}
					else{
						while(s.top()->val > preorder[pos]){
							// s will not be empty is valid preorder
							s.pop();
						}
						TreeNode* newNode = new TreeNode(preorder[pos++]);
						s.top()->right = newNode;
						s.emplace(newNode);
					}
				}
				return res;
	}
};