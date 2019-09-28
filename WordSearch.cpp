class Solution {
public:
	vector<vector<char>> board;
	int R;
	int C;
	bool validPos(int i, int j){
		return i >=0 && j >= 0 && i < R && j < C;
	}
	bool helper(int pos, string word, int r, int c){
		if(pos == word.size()) return true;
		if(!validPos(r,c) || board[r][c] != word[pos]) return false;
		
		char tmp = board[r][c];
		board[r][c] = '.';
		bool flag =helper(pos + 1, word, r, c+1) ||
				   helper(pos + 1, word, r+1, c) ||
				   helper(pos + 1, word, r, c-1) ||
				   helper(pos + 1, word, r-1, c);
		board[r][c] = tmp;
		return flag;
		
			
	}
	
	bool exist(vector<vector<char>>& board_, string word) {
		board = board_;
		if(word.empty()) return true;
		R = board.size();
		if(R == 0) return false;
		C = board[0].size();
		if(C == 0) return false;
		
		char start = word[0];
		for(int r = 0; r < R; r++){
			for(int c = 0; c < C; c++){
					if(helper(0, word, r, c)) return true;
				
			}
		}
		return false;
	}
};