class Solution2 {
public:
	struct Compare{
		bool operator()(const vector<int>& a, const vector<int>& b){
			return a[0] < b[0];
		}
	}compare;
	
	struct Comp{
		bool operator()(const vector<int>& a, const vector<int>& b){
			return a[1] > b[1];
		}
	};
	int minMeetingRooms(vector<vector<int>>& intervals) {
		sort(intervals.begin(), intervals.end(), compare);
		priority_queue<vector<int>, vector<vector<int>>, Comp> pq;
		for(auto interval : intervals){
			if(!pq.empty() && interval[0] >= pq.top()[1]){
				pq.pop();
				pq.emplace(interval);
			}
			else{
				pq.emplace(interval);
			}
		}
		return pq.size();
	}
};

class Solution {
public:
	
	int minMeetingRooms(vector<vector<int>>& intervals) {
		int n = intervals.size();
		vector<int> start(n, 0);
		vector<int> end(n, 0);
		for(int i = 0; i < n; i++){
			start[i] = intervals[i][0];
			end[i] = intervals[i][1];
		}
		sort(start.begin(), start.end());
		sort(end.begin(), end.end());
		
		int res = 0;
		int s = 0, e = 0;
		while(s < n){
			if(start[s] < end[e]){
				res++;
				s++;
			}
			else{
				s++;
				e++;
			}
		}
		return res;
	}
};