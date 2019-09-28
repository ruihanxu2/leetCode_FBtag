class Solution {
	
	bool helper(int pos, vector<int>& nums, int target ,vector<int>& buckets){
		if(pos < 0){
			return true;
		}
		int next = nums[pos];
		for(int i = 0; i < buckets.size(); i++){
			if(buckets[i] + next <= target){
				buckets[i] += next;
				if(helper(pos - 1, nums, target, buckets)) return true;
				buckets[i] -= next;
			}
		}
		
		return false;
	}
public:
	bool canPartitionKSubsets(vector<int>& nums, int k) {
		int sum = accumulate(nums.begin(), nums.end(), 0);
		if(sum % k != 0) return false;
		int target = sum / k;
		sort(nums.begin(), nums.end());
		int pos = nums.size() - 1;
		while(k!= 0 && nums[pos] == target){
			pos--;
			k--;
		}
		if(k == 0) return true;
		vector<int> buckets(k, 0);
		return helper(pos, nums, target, buckets);
	}
};