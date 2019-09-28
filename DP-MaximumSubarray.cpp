class Solution_ {
public:
	int maxSubArray(vector<int>& nums) {
		int n = nums.size();
		vector<int> dp(n + 1);
		dp[0] = -1;
		int res = INT_MIN;
		
		for(int i = 1; i <= n; i++){
			if(dp[i - 1] > 0){
				dp[i] = dp[i - 1] + nums[i - 1];
			}
			else{
				dp[i] = nums[i - 1];
			}
			res = max(res, dp[i]);
		}
		return res;
	}
};

class Solution {
public:
	int maxSubArray(vector<int>& nums) {
		int n = nums.size();
		vector<int> dp(n + 1);
		int dp1 = -1;
		int dp2 = 0;
		int res = INT_MIN;
		
		for(int i = 1; i <= n; i++){
			if(dp1 > 0){
				dp2 = dp1 + nums[i - 1];
			}
			else{
				dp2 = nums[i - 1];
			}
			res = max(res, dp2);
			dp1 = dp2;
		}
		return res;
	}
};