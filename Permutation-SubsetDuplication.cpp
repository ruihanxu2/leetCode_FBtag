class Solution {
	vector<vector<int> > res;
public:
	void helper(int pos, vector<int>& cur, vector<int>& nums){
		res.emplace_back(cur);
		for(int i = pos; i < nums.size(); i++){
			if(i > pos && nums[i] == nums[i - 1]) continue;
			cur.emplace_back(nums[i]);
			helper(i + 1, cur, nums);
			cur.pop_back();
		}
		
		
	}
	vector<vector<int>> subsetsWithDup(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		vector<int> cur;
		helper(0, cur, nums);
		return res;
	}
};