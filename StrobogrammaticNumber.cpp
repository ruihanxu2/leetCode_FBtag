//if strobogrammatic number
class Solution {
public:
	bool isStrobogrammatic(string num) {
		int n = num.size();
		unordered_map<char, char> m = {
			{'6', '9'},
			{'9', '6'},
			{'1', '1'},
			{'0', '0'},
			{'8', '8'}
		};
		for(int i = 0; i <= n / 2; i++){
			if(!m.count(num[i])) return false;
			if(num[i] != m[num[n - 1 -i]]) return false;
		}
		return true;
	}
};

//找到给定长度的所有strobogrammatic Number
class Solution {
public:
	vector<string> helper(int pos, int n){
		vector<string> res;
		if(pos == 0) return vector<string>{""};
		if(pos == 1) return vector<string>{"0", "1", "8"};
		vector<string> prev = helper(pos - 2, n);
		for(auto s : prev){
			if(pos != n) res.emplace_back("0"+s+"0");
			res.emplace_back("1"+s+"1");
			res.emplace_back("8"+s+"8");
			res.emplace_back("6"+s+"9");
			res.emplace_back("9"+s+"6");
		}
		return res;
	}
	vector<string> findStrobogrammatic(int n) {
		return helper(n, n);
	}
};