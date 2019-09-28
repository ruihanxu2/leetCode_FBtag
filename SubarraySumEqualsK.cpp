class Solution {
public:
	int subarraySum(vector<int>& nums, int k) {
		int res = 0;
		unordered_map<int, int> prefix; // prefix sum, count
		prefix[0] = 1;
		int sum = 0;
		for(int i = 0 ; i < nums.size(); i++){
			
			sum+=nums[i];
			if(prefix.count(sum - k)){
				res+=prefix[sum - k];
			}
			prefix[sum]++;
		}
		return res;
	}
};