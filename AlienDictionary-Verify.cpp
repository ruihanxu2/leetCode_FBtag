class Solution {
public:
	bool isAlienSorted(vector<string>& words, string order) {
		vector<int> orders(26, 0);
		for(int i = 0; i < 26; i++){
			orders[order[i] - 'a'] = i;    
		}
		for(int i = 0; i < words.size() - 1; i++){
			string s1 = words[i];
			string s2 = words[i + 1];
			bool flag = false;
			for(int k = 0, j = 0; k < s1.size() && j < s2.size(); k++, j++){
				if(s1[k] == s2[j]) continue;
				else if(orders[s1[k] - 'a'] > orders[s2[j] - 'a']) return false;
				else{
					flag = true;
					break;
				}
			}
			if(!flag){
				if(s1.size() > s2.size()) return false;
			}
		}
		return true;
	}
};