// 1|234 and 432 can be made of to 432 1 234 . so we want to search the 
// reverse of the right side
// 1. left side must be palindrome, then try and find the reverse of right
// 2. apply the same again. right palindrome
// corner cases: abba , find ""

// duplicates? will not appear if length are different
// is same len, since we only check full string once, will not deplicate(second loop stop condition)

class Solution {
	bool isPalindrome(string s){
		int l = 0;
		int r = s.size()-1;
		while(l < r){
			if(s[l++] != s[r--]){
				return false;
			}
		}
		return true;
	}
public:
	
	vector<vector<int>> palindromePairs(vector<string>& words) {

		
		vector<vector<int>> res;
		unordered_map<string, int> m; // reversed string, pos
		for(int i = 0; i < words.size(); i++){
			string word = words[i];
			reverse(word.begin(), word.end());
			m[word] = i;
		}
		for(int i = 0; i < words.size(); i++){
			
			for(int j = 0; j < words[i].size(); j++){
				string left = words[i].substr(0, j);
				string right = words[i].substr(j);

				if(j == 0  &&isPalindrome(right) && m.count("")){
					res.emplace_back(vector<int>{m[""], i});
					res.emplace_back(vector<int>{i, m[""]});
					continue;
				}
				if(isPalindrome(left) && m.count(right) && m[right] != i){
					
					res.emplace_back(vector<int>{m[right], i});
				}
				if(isPalindrome(right) && m.count(left) && m[left] != i){
					res.emplace_back(vector<int>{i, m[left]});
				}
			}
		}
		return res;
	}
};