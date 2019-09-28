class Solution {
	vector<int> prefix;
	int total;
public:
	
	Solution(vector<int>& w) {
		prefix.emplace_back(w[0]);
		for(int i = 1; i < w.size(); i++){
			prefix.emplace_back(prefix.back() + w[i]);
		}
		total = prefix.back();
		srand(time(0));
		
		
	}
	
	int pickIndex() {
		int target = rand() % total;
		return upper_bound(prefix.begin(), prefix.end(), target) - prefix.begin();
	}
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */