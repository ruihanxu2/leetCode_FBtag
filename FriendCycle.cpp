class Solution {
public:
	void dfs(vector<vector<int>>& M, vector<bool>& visited, int i){
		visited[i] = true;
		for(int nei = 0; nei < M.size(); nei++){
			if(i == nei) continue;
			if(M[i][nei] == 1 && visited[nei] == false){
				dfs(M, visited, nei);    
			}
		}
	}
	
	int findCircleNum(vector<vector<int>>& M) {
		int n = M.size();
		if(n == 0) return 0;
		int res = 0;
		vector<bool> visited(n, false);
		for(int i = 0; i < n; i++){
			if(!visited[i]){
				res++;
				dfs(M, visited, i);
			}
		}
		return res;
	}
};