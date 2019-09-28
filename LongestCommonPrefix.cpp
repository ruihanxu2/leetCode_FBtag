string longestCommonPrefix(vector<string>& strs) {
	if(strs.size() == 0 || strs[0].size() == 0) return "";
	string res;
	for(int i = 0; i < strs[0].size(); i++){
		char tmp = strs[0][i];
		for(int j = 1; j < strs.size(); j++){
			if(i == strs[j].size() || strs[j][i] != tmp){
				return res;
			}
		}
		res+=tmp;
	}
	return res;
}