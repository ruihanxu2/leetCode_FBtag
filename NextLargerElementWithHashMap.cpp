vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
	unordered_map<int, int> lookup; // num : nextGreaterNum
	stack<int> s;
	vector<int> res;
	for(auto n : nums2){
		while(!s.empty() && n > s.top()){
			lookup[s.top()] = n;
			s.pop();
		}
		s.emplace(n);
	}
	while(!s.empty()){
		lookup[s.top()] = -1;
		s.pop();
	}
	for(auto n : nums1){
		res.emplace_back(lookup[n]);
	}
	return res;
}
