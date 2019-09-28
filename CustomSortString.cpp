
string customSortString(string S, string T) {
	string res;
	vector<int> freq(26, 0);
	for(auto& c : T){
		freq[c-'a']++;
	}
	for(auto& c : S){
		while(freq[c-'a']>0){
			res+=c;
			freq[c-'a']--;
		}
	}
	for(int i = 0; i < 26; i++){
		while(freq[i]>0){
			res+='a' + i;
			freq[i]--;
		}
	}
	return res;
}