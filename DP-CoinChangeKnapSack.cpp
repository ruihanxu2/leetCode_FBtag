class Solution{
public:
	int coinChange(vector<int>& coins, int n){
		vector<int> dp(n + 1, INT_MAX);
		dp[0] = 0;
		for(int i = 1; i <= n; i++){
			for(auto coin : coins){
				if(i - coin >= 0 && dp[i - coin] != INT_MAX){
					dp[i] = min(dp[i], dp[i - coin] + 1);
				}
			}
		}
		return dp.back() == INT_MAX ? -1 : dp.back();
	}
};