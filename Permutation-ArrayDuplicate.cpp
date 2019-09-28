class Solution {
	vector<vector<int> > res;
public:
	void helper(int pos, vector<int>& cur, vector<int>& nums, vector<bool>& used){
		if(pos == nums.size()){
			res.emplace_back(cur);
			return;
		}
		for(int i = 0; i < nums.size(); i++){
			if(used[i]) continue;
			if(i > 0 && nums[i - 1] == nums[i] && !used[i - 1]) continue;
			used[i] = true;
			cur.emplace_back(nums[i]);
			helper(pos + 1, cur, nums, used);
			cur.pop_back();
			used[i] = false;
		}
	}
	vector<vector<int>> permuteUnique(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		vector<bool> used(nums.size(), false);
		vector<int> cur;
		helper(0, cur, nums, used);
		return res;
	}
};


//这里有两点比较难懂
//swap仅仅是为了当前那一位得到不一样的数而已，不要想太多
// pass by ref， 不swapback 都是为了这个服务的
// sort就是为了防止那一位经过转换重复
// 121 => 211 => 112 第一位是1的情况会发生两次
// sort了就一定会跳过这种情况

class Solution {
	vector<vector<int> > res;
public:
	void helper(int pos, vector<int> nums){ // why not ref: 后面的swap 会改变原有顺序，导致当前位可能会换回之前的数
		if(pos == nums.size()){
			res.emplace_back(nums);
			return;
		}
		for(int i = pos; i < nums.size(); i++){
			if(i > pos && nums[pos]==nums[i]) continue;
			swap(nums[pos], nums[i]);
			helper(pos+1, nums);
			// why not swap back: 1 1 3 3 => 3 . . . swap back...1 1 3 3 => 3 . . .  
			//  									|   |                          |     |
		}
	}
	vector<vector<int>> permuteUnique(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		helper(0, nums);
		return res;
	}
};



