bool wordBreak(string S, vector<string>& wordDict) {
	unordered_set<string> s(wordDict.begin(), wordDict.end());
	vector<bool> dp(S.size() + 1, false);
	dp[0] = true;
	for(int i = 1; i <= S.size(); i++){
		for(int j = i - 1 ; j >= 0; j--){
			if(dp[j]&&s.count(S.substr(j, i - j))){
				dp[i] = true;
				break;
			}
		}
	}
	return dp.back();
}
