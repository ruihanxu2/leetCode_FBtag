class Solution {
public:
	vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
		vector<string> res;
		long l = lower, r;
		for(int i = 0; i < nums.size(); i++){
			r = (long)nums[i] - 1;
			if(l == r) res.emplace_back(to_string(l));
			else if(l < r) res.emplace_back(to_string(l) + "->" + to_string(r));
			l = (long)nums[i] + 1;
		}
		if(l == upper) res.emplace_back(to_string(l));
		else if(l < upper) res.emplace_back(to_string(l) + "->" + to_string(upper));
		return res;
	}
};
