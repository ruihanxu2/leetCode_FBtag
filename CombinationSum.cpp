void dfs(vector<vector<int> >& res, vector<int>& cur, int pos, int curSum, int target, vector<int>& candidates){
	if(curSum > target) return;
	else if(curSum == target){
		res.emplace_back(cur);
		return;
	}
	else{
		for(int i = pos; i < candidates.size(); i++){
			cur.emplace_back(candidates[i]);
			dfs(res, cur, i, curSum+candidates[i], target, candidates);
			cur.pop_back();
		}
		
		
	}
}
vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
	vector<vector<int>> res;
	vector<int> cur;
	dfs(res, cur, 0, 0, target, candidates);
	return res;
}