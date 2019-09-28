//On On
void rotate(vector<int>& nums, int k) {
	vector<int> tmp(nums.size());
	
	for(int i = 0; i < nums.size(); i++){
		tmp[(i + k) % nums.size()] = nums[i];
	}
	swap(tmp, nums);
	
}



// On O1
//reverse 大法
// 考虑到有k个会被移动到前面
//void reverse_(vector<int>& nums, int s, int e){
//		while(s < e - 1){
//			swap(nums[s++], nums[e-- - 1]);
//		}
//	}
void rotate(vector<int>& nums, int k) {
	k = k % nums.size();
//		reverse_(nums, 0, nums.size());
//		reverse_(nums, 0, k);
//		reverse_(nums, k, nums.size());
	
	 reverse(nums.begin(), nums.end());
	 reverse(nums.begin(), nums.begin()+k);
	 reverse(nums.begin()+k, nums.end());
	
}

// On O1
// 转着圈换
// 注意如果n整除k，每次循环会回到原点，此时必须手动加1
void rotate(vector<int>& nums, int k) {
	int n = nums.size();
	if(n == 0) return;
	k = k % n;
	int count = 0;
	
	for(int start = 0; count < n; start++){
		int pos = start;
		int cur = nums[start];
		do{
			int tmp = nums[(pos + k) % n];
			nums[(pos + k) % n] = cur;
			cur = tmp;
			count++;
			pos = (pos + k) % n;
		}while(pos!=start);
	}
}