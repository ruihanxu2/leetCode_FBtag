// O(n)
string reorganizeString(string s) {
	unordered_map<char, int> freq;
	int maxFreq = 0;
	char maxFreqChar;
	for(auto c : s){
		freq[c]++;
		if(freq[c] > maxFreq){
			maxFreq = freq[c];
			maxFreqChar = c;
		}
	}
	int n = s.size();
	if(maxFreq > (n + 1)/2) return "";
	int i = 0;
	for(int count = 0; count < maxFreq; count++){
		s[i] = maxFreqChar;
		i+=2;
	}
	freq[maxFreqChar] = 0;
	for(auto p : freq){
		while(p.second > 0){
			if(i >= n) i = 1;
			s[i] = p.first;
			i+=2;
			p.second--;
		}
	}
	return s;
}
//use pq, 每次pop freq最大的两个放进s O（Nlog26）
