int singleNonDuplicate(vector<int>& nums) {
	int left = 0, right = nums.size() - 1;
	while(left < right){
		int mid = (left + right) / 2;
		if(mid % 2 == 0){// potential pos
			if(nums[mid] == nums[mid + 1]) left = mid + 2;
			else if(nums[mid] == nums[mid - 1]) right= mid - 2;
			else return nums[mid];
		}
		else{
			if(nums[mid] == nums[mid + 1]) right = mid - 1;
			else left = mid + 1;
		}
	}
	return nums[left];
}
