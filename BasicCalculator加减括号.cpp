class Solution{
private:
	long parseNum(string& s, int& i){
		long res = 0;
		while(isdigit(s[i])){
			res*=10;
			res += s[i++] - '0';
		}
		return res;
	}
public:
	int helper(string& s, int& i){
		vector<int> res;
		char op = '+';
		for(; i < s.size() && op!=')'; i++){
			if(isspace(s[i])) continue;
			long cur = s[i] == '(' ? helper(s, ++i) : parseNum(s, i);
			
			switch(op){
				case '+' : res.emplace_back(cur); break;
				case '-' : res.emplace_back(-cur); break;
			}
			op = s[i];
		}
		return accumulate(res.begin(), res.end(), 0);
	}
	int calculate(string s){
		int i = 0;
		return helper(s, i);
	}
	
};