//sort then linear scan

//sort then bs
int findDuplicate(vector<int>& nums) {
	int left = 0, right = nums.size() - 1;
	sort(nums.begin(), nums.end());
	while(left < right-1){
		int mid = (left + right) / 2;
		if(nums[mid] <= mid){
			right = mid;
		}
		else{
			left = mid;
		}
	}
	return nums[left];
}

//unordered_set

//cycle
int findDuplicate(vector<int>& nums) {
	int slow = 0;
	int fast = 0;
	do{
		slow = nums[slow];
		fast = nums[nums[fast]];
	}
	while(slow != fast);
	fast = 0;
	while(slow != fast){
		slow = nums[slow];
		fast = nums[fast];
	}
	return fast;
}