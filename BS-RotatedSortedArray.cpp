//search pivot
int findMin(vector<int>& nums) {
	int n = nums.size();
	int l = 0;
	int r = n - 1;
	while(l < r){
		int mid = (l + r) / 2;
		if(nums[mid] > nums[r]){
			l = mid + 1;
		}
		else{
			r = mid;
		}
	}
	return nums[l];
}


//search random num
int search(vector<int>& nums, int target) {
		// search for the smallest number.
	if(nums.size() == 0) return -1;
	int left = 0;
	int right = nums.size()-1;
	while(left < right){
		int mid = left + (right - left) / 2;
		if(nums[mid] < nums[right]){
			right = mid;
		}
		else{
			left = mid + 1;    
		}
	}
	int pivotPos = left;
	if(target < nums[pivotPos]) return -1;
	else{
		if(target > nums.back()) {
			left = 0;
			right = pivotPos; 
		}
		else {
			left = pivotPos;
			right = nums.size();
		}
	}
	int pos = lower_bound (nums.begin() + left, nums.begin() + right, target) - nums.begin();
	return nums[pos] == target? pos : -1;
}
