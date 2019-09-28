class Solution {
public:
	bool isValidSudoku(vector<vector<char>>& board) {
		vector<unordered_set<char> > rows(9, unordered_set<char>());
		vector<unordered_set<char> > cols(9, unordered_set<char>());
		vector<unordered_set<char> > blocks(9, unordered_set<char>());
		for(int i = 0; i < 9; i++){
			for(int j = 0; j < 9; j++){
				char cur = board[i][j];
				if(cur != '.'){
					int blockNum = i / 3 * 3+ (j / 3);
					if(rows[i].count(cur)) return false;
					if(cols[j].count(cur)) return false;
					if(blocks[blockNum].count(cur)) return false;
					
					rows[i].insert(cur);
					cols[j].insert(cur);
					blocks[blockNum].insert(cur);
				}
			}
		}
		return true;
	}
};
