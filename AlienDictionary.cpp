
class Solution {
public:
	
	string alienOrder(vector<string>& words) {
		// construct graph and indegree
		unordered_map<char, unordered_set<char> > graph;
		unordered_map<char, int> indegree;
		for(auto& word : words){
			for(auto& c : word){
				if(!graph.count(c)) graph[c] = unordered_set<char>();
				indegree[c] = 0;
			}
		}
		for(int i = 0; i < (int)words.size() - 1; i++){
			int n1 = words[i].size();
			int n2 = words[i + 1].size();
			for(int j = 0;  j < min(n1, n2); j++){
				if(words[i][j] == words[i+1][j]){
					continue;
				}
				else{
					graph[words[i][j]].insert(words[i + 1][j]);
					break;
				}
			}
		}
		for(auto p : graph){
			for(auto c : p.second){
				indegree[c]++;
			}
		}
		queue<char> q;
		string res;
		for(auto& p : indegree){
			if(p.second == 0){
				q.emplace(p.first);
			}
		}
		while(!q.empty()){
			char cur = q.front();
			q.pop();
			res+=cur;
			for(auto nei : graph[cur]){
				indegree[nei]--;
				if(indegree[nei] == 0){
					
					q.emplace(nei);
				}
			}
		}
		return res.size() == graph.size() ? res : "";
	}
};

class SolutionDFS {
private:
	unordered_map<char, unordered_set<char> > graph;
	unordered_set<char> done;
	unordered_set<char> visited;
	string res;
	bool cycle = false;
	
	void dfs(char cur){
		if(cycle) return;
		visited.insert(cur);
		for(auto nei : graph[cur]){
			if(visited.count(nei) && !done.count(nei)){
				cycle = true;
				return;
			}
			if(!visited.count(nei)){
				dfs(nei);
			}
		}
		res+=cur;
		done.insert(cur);
	}
	
public:
	
	string alienOrder(vector<string>& words) {
		for(auto& word : words){
			for(auto& c : word){
				if(!graph.count(c)){
					graph[c] = unordered_set<char>();
				}
			}
		}
		for(int i = 0; i < (int)words.size() - 1; i++){
			int n1 = words[i].size();
			int n2 = words[i + 1].size();
			for(int j = 0; j < min(n1, n2); j++){
				if(words[i][j]!=words[i + 1][j]){
					graph[words[i][j]].insert(words[i + 1][j]);
					break;
				}   

			}
		}
		for(auto& p : graph){
			if(!done.count(p.first)) dfs(p.first); 
		}
		reverse(res.begin(), res.end());
		return cycle ? "" : res;
		
		
	}
};
