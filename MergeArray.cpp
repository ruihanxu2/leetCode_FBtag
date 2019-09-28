//反着来，从大到小
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
	int p = m+n-1; //
	int p1 = m-1; //1
	int p2 = n-1; //2
	while(k>=0){
		nums1[p--] = p1>=0 && nums1[p1]>nums2[p2]?nums1[p1--]:nums2[p2--];
	}
}

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
		int p = nums1.size()-1;
		int p1 = m - 1;
		int p2 = n - 1;
		for(; p >= 0; p--){
			if(p1 < 0) nums1[p] = nums2[p2--];
			else if(p2 < 0) nums1[p] = nums1[p1--];
			else{
				int a = nums1[p1];
				int b = nums2[p2];
				if(a < b){
					nums1[p] = nums2[p2--];
				}
				else{
					nums1[p] = nums1[p1--];
				}
			}
		}
		
	}