class Solution__2dDP {
public:
	bool canPartition(vector<int>& nums) {
		int sum = accumulate(nums.begin(), nums.end(), 0);
		if(sum % 2 == 1) return false;
		sum/=2;
		vector<vector<bool> > dp(nums.size() + 1, vector<bool>(sum + 1, false));
		dp[0][0] = true;
		for(int i = 1; i <= nums.size(); i++){
			for(int j = 0; j <= sum; j++){
				if(j - nums[i-1] >= 0){
					dp[i][j] = dp[i-1][j] || dp[i-1][j - nums[i-1]];
				}
				else{
					dp[i][j] = dp[i-1][j];
				}
			}
		}
		return dp.back().back();
	}
};

class Solution {
public:
	bool canPartition(vector<int>& nums) {
		int sum = accumulate(nums.begin(), nums.end(), 0);
		if(sum % 2 == 1) return false;
		sum/=2;
		vector<bool> dp(sum + 1, false);
		dp[0] = true;
		for(int i = 0; i < nums.size(); i++){
			for(int j = sum; j >= nums[i]; j--){
				dp[j] = dp[j] || dp[j - nums[i]];
			}
		}
		return dp.back();
	}
};
class Solution_ {
private:
	bool canReach(vector<int>& nums, int pos, int cur, int target, unordered_set<int>& s) {
		
		
		if(s.count(target)) return true;
		if(cur == target) return true;
		if(cur > target) return false;
		if(pos >= nums.size()) return false;
		
		s.insert(cur);
		return canReach(nums, pos + 1, cur, target,s) || canReach(nums, pos + 1, cur + nums[pos], target, s);
		
	}
	
public:
	bool canPartition(vector<int>& nums) {
		unordered_set<int> s;
		int sum = accumulate(nums.begin(), nums.end(), 0);
		if(sum % 2 == 1) return false;
		sum /= 2;
		return canReach(nums, 0, 0, sum,s);
	}
};

class Solution_Kbuckets {
	
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
	bool canPartition(vector<int>& nums) {
		int k  =2;
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