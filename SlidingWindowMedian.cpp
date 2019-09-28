class Solution {
public:
	
	vector<double> medianSlidingWindow(vector<int>& nums, int k) {
		vector<double> res;
		multiset<int> left, right;
		for(int i = 0; i < nums.size(); i++){
			// remove
			if(i >= k){
				if(nums[i - k] <= *left.rbegin()){
					left.erase(left.find(nums[i - k]));
				}
				else{
					right.erase(right.find(nums[i - k]));
				}
			}
			left.insert(nums[i]);
			right.insert(*left.rbegin());
			left.erase(prev(left.end()));
			
			if(left.size() < right.size()){
				left.insert(*right.begin());
				right.erase(right.begin());
			}
			
			if(i >= k - 1){
				res.emplace_back(k & 1 ? *left.rbegin() : ((double)*left.rbegin() + (double)*right.begin()) * 0.5);
			}
		}
		return res;
	}
};

