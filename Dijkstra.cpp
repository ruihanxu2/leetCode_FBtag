class Solution {
public:
	int networkDelayTime(vector<vector<int>>& times, int N, int K) {
		typedef pair<int, int> iPair;
		unordered_map<int, vector<iPair > > graph; // cur, {nei, dist};
		unordered_map<int, int> dist;
		unordered_set<int> visited;
		for(int i = 1; i <= N; i++){
			dist[i] = INT_MAX;
		}
		dist[K] = 0;
		for(auto& time : times){
			graph[time[0]].emplace_back(time[1], time[2]);
		}
		
		priority_queue<iPair, vector<iPair>, greater<iPair> > pq; // dist, node 
		pq.emplace(0, K);
		while(!pq.empty()){
			int curNode = pq.top().second;
			int curDist = pq.top().first;
			pq.pop();
			if(visited.count(curNode) ) continue;
			visited.insert(curNode);
			for(auto nei : graph[curNode]){
				int nextNode = nei.first;
				int nextDist = nei.second;
				
				if(curDist + nextDist < dist[nextNode]){
					dist[nextNode] = curDist + nextDist;
					pq.emplace(dist[nextNode], nextNode);
				}
			}
		}
		// --------------------
		int res = 0;
		if(visited.size()!= N) return -1;
		for(auto p : dist){
			res = max(res, p.second);
		}
		return res;
	}
};