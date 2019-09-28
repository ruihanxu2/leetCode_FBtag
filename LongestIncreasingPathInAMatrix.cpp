class Solution {
	vector<vector<int> > dp; // stores the current longest
	int res = 0;
	bool isValid(int r, int c, int R, int C){
		return (r < R && c < C && r >= 0 && c >= 0);    
	}
	int dfs(int r, int c, int R, int C, int prev, vector<vector<int>>& matrix){
		if(!isValid(r, c, R, C)) return 0;
		if(matrix[r][c] <= prev) return 0;
		// cur pos has larger value
		if(dp[r][c] != -1 ) return dp[r][c];
		
		int left = dfs(r, c-1, R, C, matrix[r][c], matrix);
		int right = dfs(r, c+1, R, C, matrix[r][c], matrix);
		int up = dfs(r-1, c, R, C, matrix[r][c], matrix);
		int down = dfs(r+1, c, R, C, matrix[r][c], matrix);
		
		dp[r][c] = max({left, right, up, down}) + 1;
		res = max(res, dp[r][c]);
		return dp[r][c];
	}
public:
	
	int longestIncreasingPath(vector<vector<int>>& matrix) {
		int r = matrix.size();
		if(r == 0) return 0;
		int c = matrix[0].size();
		if(c == 0) return 0;
		dp.resize(r, vector<int>(c, -1));
		
		for(int i =0; i < r; i++){
			for(int j = 0; j < c; j++){
				if(dp[i][j] == -1){
					dfs(i, j, r, c, matrix[i][j]-1, matrix);
				}    
			}
		}
		return res;
	}
};