vector<vector<string>> groupAnagrams(vector<string>& strs) {
	unordered_map<string, vector<string> > m;
	vector<vector<string> > res;
	for(auto s:strs){
		vector<int> count(26, 0);
		string str;
		for(auto c:s){
			count[c - 'a']++;
		}
		for(auto n : count){
			str+=to_string(n);
			str+='#';
		}
		m[str].emplace_back(s);
	}
	
	for(auto p : m){
		res.emplace_back(p.second);
	}
	return res;
}
// NK
// or just sort every string
// NKlogK