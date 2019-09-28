//---------------------------------- all pairs except 1---------------------------

int singleNumber(vector<int>& nums) {
	int b  =0;
	for(auto n : nums){
		b^=n;
	}
	return b;
}

//or 使用hashmap/set
int singleNumber(vector<int>& nums) {
	unordered_set<int> s;
	for(auto n : nums){
		if(s.count(n)) s.erase(n);
		else s.insert(n);
	}
	return *s.begin();
}

//---------------------------------- all triplets except 1 single -----------------

XOR 很重要的作用就是save and clear
如果是pair， XOR 两次 就ok了
但是现在是triplet，我们要区分是出现了一次还是出现了三次
状态是  0  1  0  0   (firstMask)
       0  0  1  0   (secondMask)
出现了  0  1  2  3 次

First Apparence : save num to firstMask, 
Second Apparence : clear firstmask, save num to secondMask. 
Third Apparence: , clear second mask;

=> when second is 0, save/clear to first
=> when first is 0, save/clear to second
int singleNumber(vector<int>& nums) {
	int first = 0, second = 0;
	for(int n : nums){
		first = (first ^ n) & ~second;
		second = (second ^ n) & ~first;
	}
	return first;
}


//---------------------------------- all pairs except 2 singles -------------------

vector<int> singleNumber(vector<int>& nums) {
	int mix = 0;
	for(auto& n : nums){
		mix ^= n;
	} // mix is a ^ b. mix must not be 0 otherwise a == b;
	// find the bit where a != b. Split the array according to that bit
	// do ^= again of both side
	
	// get the 00000100
	int mask = mix & ~(mix - 1);
	vector<int> res(2, 0);
	for(auto& n : nums){
		if(n & mask){
			res[0]^=n;
		}
		else{
			res[1]^=n;
		}
	}
	return res;
}

