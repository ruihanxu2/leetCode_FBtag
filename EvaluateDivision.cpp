class Solution {
public:
	bool dfs(string start, string end, unordered_map<string, vector<pair<string, double> > >& adjlist, unordered_set<string>& visited, double& cur){
		if(start == end) return true;
		else{
			visited.insert(start);
			bool flag = false;
			for(auto& next : adjlist[start]){
				if(!visited.count(next.first)){
					cur*=next.second;
					if(dfs(next.first, end, adjlist, visited, cur)){
						flag = true;
						break;
					}
					cur/=next.second;
				}
				
			}
			return flag;
		}
	}
	
	vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
		unordered_map<string, vector<pair<string, double> > > adjlist;
		int n = equations.size();
		for(int i = 0; i<n; i++){
			adjlist[equations[i][0]].emplace_back(equations[i][1], values[i]);
			adjlist[equations[i][1]].emplace_back(equations[i][0], 1/values[i]);
		}
		int sz = queries.size();
		vector<double> res(sz, 1);
		for(int i = 0; i < sz; i++){
			if(!adjlist.count(queries[i][0])||!adjlist.count(queries[i][1])){
				res[i] = -1;
				continue;
			}
			else{
				unordered_set<string> visited;
				
				if(dfs(queries[i][0], queries[i][1], adjlist, visited, res[i])){
					continue;
				}
				else{
					res[i] = -1;
				}
				
			}
			
		}
		return res;
	}
};