class Solution {
public:
	int maxPoints(vector<vector<int>>& points) {
		int n = points.size();
		int res = 0;
		if(points.size() == 0) return 0;
		for(int i = 0; i < n; i++){
			unordered_map<long double, int> m; // slope, count
			int vertical = 0;
			int overlap = 0;
			int tmpMax = 0;
			for(int j = 0; j < n; j++){
				if(j == i) continue; 
				if(points[j][0] == points[i][0] && points[j][1] == points[i][1]){
					overlap++;
				}
				else if(points[j][0] == points[i][0]){
					vertical++;
					tmpMax = max(tmpMax, vertical);
				}
				else{
					long double slope = (long double)(points[i][1] - points[j][1]) / (points[i][0] - points[j][0]);
					m[slope]++;
					tmpMax = max(tmpMax, m[slope]);
				}
			}
			res = max(tmpMax + overlap + 1, res);
		}
		return res;
	}
};