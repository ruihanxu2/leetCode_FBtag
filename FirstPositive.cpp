class Solution {
public:
	int firstMissingPositive(vector<int>& nums) {
		bool one = false;
		for(int& n : nums){
			if(n == 1) {
				one = true;
				break;
			}
		}
		if(!one) return 1;
		for(int& n : nums){
			if(n <= 0) {
				n = 1;
			}
		}
		for(int i = 0; i < nums.size(); i++){
			int cur = abs(nums[i]);
			if(cur > nums.size()) continue;
			else{
				nums[cur-1] = nums[cur-1] < 0 ? nums[cur-1] : -nums[cur-1];
			}
		}
		for(int i = 0; i < nums.size(); i++){
			if(nums[i] > 0) return i + 1;
		}
		return nums.size()+1;
	}
 };