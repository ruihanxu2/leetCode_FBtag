//NlogM
class Solution {
public:
	bool searchMatrix(vector<vector<int>>& matrix, int target) {
		int r = matrix.size();
		if(r == 0) return false;
		int c = matrix[0].size();
		if(c == 0) return false;
		int i = 0, j = c - 1;
		
		for(int i = 0; i < r; i++){
			int pos = lower_bound(matrix[i].begin(), matrix[i].end(), target) - matrix[i].begin();
			if(pos < c && matrix[i][pos] == target) return true;
		}
		return false;
		
		
	}
};
//O(m + n)
class Solution {
public:
	bool searchMatrix(vector<vector<int>>& matrix, int target) {
		int r = matrix.size();
		if(r == 0) return false;
		int c = matrix[0].size();
		if(c == 0) return false;
		int i = r - 1, j = 0;
		while( j < c && i >= 0){
			if(matrix[i][j] == target) return 1;
			else if(matrix[i][j] < target) j++;
			else i--;
		}
		return false;
		
	}
};