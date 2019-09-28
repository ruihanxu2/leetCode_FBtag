class Solution {
public:
	int findPeakElement(vector<int>& nums) {
		int l = 0;
		int r = nums.size() - 1;
		while(l < r){
			int mid = (l + r)/2;
			if(nums[mid] < nums[mid+1]){
				l = mid+1; // asending, 
				//must have a peak to the right
			}
			else{
				r = mid; // desending
				//must have a peak to the left
			}
		}
		return l;
	}
};
//