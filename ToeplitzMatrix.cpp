class Solution {
public:
	bool isToeplitzMatrix(vector<vector<int>>& matrix) {
		int r = matrix.size();
		if(r == 0 || r == 1) return true;
		int c = matrix[0].size();
		if(c == 0 || c == 1) return true;
		
		for(int i = 0; i < r - 1; i++){
			vector<int>& r1 = matrix[i];
			vector<int>& r2 = matrix[i+1];
			for(int j = 1; j < c; j++){
				if(r2[j] != r1[j - 1]) return false;
			}
		}
		return true;
		
	}
};