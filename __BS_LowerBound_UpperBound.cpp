int lowerbound(vector<int>& nums, int target){
		int l = 0, r = nums.size();
		while(l < r){
			int mid = (l + r) / 2;
			if(nums[mid] < target){
				l = mid + 1;
			}
			else{
				r = mid;
			}
		}
		return l;
	}
	int upperbound(vector<int>& nums, int target){
		int l = 0, r = nums.size();
		while(l < r){
			int mid = (l + r) / 2;
			if(nums[mid] <= target){
				l = mid + 1;
			}
			else{
				r = mid;
			}
		}
		return l;
	}