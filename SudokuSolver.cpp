class Solution {
	vector<vector<int> > rowCount;
	vector<vector<int> > colCount;
	vector<vector<int> > cellCount;
	bool completed = false;
	//vector<vector<char>>& board;
	bool canPlace(int r, int c, int n){
		int cellid = r/3*3+c/3;
		return rowCount[r][n] == 0 && colCount[c][n] == 0 && cellCount[cellid][n] == 0;
	}
	void putNum(vector<vector<char>>& board, int r, int c, int n){
		int cellid = r/3*3+c/3;
		board[r][c] = '0' + n;
		rowCount[r][n]++;
		colCount[c][n]++;
		cellCount[cellid][n]++;
	}
	
	void removeNum(vector<vector<char>>& board, int r, int c, int n){
		int cellid = r/3*3+c/3;
		board[r][c] = '.';
		rowCount[r][n]--;
		colCount[c][n]--;
		cellCount[cellid][n]--;
	}
	
	void backtrackNext(vector<vector<char>>& board, int r, int c){
		if(r == 8 && c == 8){
			completed = true;
		}
		else{
			if(c == 8) backtrack(board, r+1, 0);
			else backtrack(board, r, c+1);
		}
	}
	
	
	
	void backtrack(vector<vector<char>>& board, int r, int c){
		if(board[r][c] == '.'){
			for(int i = 1; i < 10; i++){
				if(canPlace(r, c, i)){
					putNum(board, r, c, i);
					backtrackNext(board, r, c);
					if(!completed) removeNum(board,r,c,i);
				}
			}
		}
		else{
			backtrackNext(board, r, c);
		}
	}
	
public:    
	void solveSudoku(vector<vector<char>>& board) {
		rowCount.resize(9,vector<int>(10, 0));
		colCount.resize(9,vector<int>(10, 0));
		cellCount.resize(9,vector<int>(10, 0));
		for(int i = 0; i < 9; i++){
			for(int j = 0; j < 9; j++){
				if(board[i][j] != '.'){
					int n = board[i][j] - '0';
					putNum(board, i, j, n);
				}
			}
		}
		backtrack(board, 0, 0);
	}
};