// brutal force, On3, get ever permutation

//O(n) if mono dec, get the largest num after the pivot that is as far as possible
//get the first num that is smaller than the largest num
int maximumSwap(int Num) {
	string num = to_string(Num);
	bool monoDec = true;
	int maxNumPos = 0;
	char maxNum = '0';
	for(int i = 0; i < num.size() - 1; i++){
		if(num[i + 1] > num[i]){
			monoDec = false;
		}
		if(!monoDec && num[i+1] >= maxNum){
			maxNum = num[i+1];
			maxNumPos = i+1;
		}
	}
	if(monoDec) return Num;
	for(int i = 0; i < num.size(); i++){
		if(num[i] < maxNum){
			swap(num[i], num[maxNumPos]);    
			break;
		}
	}
	return stoi(num);
	
}
