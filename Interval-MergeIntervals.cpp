//Merge Interval

static bool compare(vector<int> a, vector<int> b){
		return a[0] < b[0];
	}  
vector<vector<int> > merge(vector<vector<int> >& intervals) {
	
	sort(intervals.begin(), intervals.end(), compare);
	vector<vector<int> > res;
	if(intervals.size() == 0) return res;
	res.emplace_back(intervals[0]);
	for(int i = 1; i < intervals.size(); i++){
		if(intervals[i][0] <= res.back()[1]){
			res.back()[1] = max(intervals[i][1], res.back()[1]);
		}    
		else{
			res.emplace_back(intervals[i]);
		}
	}
	return res;
}