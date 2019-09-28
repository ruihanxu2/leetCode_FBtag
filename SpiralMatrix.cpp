class Solution {
public:
	vector<int> spiralOrder(vector<vector<int>>& matrix) {
		vector<int> res;
		int r = matrix.size();
		if(r == 0) return res;
		int c = matrix[0].size();
		if(c == 0) return res;
		// r, c - 1, r - 1, c - 2
		// 1  2      3      4
		//r/ c  - count / 2
		vector<vector<int> > d{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
		int count = 1;
		int dir = 0;
		int i = 0, j = -1;
		int tot = 0;
		vector<int> num = {c, r}; // 1, 2
		while(1){
			if(tot == r*c) return res;
			for(int k = 0; k < num[dir%2] - (count / 2); k++, tot++){
				i+=d[dir%4][0];
				j+=d[dir%4][1];
				res.emplace_back(matrix[i][j]);
				
			}
			count++;
			dir++;
			
			
		}
		return res;
	}
};