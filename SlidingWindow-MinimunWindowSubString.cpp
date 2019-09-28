class Solution {
public:
	string minWindow(string s, string t) {
		if(t.size() > s.size()){
			return "";
		}
		int minLen = INT_MAX;
		int resPos = -1;
		unordered_map<char, int> freq; // char, freq
		for(auto c : t){
			freq[c]++;
		}
		int matched = 0;
		int left = 0; // two pointers
		int right = 0;
		for(; right < s.size(); right++){
			if(!freq.count(s[right])){
				continue;
			}
			freq[s[right]]--;
			if(freq[s[right]] == 0){
				matched++;
			}
			
			// try to move left
			while(matched == freq.size()){
				if(right - left + 1 < minLen){
					minLen = right - left + 1;
					resPos = left;
				}
				char toRemove = s[left++];
				
				if(freq.count(toRemove)){
					freq[toRemove]++;
					if(freq[toRemove] == 1){
						matched--;
					}
				}
				
			}
		}
		return resPos == -1 ? "" : s.substr(resPos, minLen);
	}
};