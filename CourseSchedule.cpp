class Solution_bfs {
public:
	bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
		unordered_map<int, unordered_set<int> > adjlist;
		for(auto p : prerequisites){
			adjlist[p[0]].insert(p[1]);
		}
		unordered_map<int, int> indegree; // num, freq
		for(int i = 0; i < numCourses; i++){
			if(!adjlist.count(i)) indegree[i] = 0;
			else{
				for(auto j : adjlist[i]){
					indegree[j]++;
				}
			}
			
		}
		queue<int> q;
		for(int i = 0; i < numCourses; i++){
			if(indegree[i] == 0) q.emplace(i);    
		}
		int res = 0;
		while(!q.empty()){
			int cur = q.front();
			q.pop();
			res++;
			for(auto nei : adjlist[cur]){
				indegree[nei]--;
				if(indegree[nei] == 0){
					q.emplace(nei);
				}
			}
		}
		return res == numCourses;
	}
};
//dfs
class Solution {
public:
	bool isPossible = true;
	vector<bool> visited;
	vector<bool> done;
	unordered_map<int, unordered_set<int> > adjlist;
	void dfs(int cur){
		if(!isPossible) return;
		visited[cur] = true;
		for(int nei : adjlist[cur]){
			if(visited[nei] && !done[nei]) isPossible = false;
			if(!visited[nei]) {
				dfs(nei);
				
			}
		}
		done[cur] = true;
	}
	bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
		visited.resize(numCourses, false);
		done.resize(numCourses, false);
		for(auto p : prerequisites){
			adjlist[p[0]].insert(p[1]);
		}
		for(int i = 0; i < numCourses; i++){
			if(!done[i]) dfs(i);
		}
		return isPossible;
		
	}
};