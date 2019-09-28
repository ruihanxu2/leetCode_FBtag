class Solution {
public:
	bool isMatch(string s, string p) {
		int r = s.size();
		int c = p.size();	
		vector<vector<int> > dp(r+1, vector<int> (c+1 , 0));
		dp[0][0] = 1;
		int count = 1;
		while(count < c){
			if(p[count] == '*'){
				dp[0][count+1] = 1;
				count +=2;
			}
				
			else
				break;
		}
		for(int i = 1; i <= r; i++){
			for(int j = 1; j <= c; j++){
				if(s[i-1] == p[j-1]||p[j-1]=='.'){
					dp[i][j] = dp[i-1][j-1];
				   
				}
				if(p[j-1] == '*'){
					if(dp[i][j-2] == 1){
						// append zero preceding char
						dp[i][j] = 1;
						
					}
					else if (s[i-1] == p[j-2]||p[j-2] == '.') {
						// append preceding char
						dp[i][j] = dp[i-1][j];
						
					}
				}
			} 
		}
		return dp[r][c];
	}
};