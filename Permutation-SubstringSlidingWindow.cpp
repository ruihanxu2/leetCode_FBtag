// method 1 find all permuation of the first string. then find it in s2
//		n1! * n2

// method 2 sort s1, in side s2 find first then sort and compare one by one;
// n1logn1 + n2 * n1logn1

//method 3 hashmap， get freq of n1 and iterate n2
// n1 + n2 * n1

//method 4 sliding window
// n1 + n2 * 26

class Solution {
public:
	bool checkInclusion(string s1, string s2) {
		vector<int> freq1(26, 0);
		vector<int> freq2(26, 0);
		int n1 = s1.size();
		int n2 = s2.size();
		if (n2 < n1) return false;
		for(int i = 0; i < n1; i++){
			freq1[s1[i] - 'a']++;
			freq2[s2[i] - 'a']++;
		}
		
		for(int l = 0, r = l + n1; r <= n2; l++, r++){
			if(freq1 == freq2) return true;
			if(r>=n2) return false;
			freq2[s2[r] - 'a'] ++;
			freq2[s2[l] - 'a'] --;
			
		}
		return false;
		
	}
};


class Solution {
public:
	bool checkInclusion(string s1, string s2) {
		vector<int> freq1(26, 0);
		vector<int> freq2(26, 0);
		int n1 = s1.size();
		int n2 = s2.size();
		if (n2 < n1) return false;
		for(int i = 0; i < n1; i++){
			freq1[s1[i] - 'a']++;
			freq2[s2[i] - 'a']++;
		}
		int count = 0;
		for(int i = 0; i < 26; i++){
			if(freq1[i] == freq2[i]) {
				count++;
			}
		}
		for(int l = 0, r = l + n1; r <= n2; l++, r++){
			cout<<count;
			if(count == 26) return true;
			if(r>=n2) return false;
			freq2[s2[r] - 'a'] ++;
			if(freq2[s2[r] - 'a'] == freq1[s2[r] - 'a']) count++;
			else if(freq2[s2[r] - 'a'] == freq1[s2[r] - 'a']+1) count--;
			
			freq2[s2[l] - 'a'] --;
			if(freq2[s2[l] - 'a'] == freq1[s2[l] - 'a']) count++;
			else if(freq2[s2[l] - 'a'] == freq1[s2[l] - 'a']-1) count--;
		}
		return false;
		
	}
};



