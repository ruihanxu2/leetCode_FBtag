class Solution {
public:
	void dfs(int i, int j, vector<vector<char>>& grid){
		if(i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size()){
			return;
		}
		if(grid[i][j] == '1') grid[i][j] = '.';
		else return;
		
		dfs(i+1, j, grid);
		dfs(i-1, j, grid);
		dfs(i, j+1, grid);
		dfs(i, j-1, grid);
	}
	int numIslands(vector<vector<char>>& grid) {
		int r = grid.size();
		if(r == 0) return 0;
		int c = grid[0].size();
		if(c == 0) return 0;
		
		int res = 0;
		
		for(int i = 0; i < r; i++){
			for(int j = 0; j < c; j++){
           if(grid[i][j] == '1'){
                dfs(i, j, grid);
                res++;
           }
			}
		}
		return res;
	}
};


//NumOfIslandII
class Solution {
private:
	vector<int> parents;
	vector<int> rank;
	
public:
	vector<int> numIslands2(int r, int c, vector<vector<int>>& positions) {
		
		vector<int> res;
 
		
		for(int i = 0; i< r; i++){
			for(int j = 0; j < c; j++){
				parents.emplace_back(i*c+j);
				rank.emplace_back(0);
			}
		}
	   // cout<<parents.size()<<endl;
		vector<vector<int>> grid(r, vector<int>(c, 0));
		int count = 0;
		
		for(auto& p:positions){
			int i = p[0];
			int j = p[1];
			if(grid[i][j] == 1){
				res.emplace_back(count);
				continue;
			}
			grid[i][j] = 1;
			int uni_count = 0;
			if(i-1>=0&&grid[i-1][j] == 1){
				if(uni(i*c+j, (i-1)*c+j)) uni_count++;
			}
			if(i+1<r&&grid[i+1][j] == 1){
				if(uni(i*c+j, (i+1)*c+j)) uni_count++;
			}
			if(j-1>=0&&grid[i][j-1] == 1){
				if( uni(i*c+j, i*c+j-1)) uni_count++;
			}
			if(j+1<c&&grid[i][j+1] == 1){
				if(uni(i*c+j, i*c+j+1)) uni_count++;
			}
			//cout<<uni_count<<" ";
			count+=(1-uni_count);
			res.emplace_back(count);
		}
		return res;
		
	}
	
	int find(int x){
		if(parents[x]!=x){
			parents[x] = find(parents[x]);
		}
		return parents[x];
	}
	
	bool uni(int x, int y){
		//cout<< x<<" "<<y;
		int a = find(x);
		int b = find(y);
		
		if(a == b) return false;
		else if(rank[a]<rank[b]){
			parents[a] = b;
		}
		else if(rank[b]<rank[a]){
			parents[b] = a;
		}
		else{
			parents[a] = b;
			rank[b]++;
		}
		return true;
	}
};