class Solution_naivedp {
public:
	//naive dp
	vector<vector<int> > dp;
	string word1;
	string word2;
	int helper(int i, int j){
		
		if(i == word1.size() || j == word2.size()){
			return max( word1.size() - i,  word2.size() - j );
		}
		if(dp[i][j] != -1) return dp[i][j];
		
		if(word1[i] == word2[j]){
			dp[i][j] = helper(i + 1, j + 1);
		}
		else{
			int a = helper(i + 1, j + 1);
			int b = helper(i , j + 1);
			int c = helper(i + 1, j );
			dp[i][j] =  min({a, b, c})  + 1;
		}
		return dp[i][j];
	}
	int minDistance(string Word1, string Word2) {
		word1 = Word1;
		word2 = Word2;
		int n1 = word1.size();
		int n2 = word2.size();
		
		dp.resize(n1, vector<int>(n2, -1));
		return helper(0, 0);        
	}
};

class Solution {
public:
	int minDistance(string word1, string word2) {
		int n1 = word1.size();
		int n2 = word2.size();
		if(n1 == 0 || n2 == 0) return max(n1, n2);
		vector<vector<int> > dp(n1 + 1, vector<int>(n2 + 1, 0));
		for(int i = 1; i <= n1; i++){
			dp[i][0] = dp[i - 1][0] + 1;
		}
		for(int j = 1; j <= n2; j++){
			dp[0][j] = dp[0][j - 1] + 1;
		}
		for(int i = 1; i <= n1; i++){
			for(int j = 1; j <= n2; j++){
				if(word1[i-1] == word2[j-1]){
					dp[i][j] = dp[i-1][j-1];
				}
				else{
					dp[i][j] = min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]}) + 1;
				}
			}    
		}
		return dp[n1][n2];
		
	}
};