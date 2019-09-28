class Solution {
public:
	int trap(vector<int>& height) {
		stack<int> s;
		int cur = 0;
		int dist = 0;
		int res = 0;
		int n = height.size();
		if(n <= 2) return 0;
		while(cur < n){
			while(!s.empty() && height[cur] > height[s.top()]){
				int bound = s.top();
				s.pop();
				if(s.empty()) break;
				dist = cur - s.top() - 1;
				int bound_height = min(height[cur], height[s.top()]) - height[bound];
				res+=dist*bound_height;
			}
			s.emplace(cur++);
		}
		return res;
	}
};