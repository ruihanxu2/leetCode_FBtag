vector<int> findAnagrams(string s, string p) {
	vector<int> pattern(26, 0);
	vector<int> cur(26, 0);
	vector<int> res;
	
	int n = p.size();
	int n2 = s.size();
	if(n2 < n) return res;
	int left = 0;
	int right = left + n -1;
	for(int i = left; i <=right; i++){
		cur[s[i] - 'a']++;
		pattern[p[i] - 'a']++;
	}
	while(right < s.size()){
		if(cur == pattern) res.emplace_back(left);
		if(right == s.size() - 1) break;
		cur[s[left++] - 'a']--;
		cur[s[++right] - 'a']++;

	}
	return res;
}

/*Given a string s and a non-empty string p, find all the start indices of p's anagrams in s.

Strings consists of lowercase English letters only and the length of both strings s and p will not be larger than 20,100.

The order of output does not matter.*/