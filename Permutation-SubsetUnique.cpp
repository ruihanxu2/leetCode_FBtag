class Solution {
	vector<vector<int> > res;
	void helper(int pos, vector<int>& cur, vector<int>& nums){
		res.emplace_back(cur);
		for(int i = pos; i < nums.size(); i++){
			cur.emplace_back(nums[i]);
			helper(i + 1, cur, nums);
			cur.pop_back();
		}
		
	}
public:
	
	vector<vector<int> > subsets(vector<int>& nums) {
		vector<int> cur;
		helper(0, cur, nums);
		return res;
	}
};


class Solution {
public:
	vector<vector<int>> subsets(vector<int>& nums) {
		int n=nums.size();
		
		vector<vector<int>> res;
		for(int i=1; i<=n; i++){
			vector<int> cur;
			helper(0, i, 0, res, nums, cur);
		}
		
		res.emplace_back(vector<int>{});
		return res;
		
	}
	void helper(int level, int num, int index, vector<vector<int>>& res, vector<int>& nums, vector<int>& cur){
		if(level==num){
			res.emplace_back(cur);
			return;
		}
		for(int i=index; i<nums.size(); i++){
			cur.emplace_back(nums[i]);
			helper(level+1, num, i+1, res, nums, cur);
			cur.pop_back();
		}
	}
};