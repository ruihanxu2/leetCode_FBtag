vector<string> letterCombinations(string digits) {
	vector<string> keys = {"", "", "abc", "def", "ghi",
	"jkl", "mno", "pqrs", "tuv", "wxyz"};
	vector<string> res;
	if(digits.size() == 0) return res;
	dfs(digits, "", 0, res, keys);
	return res;
}
void dfs(string& digits, string cur, int pos, vector<string>& res, vector<string>& keys){
	if(pos == digits.size()) res.emplace_back(cur);
	else{
		for(int i = 0; i < keys[digits[pos] - '0'].size(); i++){
		cur+=keys[digits[pos] - '0'][i];
		dfs(digits, cur, pos+1, res, keys);
		cur.pop_back();
		}
	} 
}