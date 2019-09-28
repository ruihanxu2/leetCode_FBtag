bool win(char c, vector<string>& board){
	if(board[0][0] == c && board[0][1] == c && board[0][2] == c) return true;
	if(board[1][0] == c && board[1][1] == c && board[1][2] == c) return true;
	if(board[2][0] == c && board[2][1] == c && board[2][2] == c) return true;
	if(board[0][0] == c && board[1][0] == c && board[2][0] == c) return true;
	if(board[0][1] == c && board[1][1] == c && board[2][1] == c) return true;
	if(board[0][2] == c && board[1][2] == c && board[2][2] == c) return true;
	if(board[0][0] == c && board[1][1] == c && board[2][2] == c) return true;
	if(board[0][2] == c && board[1][1] == c && board[2][0] == c) return true;
	return false;
}


bool validTicTacToe(vector<string>& board) {
	int countX = 0;
	int countO = 0;
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){
			if(board[i][j] == 'X') countX++;
			if(board[i][j] == 'O') countO++;
			
		}
	}
	if(countX-countO > 1 || countO - countX > 0) return false;
	if(win('X', board) && countX - countO == 0) return false;
	if(win('O', board) && (countX - countO == 1 || win('X', board))) return false;
	return true;
}
