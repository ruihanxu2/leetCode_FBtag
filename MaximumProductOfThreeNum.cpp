class Solution2 {
public:
	int maximumProduct(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		int nnp = nums[0] * nums[1] * nums.back();
		int nnn = nums[nums.size() - 1] *nums[nums.size() - 2] *nums[nums.size() - 3];
		return max(nnp, nnn);
	}
};
class Solution {
public:
	int maximumProduct(vector<int>& nums) {
		
		int max1 = INT_MIN, max2 = INT_MIN, max3 = INT_MIN;
		int min1 = INT_MAX, min2= INT_MAX;
		for(auto& n : nums){
			if(n >= max1){
				max3 = max2;
				max2 = max1;
				max1 = n;
			}
			else if(n >= max2){
				max3 = max2;
				max2 = n;
			}
			else if(n > max3){
				max3 = n;
			}
			
			if(n <= min1){
				min2 = min1;
				min1 = n;
			}
			else if(n < min2){
				min2 = n;
			}
		}
		return max(max1 * max2 * max3, min1 * min2 * max1);
	}
};