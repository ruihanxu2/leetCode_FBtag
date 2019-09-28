struct Compare{
	bool operator()(const pair<int, int>& a, const pair<int, int>& b){
		return a.first > b.first;
	}
};
vector<int> topKFrequent(vector<int>& nums, int k) {
	unordered_map<int, int> freq;
	vector<int> res;
	for(auto n : nums){
		freq[n]++;    
	}
	priority_queue<pair<int, int>, vector<pair<int, int> >, Compare > pq;
	for(auto p : freq){
		pq.emplace(make_pair(p.second, p.first));
		if(pq.size() > k) pq.pop();
	}
	while(!pq.empty()){
		res.emplace_back(pq.top().second);
		pq.pop();
	}
	reverse(res.begin(), res.end());
	return res;
}