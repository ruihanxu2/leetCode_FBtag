void rotate(vector<vector<int>>& matrix) {
	int r = matrix.size();
	if(r == 0) return;
	int c = matrix[0].size();
	if(c == 0) return;
	
	for(int i = 0; i < r; i++){
		for(int j = i; j < c; j++){
			swap(matrix[i][j], matrix[j][i]);
		}
	}
	
	for(int i = 0; i < r; i++){
		for(int j = 0; j < c / 2; j++){
			swap(matrix[i][j], matrix[i][c - j - 1]);
		}
	}
	
	return;
}