class Solution {
	int lowerBound(int left, int right, int target, vector<int> nums){
		while(left < right){
			int mid = (left + right) / 2;
			if(nums[mid] < target){
				left = mid + 1;
			}
			else{
				right = mid;
			}
		}
		return left;
	}
public:
	bool search(vector<int>& nums, int target) {
		//search pivot
		if(nums.empty()) return false;
		int left = 0;
		int right = nums.size() -1;
		int pivot = -1;
		while(left < right){
			int mid = (left + right) / 2;
			if(nums[mid] < nums[right]){
				right = mid;
			}
			else if(nums[mid] > nums[right]){
				left = mid + 1;
			}
			else{
				if(right > 0 && nums[right - 1] <= nums[right]){
					right--;
				}
				else{
					pivot = right;
					break;
				}
			}
		}
		if(pivot == -1) pivot = left;
		//cout<<right;
		int pos = -1;
		if(target > nums.back()){
			pos = lowerBound(0, pivot, target, nums);
			
		}
		else{
			pos = lowerBound(pivot, nums.size(), target, nums);
		}
		if(pos == nums.size() || nums[pos]!=target) return false;
		return true;
		 
	}
};