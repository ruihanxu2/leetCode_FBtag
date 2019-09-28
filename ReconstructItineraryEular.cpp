class Solution {
	vector<string> res;
	unordered_map<string, multiset<string> > graph;
public:
	void dfs(string city){
		while(!graph[city].empty()){
			string next = *graph[city].begin();
			graph[city].erase(graph[city].begin());
			dfs(next);
		}
		res.emplace_back(city);
		
	}
	
	vector<string> findItinerary(vector<vector<string>>& tickets) {
		for(auto ticket : tickets){
			graph[ticket[0]].insert(ticket[1]);
		}
		dfs("JFK");
		reverse(res.begin(), res.end());
		return res;
		
	}
};

class Solution_ {
public:
	
	vector<string> findItinerary(vector<vector<string>>& tickets) {
		stack<string> s;
		vector<string> res;
		unordered_map<string, multiset<string> > adjlist;
		for(auto& ticket : tickets){
			adjlist[ticket[0]].insert(ticket[1]);
		}
		s.emplace("JFK");
		while(!s.empty()){
			string cur = s.top();
			if(adjlist[cur].empty()){
				res.emplace_back(cur);
				s.pop();
			}
			else{
				s.emplace(*adjlist[cur].begin());
				adjlist[cur].erase(adjlist[cur].begin());
			}
		}
		return vector<string>(res.rbegin(), res.rend());
	}
};


