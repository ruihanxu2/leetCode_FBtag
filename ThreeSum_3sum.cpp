vector<vector<int> > threeSum(vector<int>& nums) {
	sort(nums.begin(), nums.end());
	int n = nums.size();
	vector<vector<int> > res;
	for(int i = 0; i < n - 2; i++){
		if(i > 0 && nums[i] == nums[i-1]) continue; // skip duplicate
		if(nums[i]+nums[i+1]+nums[i+2] > 0) break;
		else if(nums[i]+nums[n-1]+nums[n-2] < 0) continue;
		else{
			int low = i + 1;
			int high = n - 1;
			while(low < high){
				int sum=nums[i]+nums[low]+nums[high];
				if(sum>0) high--;
				else if(sum<0) low++;
				else{
					res.emplace_back(vector<int>{nums[i],nums[low],nums[high]});
					while(low<high&&nums[low]==nums[low+1]) low++;
					while(low<high&&nums[high]==nums[high-1]) high--;
					low++;
					high--;
				}
			}
		}
	}
	return res;
}
//n*n sort之后用twopointer