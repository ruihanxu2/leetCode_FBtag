vector<int> plusOne(vector<int>& digits) {
	int pos = digits.size() - 1;
	int carry = 1;
	for(int pos = digits.size() - 1; pos >= 0; pos-- ){
		int cur = carry + digits[pos];
		if(cur == 10){
			carry = 1;
			digits[pos] = 0;
		}
		else{
			digits[pos] = cur;
			carry = 0;
			break;
		}
	}
	if(carry == 1){
		digits.insert(digits.begin(), 1);
	}
	return digits;
}
