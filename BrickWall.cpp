class Solution {
public:
	int leastBricks(vector<vector<int>>& wall) {
		unordered_map<int, int> m;// dist, freq
		int r = wall.size();
		if(r == 0) return 0;
		
		for(int i = 0; i< r; i++){
			int x = 0;
			for(int j = 0; j < wall[i].size()-1; j++){
				x+=wall[i][j];
				m[x]++;
			}
		}
		int res = INT_MIN;
		if(m.empty()) return r;
		for(auto& p:m){
			//cout<<p.first<<" "<<p.second<<endl;
			
			res = max(res, p.second);
		}
		return r - res;
	}
};