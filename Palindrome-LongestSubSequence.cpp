class Solution_ {
public:
	int longestPalindromeSubseq(string s) {
		// len == 1 dp[i][j] = 1
		// a***a : s[i] == s[j] : dp[i][j] = dp[i+1][j-1] + 2
		// a***b : s[i] != s[j] : dp[i][j] = max(dp[i+1][j], dp[i][j-1])
		// cuz no letters should be consective
		int n = s.size();
		vector<vector<int> > dp(n, vector<int>(n, 0)); // start point, end point
		for(int len = 1; len <= n; len++){
			for(int i = 0; i <= n - len; i++){
				int j = i + len - 1;
				if(i == j){
					dp[i][j] = 1;
				}
				else{
					if(s[i] == s[j]){
						dp[i][j] = dp[i + 1][j - 1] + 2;
					}
					else{
						dp[i][j] = max(dp[i+1][j], dp[i][j - 1]);
					}
				}
			}
		}
		return dp[0][n-1];
	}
};

// O(n)  space
class Solution {
public:
	int longestPalindromeSubseq(string s) {
	// dp[l] 只和 dp[l - 1] dp [l-2]有关
		int n = s.size();
		//vector<vector<int> > dp(n, vector<int>(n, 0)); // start point, end point
		vector<int> dp0(n, 0); // len
		vector<int> dp1(n, 0); // len - 1
		vector<int> dp2(n, 0); // len - 2
		
		for(int len = 1; len <= n; len++){
			for(int i = 0; i <= n - len; i++){
				int j = i + len - 1;
				if (i == j) {
				  dp0[i] = 1;
				}
				else{
					if(s[i] == s[j]){
						dp0[i] = dp2[i + 1] + 2;
					}
					else{
						dp0[i] = max(dp1[i+1], dp1[i]);
					}
				}
			}
			dp2 = dp1;
			dp1 = dp0;
		}
		return dp1[0];
	}
};

