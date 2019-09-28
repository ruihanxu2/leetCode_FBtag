//time complexity; num of 1 * num of 0
//(mn)^2
class Solution {
public:
	bool valid(int r, int c, int R, int C){
		return r >=0 && c>=0 && r < R && c < C;
	}
	int shortestDistance(vector<vector<int>>& grid) {
		int r = grid.size();
		if(r == 0) return -1;
		int c = grid[0].size();
		if(c == 0) return -1;
		vector<vector<int> > dist(r, vector<int>(c, 0));
		vector<vector<int> > dir{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
		int minDist;
		int connectedBuilding = 0;
		for(int i = 0; i < r; i++){
			for(int j = 0; j < c; j++){
				if(grid[i][j]!=1) continue;
				// building
				minDist = INT_MAX;
				queue<pair<int, int> > q;
				q.push({i, j});
				int level = 1;
				while(!q.empty()){
					int n = q.size();
					for(int i = 0; i < n; i++){
						auto p = q.front();
						q.pop();
						int curRow = p.first;
						int curCol = p.second;
						for(int i = 0; i < 4; i++){
							int newRow = curRow + dir[i][0];
							int newCol = curCol + dir[i][1];
							if(valid(newRow, newCol, r, c) && grid[newRow][newCol] == connectedBuilding){
								dist[newRow][newCol] += level;
								minDist = min(minDist, dist[newRow][newCol]);
								grid[newRow][newCol]--;
								q.push({newRow, newCol});
							}
						}
					}
					level++;
				}
				connectedBuilding--;
			}    
		}
		return minDist == INT_MAX ? -1 : minDist;
		
	}
};