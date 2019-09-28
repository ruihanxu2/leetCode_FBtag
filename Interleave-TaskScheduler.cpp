// a a a a b  k = 1
// a b a c a d

class Solution {
public:
	int leastInterval(vector<char>& tasks, int k) {
		unordered_map<char, int> freq;
		for(auto c : tasks){
			freq[c]++;
		}
		priority_queue<int> pq;
		for(auto p : freq){
			pq.emplace(p.second);
		}
		int cycles = 0;
		while(!pq.empty()){
			vector<int> tmp;
			for(int i = 0; i <= k; i++){
			   if(!pq.empty()){
				   tmp.emplace_back(pq.top());
				   pq.pop();
			   }
			}
			// minus one
			for(int i = 0; i < tmp.size(); i++){
				if(--tmp[i] > 0){
					pq.emplace(tmp[i]);
				}
			}
			// add to cycles
			cycles+= pq.empty() ? tmp.size() : k + 1;
			
		}
		return cycles;
	}
		
};

class Solution2 {
public:
	int leastInterval(vector<char>& tasks, int n) {
		vector<int> freq(26, 0);
		for(auto c : tasks){
			freq[c - 'A']++;
		}
		sort(freq.begin(), freq.end());
		int rows = freq[25] - 1; 
		int idleNum = rows * n;
		for(int i = 24; i >=0 && freq[i] > 0; i--){
			idleNum -= min(freq[i], rows);
		}
		return idleNum < 0 ? tasks.size() : tasks.size() + idleNum;
		
	}
};

class Solution3 {
public:
	int leastInterval(vector<char>& tasks, int n) {
		vector<int> freq(26, 0);
		for(auto c : tasks){
			freq[c - 'A']++;
		}
		sort(freq.begin(), freq.end());
		int res = 0;
		while(freq[25] > 0){
			int i = 0;
			while(i <= n){
				if(freq[25] == 0) break;
				if(i < 26 && freq[25 - i] > 0){
					freq[25 - i]--;
				}
				res++;
				i++;
			}
			sort(freq.begin(), freq.end());
		}
		return res;
	}
};


