/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec_recur {
public:
	
	// Encodes a tree to a single string.
	string serialize(TreeNode* root) {
		string res;
		if(!root) return res;
		return to_string(root->val) + " " + serialize(root->left) + " " + serialize(root->right);
	}
	
	TreeNode* helper(vector<int> data, int& pos, int ub, int lb){
		if(pos == data.size()) return nullptr;
		if(data[pos] > ub || data[pos] < lb ) return nullptr;
		TreeNode* newNode = new TreeNode(data[pos++]);
		newNode->left = helper(data, pos, newNode->val, lb);
		newNode->right = helper(data, pos, ub ,newNode->val);
		
		return newNode;
	}
	
	// Decodes your encoded data to tree.
	TreeNode* deserialize(string data) {
		vector<int> elements;
		istringstream iss(data);
		string tmp;
		while(iss >> tmp){
			elements.emplace_back(stoi(tmp));
		}
		int pos = 0;
		
		return helper(elements, pos, INT_MAX, INT_MIN);
		
	}
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));

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
public:
	
	// Encodes a tree to a single string.
	string serialize(TreeNode* root) {
		if(!root) return "";
		string res = "";
		res += to_string(root->val) + " "+ serialize(root->left) + serialize(root->right);
		return res;
	}
	
	// Decodes your encoded data to tree.
	TreeNode* deserialize(string data) {
		if(data.empty()) return nullptr;
		vector<int> elements;
		stack<TreeNode*> s;
		istringstream iss(data);
		string tmp;
		while(iss >> tmp){
			elements.emplace_back(stoi(tmp));
		}
		int pos = 0;
		
		TreeNode* res = new TreeNode(elements[pos]);
		s.emplace(res);
		for(int i = 1; i < elements.size(); i++){
			TreeNode* newNode = new TreeNode(elements[i]);
			TreeNode* prev = s.top();
			if(newNode->val < prev->val){
				prev -> left = newNode;
			}
			else{
				while(!s.empty() &&  s.top() -> val < newNode->val){
					prev = s.top();
					s.pop();
				}
				prev->right = newNode;
			}
			s.emplace(newNode);
		}
		
		return res;
		
		
	}
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));