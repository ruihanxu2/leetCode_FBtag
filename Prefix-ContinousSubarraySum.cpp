class Solution {
public:
	bool checkSubarraySum(vector<int>& nums, int k) {
		// get a remainder prefix tree. if reminder is the same , found
		unordered_map<int, int> prefix; // prefixsum reminder, pos
		prefix[0] = -1;
		int sum = 0;
		for(int i = 0; i < nums.size(); i++){
			sum += nums[i];
			if(k != 0) sum %= k;
			if(prefix.count(sum)){
				if(i - prefix[sum] > 1) return true;
			}
			else{
				prefix[sum] = i;
			}
		}
		return false;
	}
};