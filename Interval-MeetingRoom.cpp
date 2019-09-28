class Solution {
public:
	struct compare{
		bool operator()(const vector<int>& a, const vector<int>& b){
			if(a[0] == b[0]) return a[1] < b[1];
			return a[0] < b[0];
		}
	};
	bool canAttendMeetings(vector<vector<int>>& intervals) {
		sort(intervals.begin(), intervals.end(), compare());
		for(int i = 1; i < intervals.size(); i++){
			if(intervals[i][0] < intervals[i-1][1]) return false;    
		}
		return true;
	}
};