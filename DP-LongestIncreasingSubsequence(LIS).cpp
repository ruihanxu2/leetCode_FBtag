//stores the potential chance of having a longer subsequence
int lengthOfLIS(vector<int>& nums) {
	vector<int> dp;
	if(nums.size() == 0) return 0;
	dp.emplace_back(nums[0]);
	for(auto num : nums){
		if(num > dp.back()) dp.emplace_back(num);
		else{
			int pos = lower_bound(dp.begin(), dp.end(), num) - dp.begin();
			dp[pos] = num;
		}
	}
	return dp.size();
}


//dp[i] = max(dp[i], dp[j] + 1) where j = [0, i-1)
int lengthOfLIS(vector<int>& nums) {
	int n = nums.size();
	if(n == 0) return 0;
	vector<int> dp(n, 1);
	for(int i = 1; i < n; i++){
		for(int j = 0; j < i; j++){
			if(nums[j] < nums[i])
				dp[i] = max(dp[i], dp[j] + 1);
		}
	}
	int res = *max_element(dp.begin(), dp.end());
	return res;
}