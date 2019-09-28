void dfs(vector<string>& res, string cur, int left, int right, int max_l){
	if(cur.size() == 2*max_l) res.emplace_back(cur);
	else{
		if(left < max_l){
			dfs(res, cur+'(', left+1, right, max_l);
		}
		if(right < left){
			dfs(res, cur+')', left, right+1, max_l);
		}
	}
}
vector<string> generateParenthesis(int n) {
	vector<string> res;
	dfs(res, "", 0, 0, n);
	return res;
}

//dfs， 记录当前左右括号的数量