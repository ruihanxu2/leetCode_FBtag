// count all 1s and then mutilply
int totalHammingDistance(vector<int>& nums) {
	vector<int> bits(32, 0);
	for(int n : nums){
		int pos = 0;
		while(n > 0){
			if(n & 1) bits[pos]++;
			n = n>>1;
			pos++;
		}
	}
	int n = nums.size();
	int res = 0;
	for(int i = 0; i < 32; i++){
		res+= bits[i] * (n - bits[i]);
	}
	return res;
}
