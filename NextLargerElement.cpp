// LC739
class Solution2 {
public:
	vector<int> dailyTemperatures(vector<int>& T) {
		vector<int> res(T.size(), 0);
		vector<int> next(101, INT_MAX);
		for(int i = T.size() - 1; i >=0; i--){
			int idx = INT_MAX;
			for(int j = T[i] + 1; j <= 100; j++){
				idx = min(next[j], idx);
			}
			if(idx<INT_MAX){
				res[i] = idx - i;
			}
			next[T[i]] = i;
		}
		return res;
	}
};

class Solution {
public:
	vector<int> dailyTemperatures(vector<int>& T) {
		stack<int> s;
		vector<int> res(T.size(), 0);
		for(int i = 0; i < T.size(); i++){
			
			while(!s.empty() && T[s.top()] < T[i]){
				res[s.top()] = i - s.top();
				s.pop();
			}
			s.emplace(i);
		}
		return res;
	}
};