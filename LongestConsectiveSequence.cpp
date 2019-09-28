class SolutionUF {
public:
	vector<int> parents;
	vector<int> size;
	int longestConsecutive(vector<int>& nums) {
		if(nums.size() == 0) return 0;
		unordered_map<int, int> m;
		for(int i = 0; i< nums.size(); i++){
			if(!m.count(nums[i])) m[nums[i]] = m.size();
			size.emplace_back(1);
			parents.emplace_back(i);
		}
		
		for(auto& n:nums){

			if(m.count(n-1)){
				uni(m[n-1], m[n]);
			}
			if(m.count(n+1)){
				uni(m[n+1], m[n]);
			}
		}
		return *max_element(size.begin(), size.end());
	}
	
	int find(int x){
		//cout<<"45";
		if(parents[x]!=x){
			parents[x] = find(parents[x]);
		}
		
		return parents[x];
	}
	 
	void uni(int x, int y){
		int a = find(x);
		int b = find(y);
		if(a == b) return;
		else if(size[a]<=size[b]){
			parents[a] = b;
			size[b]+=size[a];
		}
		else{
			parents[b] = a;
			size[a]+=size[b];
		}

		
	}
};

class Solution {
public:
	int longestConsecutive(vector<int>& nums) {
		if(nums.empty()) return 0; 
		unordered_set<int> s(nums.begin(), nums.end());
		int res = 0;
		
		while(!s.empty()){
			int cur = *s.begin();
			s.erase(s.begin());
			int count = 1;
			int bigger = cur + 1;
			int smaller = cur - 1;
			while(s.count(bigger)){
				s.erase(bigger);
				bigger++;
				count++;
			}
			while(s.count(smaller)){
				s.erase(smaller);
				smaller--;
				count++;
			}
			res = max(count, res);
		}
		return res;
	} 
};