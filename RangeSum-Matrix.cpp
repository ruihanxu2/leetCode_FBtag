class NumMatrix {
	vector<vector<int> > sum;
public:
	NumMatrix(vector<vector<int>>& matrix) {
		int r = matrix.size();
		if(r == 0) return;
		int c = matrix[0].size();
		if(c == 0) return;
		sum.resize(r + 1, vector<int>(c + 1, 0));
 		//注意要包住
		for(int i = 1; i <= r; i++){
			for(int j = 1; j <= c; j++){
				sum[i][j] = sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1] + matrix[i-1][j-1];
			}
		}
	}
	
	int sumRegion(int row1, int col1, int row2, int col2) {
		return sum[row2+1][col2+1] - sum[row1][col2+1] - sum[row2+1][col1] + sum[row1][col1];
	}
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */