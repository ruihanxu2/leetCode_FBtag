class Solution {
public:
	vector<vector<int>> grid;
	bool validPos(int i, int j){
		int r = grid.size();
		int c = grid[0].size();
		return (i >= 0 && i < r && j >=0 && j < c);
	}
	void helper(int i, int j, string& pattern, char p){
		if(validPos(i, j) && grid[i][j] == 1){
			grid[i][j] = 0;
			pattern+=p;
			helper(i-1, j, pattern, 'u');
			helper(i, j+1, pattern, 'r');
			helper(i+1, j, pattern, 'd');
			helper(i, j-1, pattern, 'l');
			pattern+='#';
			
		}
		
		
	}
	int numDistinctIslands(vector<vector<int>>& grid_) {
		grid = grid_;
		int r = grid.size();
		if(r == 0) return 0;
		int c = grid[0].size();
		if(c == 0) return 0;
		unordered_set<string> s;
		for(int i = 0; i < r; i++){
			for(int j = 0; j < c; j++){
				string pattern = "";
				helper(i, j, pattern, '0');
				if(!pattern.empty()){
					s.insert(pattern);
				}
				
			}
		}
		return s.size();
	}
};



 1 0
 1 1


 1 1
 1 0


//if d , u, r, l
// both will be 'dr'