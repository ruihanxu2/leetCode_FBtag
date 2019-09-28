class Solution {
public:
	vector<vector<string>> groupStrings(vector<string>& strings) {
		unordered_map<string, vector<string> > m;
		for(auto s : strings){
			m[shift(s)].emplace_back(s);
		}
		vector<vector<string> > res;
		for(auto p : m){
			res.emplace_back(p.second);
		}
		return res;
	}
	string shift(string s){
		string tmp;
		for(int i = 1; i < s.size(); i++){
			int diff = s[i] - s[i-1];
			if(diff < 0) diff+=26;
			tmp+=('a' + diff);
		}
		return tmp;
	}
};

//
//Given a string, we can "shift" each of its letter to its successive letter, for example: "abc" -> "bcd". We can keep "shifting" which forms the sequence:
//
//"abc" -> "bcd" -> ... -> "xyz"
//Given a list of strings which contains only lowercase alphabets, group all strings that belong to the same shifting sequence.
//
//Example:
//
//Input: ["abc", "bcd", "acef", "xyz", "az", "ba", "a", "z"],
//Output: 
//[
//	["abc","bcd","xyz"],
//	["az","ba"],
//	["acef"],
//	["a","z"]
//]