class Solution {
public:
	vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
		int n = nums.size();
		int round = 3;
		vector<int> prefix(n + 1, 0);
		for(int i = 1; i <= n; i++){
			prefix[i] = prefix[i-1] + nums[i - 1];
		}
		vector<int> dp1(n + 1, 0);
		vector<int> dp2(n + 1, 0);
		
		vector<vector<vector<int> > > sol(round + 1, vector<vector<int> >(n + 1, vector<int>()));
		for(int i = 1; i <= round; i++){
			for(int j = k * i; j <= n; j++){
				int cur = dp1[j - k] + prefix[j] - prefix[j - k];
				if(dp2[j - 1] >= cur ){
					sol[i][j] = sol[i][j-1];
					dp2[j] = dp2[j - 1];
				}
				else{
					sol[i][j] = sol[i-1][j - k];
					sol[i][j].emplace_back(j - k);
					dp2[j] = cur;
				}
			}
			swap(dp1, dp2);
			fill(dp2.begin(), dp2.end(), 0);
		}
		cout<<dp1[n];
		return sol[3][n];
	}
};


//-------------------
class Solution {
public:
	vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
		int n = nums.size();
		int round = 3;
		vector<int> prefix(n + 1, 0);
		for(int i = 1; i <= n; i++){
			prefix[i] = prefix[i-1] + nums[i - 1];
		}
		vector<int> dp1(n + 1, 0);
		vector<int> dp2(n + 1, 0);
		vector<vector<int> > sol1(n + 1, vector<int>());
		vector<vector<int> > sol2(n + 1, vector<int>());
		for(int i = 1; i <= round; i++){
			for(int j = k * i; j <= n; j++){
				int cur = dp1[j - k] + prefix[j] - prefix[j - k];
				if(dp2[j - 1] >= cur ){
					sol2[j] = sol2[j-1];
					dp2[j] = dp2[j - 1];
				}
				else{
					sol2[j] = sol1[j - k];
					sol2[j].emplace_back(j - k);
					dp2[j] = cur;
				}
			}
			swap(dp1, dp2);
			swap(sol1, sol2);
			fill(dp2.begin(), dp2.end(), 0);
			fill(sol2.begin(), sol2.end(), vector<int>());
		}
		
		return sol1[n];
	}
};