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
	string parse(string& s, int &i){
		int start;
		if(i < s.size() && s[i] == '('){
			i++;
			start = i;
			int count = 1;
			while(count != 0){
				if(s[i] == '(') count++;
				else if(s[i] == ')') count--;
				i++;
			}
			return s.substr(start, i - start - 1);
		}
		return "";
		
	}
public:
	TreeNode* str2tree(string s){
		if(s.empty()) return NULL;
		int start = 0;
		int i = 0;
		while(i < s.size() && (isdigit(s[i]) || s[i] == '-')){
			i++;
		}
		int val = stoi(s.substr(start, i - start));
		TreeNode* node = new TreeNode(val);
		node-> left = str2tree(parse(s, i));
		node-> right = str2tree(parse(s, i));
		return node;
		
	}

};

class Solution_ {
public:
	TreeNode* str2tree(string s) {
		if(s == "") return nullptr;
		stack<TreeNode*> stk;
		for(int l = 0, r = l; l < s.size(); l = r ){
			if(s[l] == ')'){
				stk.pop();
				r++;
			}
			else if(s[l] == '('){
				r++;
			}
			else{
				while(isdigit(s[r]) || s[r] == '-'){
					r++;
				}
				int cur = stoi(s.substr(l, r - l));
				TreeNode* newNode = new TreeNode(cur);
				if(!stk.empty()){
					auto parent = stk.top();
					if(parent->left){
						parent->right = newNode;
					}
					else{
						parent->left = newNode;
					}
				}
				stk.emplace(newNode);
			}
		}
		return stk.empty() ? nullptr : stk.top();
	}
};
