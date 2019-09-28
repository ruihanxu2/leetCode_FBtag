

//Sliding Window On
class Solution {
public:
	//Sliding Window
	int minSubArrayLen(int target, vector<int>& nums) {
		if(nums.size() == 0) return 0;
		int l = 0;
		int res = INT_MAX;
		int curSum = 0;
		
		for(int r = 0; r < nums.size(); r++){
			curSum += nums[r];
			while(curSum >= target){
				res = min(r - l + 1, res);
				curSum-=nums[l++];             
			}
		}
		return res == INT_MAX ? 0 : res;
	}
};

//NlogN
int minSubArrayLen(int target, vector<int>& nums) {
	int n = nums.size();
	if(n == 0) return 0;
	vector<int> prefix(n + 1, 0);
	prefix[0] = 0;
	int res = INT_MAX;
	for(int i = 1; i <= n; i++){
		prefix[i] = prefix[i-1] + nums[i-1];    
	}
	for(int i =1; i <= n; i++){
		int t = prefix[i-1] + target;
		auto pos = lower_bound(prefix.begin(), prefix.end(), t);
		if(pos != prefix.end()){
			res = min(res, (int)(pos - (prefix.begin() + i - 1)));
		}
		
	}
	return res == INT_MAX ? 0 : res;
}