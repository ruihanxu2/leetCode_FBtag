/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
private:
	void dfs_serialize(TreeNode* root, string& res){
		if(!root){
			res += "# ";
		}else{
			res += to_string(root->val) + " ";
			dfs_serialize(root->left, res);
			dfs_serialize(root->right, res);
		}
	}
	TreeNode* dfs(istringstream& iss){
		string tmp;
		iss>>tmp;
		if(tmp == "#"){
			return NULL;
		}else{
			int val = stoi(tmp);
			TreeNode* cur = new TreeNode(val);
			cur->left = dfs(iss);
			cur->right = dfs(iss);
			return cur;
		}
	}
	
public:

	// Encodes a tree to a single string.
	string serialize(TreeNode* root) {
		string res;
		dfs_serialize(root, res);
		return res;
	}

	// Decodes your encoded data to tree.
	TreeNode* deserialize(string data) {
		istringstream iss(data);
		return dfs(iss);
	}
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));