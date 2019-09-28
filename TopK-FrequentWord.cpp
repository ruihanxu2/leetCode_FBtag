class Solution {
	struct Compare{
		bool operator()(const pair<string, int>& a, const pair<string, int>& b){
			if(a.second == b.second) return a.first < b.first;
			return a.second > b.second;
		}
	};
public:
	vector<string> topKFrequent(vector<string>& words, int k) {
		unordered_map<string, int> freq;
		for(auto& word : words){
			freq[word]++;
		}
		vector<string> res;
		priority_queue<pair<string, int>, vector<pair<string, int> >, Compare> pq;
		for(auto p : freq){
			pq.emplace(p);
			if(pq.size() > k){
				pq.pop();
			}
		}
		while(!pq.empty()){
			res.emplace_back(pq.top().first);
			pq.pop();
		}
		reverse(res.begin(), res.end());
		return res;
	}
};