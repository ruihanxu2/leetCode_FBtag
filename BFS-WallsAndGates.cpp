class Solution {
public:
	void wallsAndGates(vector<vector<int>>& rooms) {
		int r = rooms.size();
		if(r == 0) return;
		int c = rooms[0].size();
		if(c == 0) return;
		queue<pair<int, int> > q;
		for(int i = 0; i < r; i++){
			for(int j = 0; j < c; j ++){
				if(rooms[i][j]== 0) q.push({i, j});
			}
		}
		vector<vector<int> > dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
		while(!q.empty()){
			pair<int, int> cur = q.front();
			q.pop();
			for(auto& dir : dirs){
				int i = cur.first + dir[0];
				int j = cur.second + dir[1];
				if(i < 0 || j < 0 || i >= r || j >= c || rooms[i][j]!=INT_MAX){
					continue;
				}
				rooms[i][j] = rooms[cur.first][cur.second]  + 1;
				q.push({i, j});
			}
			
		}
	}
};

/*
You are given a m x n 2D grid initialized with these three possible values.

-1 - A wall or an obstacle.
0 - A gate.
INF - Infinity means an empty room. We use the value 231 - 1 = 2147483647 to represent INF as you may assume that the distance to a gate is less than 2147483647.
Fill each empty room with the distance to its nearest gate. If it is impossible to reach a gate, it should be filled with INF.

Example: 

Given the 2D grid:

INF  -1  0  INF
INF INF INF  -1
INF  -1 INF  -1
	0  -1 INF INF
After running your function, the 2D grid should be:

	3  -1   0   1
	2   2   1  -1
	1  -1   2  -1
	0  -1   3   4
*/