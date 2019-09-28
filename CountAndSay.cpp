class Solution {
public:
	string doCountAndSay(string s){
		string res;
		int count = 0;
		for(int i = 0; i < s.size(); i++){
			count = 1;
			while(i < s.size() - 1 && s[i] == s[i + 1]){
				count++;
				i++;
			}
			res+=to_string(count) + s[i];
		}
		
		return res;
	}
	string countAndSay(int n) {
		string res = "1";
		for(int i = 2; i <= n; i++){
			res = doCountAndSay(res);
		}
		return res;
	}
};