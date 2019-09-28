class Solution1 {
public:
	void dfs(vector<vector<char>>& board, int i , int j){
		if(i < 0 || j < 0 || i >= board.size() || j >= board[0].size()) return;
		if(board[i][j] == '.') return;
		board[i][j] = '.';
		dfs(board, i+1, j);
		dfs(board, i, j+1);
	}
	int countBattleships(vector<vector<char>>& board) {
		int r = board.size();
		if(r == 0) return 0;
		int c = board[0].size();
		if(c == 0) return 0;
		int res = 0;
		
		for(int i = 0; i < r; i++){
			for(int j = 0; j < c; j++){
				if(board[i][j] == 'X'){
					res++;
					dfs(board, i, j);
				}        
			}
		}
		return res;
	}
};

class Solution {
public:
	
	int countBattleships(vector<vector<char>>& board) {
		int r = board.size();
		if(r == 0) return 0;
		int c = board[0].size();
		if(c == 0) return 0;
		int res = 0;
		
		for(int i = 0; i < r; i++){
			for(int j = 0; j < c; j++){
				if(board[i][j] == 'X'){
					if(i == 0 && j == 0) res++;
					else if(i == 0 && board[i][j - 1] == '.') res++;
					else if(j == 0 && board[i - 1][j] == '.') res++;
					else if(i > 0 && j > 0 && board[i][j - 1] == '.' && board[i - 1][j] == '.') res++;
				}
			}
		}
		return res;
	}
};