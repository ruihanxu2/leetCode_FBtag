int uniquePaths(int m, int n) {
	vector<int> dp(n, 0);
	dp[0] = 1;
	for(int j = 0; j < m; j++){
		for(int i = 1; i < n; i++){
			dp[i] = dp[i - 1] + dp[i];
		}
	}
	return dp[n-1];
	
}
