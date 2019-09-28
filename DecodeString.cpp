// 3[abc] aaa
// 3[2[a]b] aabaabaab
// 2[] ""
// 3[a]3[b]

// key point is we need to pass the pos with ref

class Solution {
	string helper(string &s, int &pos){
		 
		string res; // string in this recur
		
		for(; pos < s.size() && s[pos]!=']'; ){
			if(!isdigit(s[pos])){
				res+=s[pos++];
			}
			else{
				int num = 0; // repeat time
				while(isdigit(s[pos])){
					num = num*10 + s[pos] - '0';
					pos++;  
				}
				pos++; // skip [
				string prev = helper(s, pos);
				pos++; // skip ]

				while(num-- > 0){
					res+=prev;
				} 
			}
		}
		
		return res;
	}
public:
	string decodeString(string s) {
		int pos = 0;
		return helper(s, pos);
	}
};


class Solution {
public:
	string decodeString(string s) {
		stack<string> chars;
		stack<int> nums;
		string res;
		int num = 0;
		for(char c : s) {
			if(isdigit(c)) {
				num = num*10 + (c-'0');                              
			}
			else if(isalpha(c)) {
				res.push_back(c);                
			}
			else if(c == '[') {
				chars.push(res);
				nums.push(num);
				res = "";
				num = 0;
			}
			else if(c == ']') {
				string tmp = res;
				for(int i = 0; i < nums.top()-1; ++i) {
					res += tmp;
				}
				res = chars.top() + res;
				chars.pop(); nums.pop();
			}
		}
		return res;
	 }
};