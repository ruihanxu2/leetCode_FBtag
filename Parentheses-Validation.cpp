class Solution {
public:
	bool isValid(string s) {
		stack<char> stk;
		unordered_map<char, char> m{{')', '('},{']', '['},{'}', '{'}};
		for(int i = 0; i < s.size(); i++){
			if(m.count(s[i])){
				if(stk.empty()) return false;
				char cur = stk.top();
				stk.pop();
				if(m[s[i]] != cur) return false;
			}
			else if(s[i] == '(' ||s[i] == '[' ||s[i] == '{'){
				stk.emplace(s[i]);
			}
		}
		return stk.empty();
	}
};