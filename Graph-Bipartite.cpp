class Solution {
public:
	bool isBipartite(vector<vector<int>>& graph) {
		int n = graph.size();
		if(n == 0) return true;
		vector<int> color(graph.size(), -1);
		//-1 is not assigned a color, and 1, 0
		for(int i = 0; i < n; i++){
			queue<int> q;
			if(color[i] == -1){
				q.emplace(i);
				color[i] = 0;
				while(!q.empty()){
					int cur = q.front();
					q.pop();
					for(auto next : graph[cur]){
						if(color[next] == -1){
							color[next] = 1-color[cur];
							q.emplace(next);
						}else{
							if(color[next]!=1-color[cur]){
								return false;
							}
						}
					}
				}
			}
		}
		return true;
	}
};