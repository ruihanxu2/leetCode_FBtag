TreeNode* deleteNode(TreeNode* root) {
    if(!root) return root;

    while(root->mod‍‌‌‍‌‍‌‍‌‍‍‌‍‌‍‍‍‌‌e == 0){
        if(!root->left || !root->right){
            root = (root->left)? root->left : root->right;
        }else{
            TreeNode *cur = root->left;
            while(cur->right) cur = cur->right;
            root->val = cur->val;
            root->mode = cur->mode;
            cur->mode = 0;
            root->left = deleteNode(root->left);
        }
    }
		if(root){
			root->left = deleteNode(root->left);
			root->right = deleteNode(root->right);
		}
        
    
    return root;
}


//


class Solution {
public:
	TreeNode* deleteNode(TreeNode* root, int key) {
		if(!root) return root;
		if(root->val > key){
			root->left = deleteNode(root->left, key);
		}
		else if(root ->val < key){
			root->right = deleteNode(root->right, key);
		}
		else{
			if(!root->left || !root->right){
				TreeNode* res = root->left ? root->left : root->right;
				delete root;
				return res;
			}
			else{
				// two child
				TreeNode* tmp = root->right;
				while(tmp->left){
					tmp = tmp->left;
				}
				root->val = tmp->val;
				root->right = deleteNode(root->right, tmp->val);
				return root;
			}
		}
		return root;
	}
};

/*
3轮1.5题。有点像利口驷吾零。说有一个balanced BST，treeNode除val外，还有一个值为Mode。mode值不确定，可以为0或非0.mode对树结构无影响。要删除树中所有mode为0的节点。
因为没见过这题，老王反正强行解，1遍历树找到要删的vals。2候检find函数删掉要删的所有nodes。强行刚30分钟后，写出整墙大约能行的代码。最后跑了两个test case可行。
但小哥说最优方法为在recursion中进行删除。后拍照say bye。

*/




class TreeNode(ob‍‌‌‍‌‍‌‍‌‍‍‌‍‌‍‍‍‌‌ject):
    def __init__(self, val, mode):
        self.val = val
        self.mode = mode
        self.left = None
        self.right = None

class Solution(object):
    def deleteNode(self, root):
        # 中序遍历找第一个mode不为0的节点。
        def findMin(node):
            if not node: return
            findMin(node.left)
            if node.mode != 0:
                self.newRoot = node
                return
            findMin(node.right)
        
        if not root: return None
        if root.mode != 0:
            root.left = self.deleteNode(root.left)
            root.right = self.deleteNode(root.right)
            return root
        else:
            self.newRoot = None
            findMin(root.right)  # 中序遍历找右子树第一个mode不为0节点。
            # 没找到， 那么右子树没有mode不为0的点， 那么直接处理左子树。
            if self.newRoot is None:
                return self.deleteNode(root.left)
            #找到了一个，那么把值和mode跟root对换。
            else:
                root.val = self.newRoot.val
                root.mode = self.newRoot.mode
                self.newRoot.mode = 0
                root.left = self.deleteNode(root.left)
                root.right = self.deleteNode(root.right)
                return root