double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		int n1 = nums1.size();
		int n2 = nums2.size();
		if(n1 > n2){
			swap(nums1, nums2);
			swap(n1, n2);
		}// num1 always <= nums2;
		int n = (n1 + n2 + 1)/2;
		int left = 0, right = n1;
		while(left <= right){
			int i = (left + right) / 2;
			int j = n - i;
			if(i > left && nums1[i - 1] > nums2[j]){
				// left has some num larger than right, remove it
				right = i - 1;
			}
			else if(i < right && nums2[j - 1] > nums1[i] ){
				left = i + 1;
			}
			else{
				// found
				int left_max = 0, right_min = 0;
				if(i == 0){
					left_max = nums2[j - 1];
				}
				else if(j == 0){
					left_max = nums1[i - 1];
				}
				else{
					left_max = max(nums1[i-1], nums2[j-1]);
				}
				
				if((n1+n2) % 2 == 1) return left_max;
				
				if(i == n1){
					right_min = nums2[j];
				}
				else if(j == n2){
					right_min = nums1[i];
				}
				else{
					right_min = min(nums1[i], nums2[j]);
				}
				return (left_max + right_min)/2.0;
			}
		}
		return 0;
	}