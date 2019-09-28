vector<int> countBits(int num) {
	int mul = 1;
	int count = 1;
	int n = num;
	vector<int> dp(1, 0);
	for(int i = 1; i <= n; i++){
		if(i % 2 == 0) dp.emplace_back(dp[i/2]);
		else{
			dp.emplace_back(dp[i/2]+1);
		}
	}
	return dp;
}