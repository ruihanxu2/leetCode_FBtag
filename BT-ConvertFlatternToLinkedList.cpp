// postorder right, left, node
    1
	 / \
	2   5
 / \   \
3   4   6
-----------        
pre = 5
cur = 4

		1
	 / 
	2   
 / \   
3   4
		 \
			5
			 \
				6
-----------        
pre = 4
cur = 3

		1
	 / 
	2   
 /   
3 
 \
	4
	 \
		5
		 \
			6
-----------        
cur = 2
pre = 3

		1
	 / 
	2   
	 \
		3 
		 \
			4
			 \
				5
				 \
					6
-----------        
cur = 1
pre = 2

1
 \
	2
	 \
		3
		 \
			4
			 \
				5
				 \
					6
					
					
// reverse preorder
					
class Solution {
	TreeNode* prev;
public:
	void flatten(TreeNode* root) {
		if(!root) return;
		flatten(root->right);
		flatten(root->left);
		root->right = prev;
		root->left = NULL;
		prev = root;
		return;
	}
};


//iterative
// 把右子树往左边最右节点移， 然后把左子树设为右子树，node->right = node->left
void flatten(TreeNode* root){
	TreeNode* cur = root;
	while(cur){
		if(cur->left){
			TreeNode* tmp = cur->left;
			while(tmp->right){
				tmp = tmp->right;  
			}
			tmp->right = cur->right;
			cur->right = cur->left;
			cur->left = NULL;
		}
		cur = cur->right;
	}
}
