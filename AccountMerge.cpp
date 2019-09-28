class Solution {
	unordered_map<string, unordered_set<string> > graph;
	unordered_map<string, string> emailToAcc;

	unordered_set<string> visited;
	void dfs(set<string>& group, string cur){
		visited.insert(cur);
		group.insert(cur);
		for(auto nei : graph[cur]){
			if(!visited.count(nei))
				dfs(group, nei);
		}
	}
public:
	vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
		int n = accounts.size();
		for(int i = 0; i < n; i++){
			for(int j = 1; j < accounts[i].size(); j++){
				emailToAcc[accounts[i][j]] = accounts[i][0];
				graph[accounts[i][1]].insert(accounts[i][j]);
				graph[accounts[i][j]].insert(accounts[i][1]);
			}
		}
		
		vector<vector<string> > res;
		for(auto p : graph){
			
			string cur = p.first;
			if(!visited.count(cur)){
				set<string> group;
				dfs(group, cur);
				vector<string> tmp(group.begin(), group.end());
				tmp.insert(tmp.begin(), emailToAcc[cur]);
				res.emplace_back(tmp);
			}
		}
		return res;
		
	   
		
		
	}
};




class Solution_uf {
	vector<int> parent;
	vector<int> rank;
	int find(int x){
		if(x != parent[x]){
			parent[x] = find(parent[x]);
		}
		return parent[x];
	}
	void uni(int x, int y){
		int a = find(x);
		int b = find(y);
		if(a == b) return;
		else if( rank[a] < rank[b] ){
			parent[a] = b;    
		}
		else if( rank[b] < rank[a]){
			parent[b] = a;
		}
		else{
			parent[a] = b;
			rank[b]++;
		}
	}
public:
	vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
		int n = accounts.size();
		parent.resize(n, 0);
		rank.resize(n, 0);
		for(int i = 0; i < n; i++){
			parent[i] = i;
		}
		unordered_map<string, int> m; // email to account id
		
		for(int i = 0; i < n; i++){
			for(int j = 1; j < accounts[i].size(); j++){
				if(m.count(accounts[i][j])){
					uni(i, m[accounts[i][j]]);
				}
				else{
					m[accounts[i][j]] = i;
				}
			}
		}
		for(int i = 0; i < n; i++){
			parent[i] = find(parent[i]);
		}
		
		unordered_map<int, set<string> > result; // merge email
		for(int i = 0; i < n; i++){
			for(int j = 1; j < accounts[i].size(); j++){
				result[parent[i]].insert(accounts[i][j]);
			}
		}
		vector<vector<string> > res;
		for(auto p : result){
			vector<string> cur;
			cur.emplace_back(accounts[p.first][0]);
			for(auto s : p.second){
				cur.emplace_back(s);
			}
			res.emplace_back(cur);
		}
		return res;
		
	}
};

