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
	unordered_map<int, int> inorderPos;
	TreeNode* helper(vector<int>& preorder,int preS, int preE, vector<int>& inorder, int inS, int inE){
		if(preS >= preE || inS >= inE) return NULL;
		
		int val = preorder[preS];
		TreeNode *node = new TreeNode(val);
		int pos = inorderPos[val];
		int length = pos - inS;
		node->left = helper(preorder, preS+1, preS+1+length, inorder, inS , inS + length);
		node->right = helper(preorder, preS+1+length, preE, inorder, pos+1, inE);
		return node;
		
	}
public:
	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
		for(int i = 0; i < inorder.size(); i++){
			inorderPos[inorder[i]]= i;
		}
		return helper(preorder, 0, preorder.size(), inorder, 0, inorder.size());
		
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
	vector<int> preorder;
	vector<int> inorder;
	unordered_map<int, int> inorder_map;
	TreeNode* helper(int preS, int preE, int inS, int inE){
		if(preS >= preE || inS >= inE) return NULL;
		int val = preorder[preS];
		TreeNode* node = new TreeNode(val);
		int inorderPos = inorder_map[val];
		int inSLeft = inS;
		int inELeft = inorderPos;
		int inSRight = inorderPos + 1;
		int inERight = inE;
		int preSLeft = preS + 1;
		int preELeft = preSLeft + inELeft - inSLeft;
		int preSRight = preELeft;
		int preERight = preE;
		node->left = helper(preSLeft, preELeft, inSLeft, inELeft);
		node->right = helper(preSRight, preERight, inSRight, inERight);
		return node;
		
	}
public:
	TreeNode* buildTree(vector<int>& preorder_, vector<int>& inorder_) {
		preorder = preorder_;
		inorder = inorder_;
		for(int i = 0; i < inorder.size(); i++){
			inorder_map[inorder[i]] = i;
		}
		return helper(0, preorder.size(), 0, inorder.size());
	}
};