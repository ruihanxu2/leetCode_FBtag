class Solution_ {
	vector<vector<vector<vector<int> > > > memo;
	int N;
public:
	int helper(vector<vector<int>>& grid, int r1, int c1, int r2, int c2){

		if(r1 < 0 || r2 < 0 || r1 >= N || r2 >= N || c1 < 0 || c2 < 0 || c1 >= N || c2 >= N || grid[r1][c1] == -1 || grid[r2][c2] == -1){
			return INT_MIN;
		}
		if(memo[r1][c1][r2][c2] > INT_MIN){
			return memo[r1][c1][r2][c2];
		}
		
		if(r1 == N - 1 && c1 == N - 1){
			memo[r1][c1][r2][c2] = grid[N-1][N-1];
			return grid[N-1][N-1];
		}
		if(r2 == N - 1 && c2 == N - 1){
			memo[r1][c1][r2][c2] = grid[N-1][N-1];
			return grid[N-1][N-1];
		}
		int res = 0;
		
		if(r1 == r2 && c1 == c2){
			res+=grid[r1][c1];
		}
		else{
			res+=grid[r2][c2] + grid[r1][c1];
		}
		
		res+=max({helper(grid, r1+1, c1, r2+1, c2),helper(grid, r1+1, c1, r2, c2+1),helper(grid, r1, c1+1, r2+1, c2),helper(grid, r1, c1+1, r2, c2+1)});
		memo[r1][c1][r2][c2] = res;
		return res;
		
	}
	int cherryPickup(vector<vector<int>>& grid) {
		N = grid.size();
		memo.resize(N, vector<vector<vector<int>>>(N, vector<vector<int>>(N, vector<int>(N, INT_MIN))));
		return max(helper(grid, 0,0,0,0), 0);
	}
};


// optimize to N^3

class Solution {
	vector<vector<vector<int> > > memo;
	int N;
public:
	
	int helper(vector<vector<int>>& grid, int r1, int c1, int r2) {
		
		int c2 = r1 + c1 - r2;
		if(r1 < 0 || r2 < 0 || r1 >= N || r2 >= N || c1 < 0 || c2 < 0 || c1 >= N || c2 >= N || grid[r1][c1] == -1 || grid[r2][c2] == -1){
			return INT_MIN;
		}
		if(memo[r1][c1][r2] > INT_MIN){
			return memo[r1][c1][r2];
		}
		int res = 0;
		if(r1 == N - 1 && c1 == N - 1){
			memo[r1][c1][r2] = grid[N-1][N-1];
			return grid[N-1][N-1];
		}
		if(r2 == N - 1 && c2 == N - 1){
			memo[r1][c1][r2] = grid[N-1][N-1];
			return grid[N-1][N-1];
		}
		
		if(r1 == r2 && c1 == c2){
			res+=grid[r1][c1];
		}
		else{
			res+=grid[r2][c2] + grid[r1][c1];
		}
		
		res+=max({helper(grid, r1+1, c1, r2+1),helper(grid, r1+1, c1, r2),helper(grid, r1, c1+1, r2+1),helper(grid, r1, c1+1, r2)});
		memo[r1][c1][r2] = res;
		return res;
		
	}
	int cherryPickup(vector<vector<int>>& grid) {
		N = grid.size();
		memo.resize(N, vector<vector<int>>(N, vector<int>(N, INT_MIN)));
		return max(helper(grid, 0, 0, 0), 0);
	}
};