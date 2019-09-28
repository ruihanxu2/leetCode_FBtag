class Solution {
public:
	long parseNum(string& s, int& i){
		long res = 0;
		while(isdigit(s[i])){
			res*=10;
			res += s[i] - '0';
			i++;
		}
		return res;
	}
	int calculate(string s) {
		vector<int> operands;
		int res = 0;
		int tmp = 0;
		char op = '+';
		for(int i = 0; i < s.size(); i++){
			if(isspace(s[i])) continue;
			long val = parseNum(s, i);
			switch(op){
				case '+': operands.emplace_back(val); break;
				case '-': operands.emplace_back(-val); break;
				case '*': operands.back() *= val; break;
				case '/': operands.back() /= val; break;
			}
			if(i < s.size()) op = s[i];
			
		}
		for(auto n : operands){
			res+=n;
		}
		return res;
	}
};

// an important note is that: the operator is switch is actuall the previous operator