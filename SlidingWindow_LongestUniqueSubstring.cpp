int lengthOfLongestSubstring(string s) {
	int l = 0;
	int r = 0;
	int res = 0;
	unordered_map<char, int> m;
	while(r < s.size()){
		if(m.count(s[r])){
			l = max(m[s[r]]+1, l);
		}
		res = max(res, r - l + 1);
		m[s[r]] = r;
		r++;
	}
	return res;
}
//用set 2n


//用map记录当前已知道char的最右边位置
//如果发现出现了， 看看是否在l的右边， 位置 > l?
//如果是，l = 位置+1
//不是，l不变