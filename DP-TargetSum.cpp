
 vector<vector<int> > dp(nums.size() + 1, vector<int>(target + 1, 0));
	 dp[0][0] = 1;
	 for(int i = 1; i <= nums.size(); i++){
	     for(int j = 0; j <= target; j++){
	         dp[i][j] = dp[i-1][j];
	         if (j - nums[i - 1] >= 0){
	             dp[i][j] += dp[i - 1][j - nums[i - 1]];
	         }
	     }
	 }

class Solution_brutal {
public:
	void dfs(int& res, int pos, int cur, vector<int>& nums, int S){
		if(pos == nums.size() && cur == S) res++;
		else if(pos < nums.size()){
			dfs(res, pos + 1, cur + nums[pos], nums, S);
			dfs(res, pos + 1,  cur - nums[pos], nums, S);
		}
	}
	int findTargetSumWays(vector<int>& nums, int S) {
		int res = 0;
		dfs(res, 0, 0, nums, S);
		return res;
	}
};

class Solution_memo {
public:
	unordered_map<int, unordered_map<int, int> > m; // pos -> [ curSum- > number ]
	int dfs(int pos, int cur, vector<int>& nums, int S){
		if(pos == nums.size()){
			if(cur == S) return 1;
			else return 0;
		}
		if(m.count(pos) && m[pos].count(cur)){
			return m[pos][cur];
		}
		int add = dfs(pos + 1, cur + nums[pos], nums, S);
		int substract = dfs(pos + 1, cur - nums[pos], nums, S);
		m[pos][cur] = add + substract;
		return m[pos][cur];
	}
	int findTargetSumWays(vector<int>& nums, int S) {
	   
		dfs(0, 0, nums, S);
		return m[0][0];
	}
};

class Solution_KnapSack {
public:
	
	int findTargetSumWays(vector<int>& nums, int S) {
		int sum = accumulate(nums.begin(), nums.end(), 0);
		// sum(P) - sum(N) == Target
		// sum(P) - sum(N) + sum(P) + sum(N) == Target + sum
		// 2*sum(P) = Target + sum
		// sum(P) = (Target + sum) / 2
		if(sum < S || (S + sum)%2 == 1) return 0;
		//Subset sum problem: find a subset that has a target of (S + sum) / 2
		int target = (S + sum)/2;

		vector<int> dp(target + 1, 0);
		dp[0] = 1;
		for(auto n : nums){
			for(int j = target; j >= n; j--){
				dp[j] += dp[j - n];
			}    
		}
		return dp.back();
		
	}
};

class Solution{
public:
	int findTargetSumWays(vector<int>& nums, int S) {
		unordered_map<int, int> m; // sum, freq
		m[0] = 1;
		for(int i = 0; i < nums.size(); i++){
			unordered_map<int, int> tmp;
			for(auto p : m){
				if(tmp.count(p.first + nums[i])) tmp[p.first + nums[i]] += m[p.first];
				else tmp[p.first + nums[i]] = m[p.first];
				
				if(tmp.count(p.first - nums[i])) tmp[p.first  -nums[i]] += m[p.first];
				else tmp[p.first - nums[i]] = m[p.first];
				
			}
			m = tmp;
		}
		
		return m[S];
	}
	
};

