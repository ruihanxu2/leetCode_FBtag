class Solution {
	vector<vector<int> > dir = {{0, 1},{1,1},{1,0},{1,-1},{0, -1},{-1, -1},{-1, 0},{-1,1}};
	bool validPos(int r, int c, int R, int C){
		return (r >= 0 && c >= 0 && r < R && c < C);
	}
	void dfs(vector<vector<char>>& board, int r, int c, int R, int C){
		if(!validPos(r, c, R, C)) return;
		if(board[r][c]!='E') return;
		
		int count = 0; // used to count mines surrounding, M, X
		for(int i = 0; i < 8; i++){
			int newR = r + dir[i][0];
			int newC = c + dir[i][1];
			if(validPos(newR, newC, R, C) && (board[newR][newC] == 'X' || board[newR][newC] == 'M') ){
				count++;
			}   
		}
		if(count == 0){
			board[r][c] = 'B';
			for(int i = 0; i < 8; i++){
				int newR = r + dir[i][0];
				int newC = c + dir[i][1];
				if(validPos(newR, newC, R, C)) dfs(board, newR, newC, R, C);
			}
		}
		else{
			board[r][c] = count + '0';
		}
	}
public:
	
	vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
		int r = board.size();
		if(r == 0) return board;
		int c = board[0].size();
		if(c == 0) return board;
		
		int row = click[0];
		int col = click[1];
		if(board[row][col] == 'M'){
			board[row][col] = 'X';
		}
		else if(board[row][col] == 'E'){
			dfs(board, row, col, r, c);
		}
		return board;
		
	}
};