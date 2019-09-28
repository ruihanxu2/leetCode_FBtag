// first Zero is the pointer to the first zero of the array
// 把 0 移动到最后
void moveZeroes(vector<int>& nums) {
	int firstZero = 0;
	for(int i = 0; i < nums.size(); i++){
		if(nums[i] != 0){
			swap(nums[i], nums[firstZero++]);
		}
	}
}


// sortColor 1 pass
// two pointers pointing to the next possible place for 0 / 2

void sortColors(vector<int>& nums){
	if(nums.size() == 1) return;
	int nextZero = 0;
	int nextTwo = nums.size() - 1;
	int p = 0;
	while(p <= nextTwo){
		if(nums[p] == 0){
			//must p++!
			//换的只有可能是0 or 1
			swap(nums[p++], nums[nextZero++]);
		}    
		else if(nums[p] == 2){
			swap(nums[p], nums[nextTwo--]);
		}
		else{
			p++;
		}
	}
}


// Sort color: two pass
// 两次movezero or count num of 1, 2
void sortColors(vector<int>& nums) {
	int firstTwo  = 0;
	for(int i = 0; i < nums.size(); i++){
		if(nums[i] != 2){
			swap(nums[i], nums[firstTwo++]);
		}
	}
	
	int lastZero = nums.size() - 1;
	for(int i = nums.size() - 1; i >= 0 ; i--){
		if(nums[i] != 0){
			swap(nums[i], nums[lastZero--]);
		}
	}
	
}

