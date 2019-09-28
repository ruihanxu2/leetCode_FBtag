class Solution {
public:
	
	string rearrangeString(string s, int k) {
		vector<int> freq(26, 0), pos(26, -k);
		for(auto& c : s){
			freq[c-'a']++;
		}
		for(int i = 0; i < s.size(); i++){
			int maxCount = 0;
			char candid;
			for(int j = 0; j < 26; j++){
				if(freq[j] > maxCount && i - pos[j] >= k){
					candid = 'a' + j;
					maxCount = freq[j];
				}
			}
			if(maxCount == 0) return "";
			freq[candid - 'a']--;
			pos[candid - 'a'] = i;
			s[i] = candid;
		}
		return s;
		
	}
};
//---------------------------

class Solution2 {
	struct Compare{
		bool operator()(const pair<int ,char>& a, const pair<int ,char>& b){
			if(a.first == b.first) return a.second > b.second;
			return a.first < b.first;
		}
	};
public:
	
	string rearrangeString(string s, int k) {
		if(k == 0) return s;
		unordered_map<char, int> m;
		for(auto& c : s){
			m[c]++;
		}
		priority_queue<pair<int, char>, vector<pair<int, char> >, Compare> pq;
		for(auto p : m){
			pq.emplace(make_pair(p.second, p.first));
		}
		for(int i = 0; i < s.size(); ){
			vector<pair<int, char> > tmp;
			for(int j = 0; j < k&&i < s.size(); j++, i++){
				if(pq.empty()) return "";
				auto cur = pq.top();
				pq.pop();
				s[i] = cur.second;
				cur.first--;
				if(cur.first!=0) tmp.emplace_back(cur);
			}
			for(auto p : tmp){
				pq.emplace(p);
			}
		}
		return s;
	}
};