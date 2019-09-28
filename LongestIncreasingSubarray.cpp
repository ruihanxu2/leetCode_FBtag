int findLengthOfLCIS(vector<int>& nums) {
	int anchor = 0;
	int res = 0;
	for(int i = 0; i < nums.size(); i++){
		if(i>0 && nums[i] <= nums[i-1]){
			anchor = i;
		}
		res = max(res, i - anchor + 1);
	}
	return res;
}
