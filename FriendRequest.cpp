
int numFriendRequests(vector<int>& ages) {
	unordered_map<int, int> freq;
	for(auto age: ages){
		freq[age]++;
	}
	int res = 0;
	for(auto p : freq){
		int age = p.first;
		int frequency = p.second;
		
		for(int i = 0; i <= 120; i++){
			
			if(age * 0.5 + 7 >= i) continue;
			if(age < i) break;
			//if(i > 100 && age < 100) continue; 
			if(freq.count(i)){
				res+=frequency * freq[i];
				if(age == i) res -= frequency;
			}
			
		 }
	}
	return res;
}
