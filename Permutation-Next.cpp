class Solution {
public:
	void nextPermutation(vector<int>& nums) {
		int i = (int)nums.size() - 1;
		for(; i > 0; i--){
			if(nums[i-1] < nums[i]) break;
		}
		//     |     |
		// 1 2 3 8 7 4 2 1
		// 1 2 4 8 7 3 2 1 reverse last part
		// 1 2 4 1 2 3 7 8
		if(i!=0){
			for(int j = (int)nums.size() - 1; j >= i; j--){
				if(nums[j] > nums[i - 1]){
					swap(nums[i - 1], nums[j]);
					break;
				}
			}
		}
		reverse(nums.begin() + i, nums.end());
	}
};