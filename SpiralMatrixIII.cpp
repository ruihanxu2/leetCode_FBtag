class Solution {
public:
	vector<vector<int>> spiralMatrixIII(int R, int C, int r0, int c0) {
		//112233
		//234567
		int stepSize = 2;
		vector<vector<int> > res;
		vector<vector<int> > dir{ {0,1}, {1,0}, {0,-1}, {-1,0} };
		for(int i = 0; i < R*C; i++){
			for(int j = 0; j < 4; j++){
				
				int curSize = stepSize / 2;
				for(int k = 0; k < curSize; k++){
					
					if(r0 >=0 && r0 < R && c0 >=0 && c0 < C){
						res.emplace_back(vector<int>{r0, c0});
						if(res.size() == R*C) return res;
					}
					r0 += dir[j][0];
					c0 += dir[j][1];
				}
				stepSize++;
			}
		}
		return res;
		
	}
};