//n2
class Solution2 {
public:
	string reverseWords(string s) {
		istringstream ss(s);
		string res = "";
		string tmp;
		while(ss>>tmp) {
			res = tmp + " " + res;
		}
		return res; 
	}
};

class Solution {
	//O(N) in place
public:
	string reverseWords(string s) {
		reverse(s.begin(), s.end());
		int insertAt = 0;
		for(int i = 0; i < s.size(); i++){
			if(s[i]!=' '){
				if(insertAt != 0) insertAt++;
				int j = i;
				while(j < s.size() && !isspace(s[j])) j++;
				reverse(s.begin() + insertAt, s.begin() + j);
				insertAt+=(j - i);
				i = j;
			}
		}
		s.erase(s.begin() + insertAt, s.end());
		return s;
	}
};