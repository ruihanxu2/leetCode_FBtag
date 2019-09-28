class Solution {
   
	vector<vector<string> > res;
	vector<bool> colFlag;
	vector<bool> flag45;
	vector<bool> flag135;
	void helper(int r, int n, vector<string>& board){
		if(r == n){
			res.emplace_back(board);
			return;
		}
		for(int c = 0; c < n; c++){
			if(colFlag[c] && flag45[r + c] && flag135[n - 1 - r + c]){
				colFlag[c] = flag45[r + c] = flag135[n - 1 - r + c] = false;
				board[r][c] = 'Q';
				helper(r + 1, n, board);
				board[r][c] = '.';
				colFlag[c] = flag45[r + c] = flag135[n - 1 - r + c] = true;
			}
		}
	}
public:
	vector<vector<string>> solveNQueens(int n) {
		vector<string> board(n, string(n, '.'));
		colFlag = vector<bool>(n, 1);
		flag45 = vector<bool>(2 * n, 1);
		flag135 = vector<bool>(2 * n, 1);
		helper(0, n, board);
		return res;
		
	}
};



//------------------------------------------------------------------
class Solution_ {
	int n;
	vector<vector<string> > res;
	void placeQueen(int i, int j, vector<string>& board){
		board[i][j] = 'Q';
		for(int r = i + 1; r < n; r++){
			if(board[r][j] == '.') board[r][j]  = '1';
			else board[r][j] += 1;
		}
		
		for(int r = i + 1, c = j + 1; r < n && c < n; r++, c++){
			if(board[r][c] == '.') board[r][c]  = '1';
			else board[r][c] += 1;
		}
		for(int r = i + 1, c = j - 1; r < n && c >= 0; r++, c--){
			if(board[r][c] == '.') board[r][c]  = '1';
			else board[r][c] += 1;
		}
	}
	void removeQueen(int i, int j, vector<string>& board){
		board[i][j] = '.';
		for(int r = i + 1; r < n; r++){
			if(board[r][j] == '1') board[r][j]  = '.';
			else board[r][j] -= 1;
		}
		
		for(int r = i + 1, c = j + 1; r < n && c < n; r++, c++){
			if(board[r][c] == '1') board[r][c]  = '.';
			else board[r][c] -= 1;
		}
		for(int r = i + 1, c = j - 1; r < n && c >= 0; r++, c--){
			if(board[r][c] == '1') board[r][c]  = '.';
			else board[r][c] -= 1;
		}
	}
	void cleanUp(vector<string> board){
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				if(board[i][j] != 'Q') board[i][j] = '.';
			}
		}
		res.emplace_back(board);
	}
	void backtrack(int i, vector<string>& board){
		if(i == n){
			cleanUp(board);
		}
		else{
			for(int j = 0; j < n; j++){
				if(board[i][j] == '.'){
					placeQueen(i, j, board);
					backtrack(i+1, board);
					removeQueen(i, j, board);
				}
			}    
		}
	}
public:
	
	vector<vector<string>> solveNQueens(int n) {
		this->n = n;
		vector<string> board(n, string(n, '.'));
		backtrack(0, board);
		
		return res;
	}
};