int pivotIndex(vector<int>& nums) {
	vector<int> prefix(nums.size() + 1, 0);
	for(int i = 1; i < prefix.size(); i++){
		prefix[i] = prefix[i-1] + nums[i-1];
	}
	for(int i = 1; i < prefix.size(); i++){
		if(prefix[i-1] == prefix.back() - prefix[i]){
			return i - 1;
		}
	}
	return -1;
	
}

// O1space

int pivotIndex(vector<int>& nums) {
	int sum = 0;
	int leftSum = 0;
	for(int i = 0; i < nums.size(); i++){
		sum+=nums[i];
	}
	for(int i = 0; i < nums.size(); i++){
		if(leftSum == sum - leftSum - nums[i]){
			return i;
		}
		leftSum+=nums[i];
	}
	return -1;
	
}
