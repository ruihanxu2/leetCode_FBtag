//pos: the index to write
// i: left pointer
// j: right pointer
int compress(vector<char>& chars) {
	int i = 0, pos = 0; // pos is the index to write
	for(int j = 0; j < chars.size(); j++){
		if(j == chars.size() - 1 || chars[j] != chars[j + 1]){
			chars[pos++] = chars[j];
			if(j - i > 0){
				string s = to_string(j - i + 1);
				for(auto c : s){
					chars[pos++] = c;
				}
			}
			i = j + 1;
		}
	}
	return pos;
}
