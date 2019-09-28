// ----------------one edit distance---------------
// check if two strings have 1 edit distance

class Solution {
public:
	bool diffLength(string& s, string& t){
		//s is shorter
		bool flag = false;
		for(int i = 0, j = 0; i < s.size(), j < t.size(); i++, j++){
			if(s[i] != t[j]){
				if(flag) return false;
				i--;
				flag = true; // already did one flip
			}
		}
		return true;
	}
	bool sameLength(string& s, string& t){
		int count = 0;
		for(int i = 0; i < s.size(); i++){
			if(s[i] != t[i]) count++;
			if(count == 2) return false;
		}
		return count == 1;
	}
	bool isOneEditDistance(string s, string t) {
		int ns = s.size();
		int nt = t.size();
		if(abs(ns - nt) > 1) return false;
		if(ns == nt){
			return sameLength(s, t);
		}
		else{
			if(ns > nt){
				swap(s, t);
				// s is alwas shorter
			}
			return diffLength(s, t);
		}
		
	}
};

