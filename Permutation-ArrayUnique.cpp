// ordinary method
// O(n!), O(n)
class Solution {
	vector<vector<int> > res;
public:
	void helper(vector<int>& nums, vector<bool>& used, int pos, vector<int>& cur ){
		if(pos == nums.size()){
			res.emplace_back(cur);
			return;
		}
		
		for(int i = 0; i < used.size(); i++){
			if(!used[i]){
				used[i] = true;
				cur.emplace_back(nums[i]);
				helper(nums, used, pos + 1, cur);
				cur.pop_back();
				used[i] = false;
			}
		}
	}

	vector<vector<int>> permute(vector<int>& nums) {
		vector<bool> used(nums.size(), false);
		vector<int> cur;
		helper(nums, used, 0, cur);
		return res;
	}
};

class Solution{
	vector<vector<int> > res;
public:
	void helper(vector<int>& nums, int pos) {
		if(pos == nums.size()){
			res.emplace_back(nums);
		}
		for(int i = pos; i < nums.size(); i++){
			swap(nums[pos], nums[i]);
			helper(nums, pos + 1);
			swap(nums[pos], nums[i]);
		}
	}

	vector<vector<int> > permute(vector<int>& nums) {
		helper(nums, 0);
		return res;
	}
};



