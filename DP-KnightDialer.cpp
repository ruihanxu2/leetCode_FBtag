class Solution{
public:
	int knightDialer(int N){
		int mod = 1000000007;
		vector<long> dp(10, 1);
		for(int i = 1; i < N; i++){
			vector<long> tmp(10, 0);
			tmp[1] = dp[6] + dp[8];
			tmp[2] = dp[7] + dp[9];
			tmp[3] = dp[4] + dp[8];
			tmp[4] = dp[3] + dp[9] + dp[0];
			tmp[5] = 0;
			tmp[6] = dp[1] + dp[7]+ dp[0];
			tmp[7] = dp[2] + dp[6];
			tmp[8] = dp[1] + dp[3];
			tmp[9] = dp[2] + dp[4];
			tmp[0] = dp[4] + dp[6];
			for(auto& n : tmp){
				n%=mod;
			}
			dp = tmp;
		}
		long res = 0;
		for(auto& n : dp){
      n%=mod;
			res+=n;
      res%=mod;
		}
		return res%mod;
	}
};
