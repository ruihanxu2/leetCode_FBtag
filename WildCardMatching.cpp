class Solution_ {
public:
	bool isMatch(string s, string p) {
		int n1 = p.size();
		int n2 = s.size();
		vector<vector<bool> > dp(n1 + 1, vector<bool>(n2 + 1, false));
		dp[0][0] = true;
		for(int i = 1; i <= n1; i++){
			for(int j = 0; j <= n2; j++){
				if(p[i-1] == '*'){
					if(j == 0){
						dp[i][j] = dp[i-1][j];
					}
					else{
						dp[i][j] = dp[i-1][j]||dp[i-1][j-1]||dp[i][j-1];
					}
				}
				else if(p[i-1] == '?'){
					if(j != 0){
						dp[i][j] = dp[i - 1][j - 1];
					}
				}
				else if(j > 0 && p[i-1] == s[j-1]){
					dp[i][j] = dp[i - 1][j - 1];
				}
			}    
		}
		return dp[n1][n2];
	}
};

class Solution {
public:
	bool isMatch(string s, string p) {
		int n1 = p.size();
		int n2 = s.size();
		vector<bool> dp(n2 + 1, false);
		dp[0] = true;
		for(int i = 1; i <= n1; i++){
			vector<bool> cur(n2 + 1, false);
			for(int j = 0; j <= n2; j++){
				
				if(p[i-1] == '*'){
					if(j == 0){
						 cur[j] = dp[j];
					}
					else{
						cur[j] = dp[j-1]||cur[j-1]||dp[j];
						
					}
				}
				else if(p[i-1] == '?'){
					if(j != 0){
						cur[j] = dp[j-1];
					}
				}
				else if(j > 0 && p[i-1] == s[j-1]){
					cur[j] = dp[j-1];
				}
			}
			swap(cur, dp);
		}
		return dp[n2];
	}
};