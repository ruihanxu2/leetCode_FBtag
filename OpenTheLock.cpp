class Solution {
	unordered_set<string> visited;
public:
	vector<string> findNeighbor(string cur, unordered_set<string>& visited){
		vector<string> res;
		for(int i = 0; i < 4; i++){
			string tmp1 = cur;
			string tmp2 = cur;
			if(cur[i] == '0'){
				tmp1[i] += 1;
				tmp2[i] = '9';
			}else if(cur[i] == '9'){
				tmp1[i] = '0';
				tmp2[i] -= 1;
			}
			else{
				tmp1[i]+=1;
				tmp2[i]-=1;
			}
			if(!visited.count(tmp1)) res.emplace_back(tmp1);
			if(!visited.count(tmp2)) res.emplace_back(tmp2);
		}
		return res;
		
	}
	int openLock(vector<string>& deadends, string target) {
		unordered_set<string> visited(deadends.begin(), deadends.end());
		if(visited.count("0000")) return -1;
		queue<string> q;
		q.emplace("0000");
		visited.insert("0000");
		int res = 0;
		while(!q.empty()){
			int n = q.size();
			for(int i = 0; i < n; i++){
				string cur = q.front();
				if(cur == target) return res;
				q.pop();
				
				vector<string> nei = findNeighbor(cur, visited);
				
				for(auto& s : nei){
					q.emplace(s);
					visited.insert(s);
					
				}
				
			}
			res++;
		}
		return -1;
	} 
};