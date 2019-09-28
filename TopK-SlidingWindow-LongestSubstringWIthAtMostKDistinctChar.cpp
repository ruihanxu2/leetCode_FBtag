class Solution_ {
public:
	int lengthOfLongestSubstringKDistinct(string s, int k) {
		int l = 0; 
		int r = 0;
		int res = 0;
		unordered_map<int, int> freq;
		while(r < s.size()){
			freq[s[r]]++;
			r++;
			while(freq.size() > k){
				freq[s[l]]--;
				if(freq[s[l]] == 0){
					freq.erase(s[l]);
				}
				l++;
			}
			res = max(res, r - l);
		}
		return res;
	}
};

class Solution {
public:
	int lengthOfLongestSubstringKDistinct(string s, int k) {
		int l = 0; 
		int r = 0;
		int res = 0;
		int count = 0;
		unordered_map<int, int> freq;
		while(r < s.size()){
			if(freq[s[r++]]++ == 0){
				count++;
			}
			while(count> k){
				
				if(--freq[s[l]] == 0){
					count--;
				}
				l++;
			}
			res = max(res, r - l);
		}
		return res;
	}
};