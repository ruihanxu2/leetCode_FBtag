class TicTacToe {
private:
	vector<int> rowSum;
	vector<int> colSum;
	int diagonalSum1 = 0;
	int diagonalSum2 = 0;
	int goal;
public:
	/** Initialize your data structure here. */
	TicTacToe(int n) {
		rowSum.resize(n, 0);
		colSum.resize(n, 0);
		goal = n;
		
	}
	
	/** Player {player} makes a move at ({row}, {col}).
		@param row The row of the board.
		@param col The column of the board.
		@param player The player, can be either 1 or 2.
		@return The current winning condition, can be either:
				0: No one wins.
				1: Player 1 wins.
				2: Player 2 wins. */
	int move(int row, int col, int player) {
		int cur = player == 1 ? 1 : -1;
		rowSum[row]+=cur;
		colSum[col]+=cur;
		for(auto i : rowSum){
			if(i == goal || i == -goal) return cur == 1 ? 1 : 2; 
		}
		for(auto i : colSum){
			if(i == goal || i == -goal) return cur == 1 ? 1 : 2; 
		}
		if(row == col) diagonalSum1+=cur;
		if(row == goal - col - 1) diagonalSum2+=cur;
		if(diagonalSum1 == goal || diagonalSum2 == goal){
			return 1; 
		}
		if(diagonalSum1 == -goal || diagonalSum2 == -goal){
			return 2; 
		}
		return 0;
	}
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe* obj = new TicTacToe(n);
 * int param_1 = obj->move(row,col,player);
 */