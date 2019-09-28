// word:
// w1rd, w2d...
//two pointers
bool validWordAbbreviation(string word, string abbr) {
	int i = 0; int j = 0;
	int n1 = word.size();
	int n2 = abbr.size();
	while(i < n1 && j < n2){
		
		if(isdigit(abbr[j])){
			if(abbr[j] == '0') return false;
			int val = 0;
			while(isdigit(abbr[j])){
				val*=10;
				val+=abbr[j++] - '0';
			}
			i+= val;
		}
		else{
			if(word[i++] != abbr[j++]) return false;
		}
	}
	return i == n1 && j == n2;
}
