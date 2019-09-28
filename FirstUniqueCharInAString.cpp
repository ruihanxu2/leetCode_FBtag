int firstUniqChar(string s) {
	unordered_map<char, pair<int, int> > freq; // char, {freq, idx}
	for(int i = 0; i < s.size(); i++){
		freq[s[i]].first++;
		freq[s[i]].second = i;
	}
	int res = INT_MAX;
	for(auto p : freq){
		if(p.second.first == 1){
			res = min(res, p.second.second);
		}
	}
	return res == INT_MAX ? -1 : res;
	
}