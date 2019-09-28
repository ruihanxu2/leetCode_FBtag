int numDecodings(string s) {
	if(s.size() == 0) return 0;
	int n = s.size();
	vector<int> dp(n + 1, 0);
	dp[0] = 1;
	dp[1] = s[0] == '0'? 0 : 1;
	for(int i = 1; i < n; i++){
		int prev = stoi(s.substr(i-1, 2));
		if(s[i] != '0') dp[i+1] = dp[i];
		if(prev >= 10 && prev <=26){
			dp[i + 1] += dp[i - 1];
		}
	}
	return dp.back();
}

int numDecodings(string s) {
		const int M = 1000000007;
		vector<long> dp(s.size()+1, 0);
		int n = s.size();
		if(n == 0) return 0;
		dp[0] = 1;
		dp[1] = s[0] == '0' ? 0 : s[0] == '*'? 9 : 1; 
		for(int i = 1; i < n; i++){
			if(s[i] == '*'){
				dp[i+1] = (dp[i] * 9 ) % M;
				if(s[i - 1] == '1'){
					dp[i + 1] = (dp[i + 1] + dp[i - 1] * 9) % M;
				}
				else if (s[i - 1] == '2'){
					//21 22 23 24 25 26
					dp[i + 1] = (dp[i + 1] + dp[i - 1] * 6) % M;
				}
				else if(s[i - 1] == '*'){
					dp[i + 1] = (dp[i + 1] + dp[i - 1] * 15) % M;
				}
			}
			else{
				// s[i] is digit
				dp[i + 1] = s[i] == '0' ? 0 : dp[i];
				if(s[i - 1] == '1'){
					dp[i + 1] = (dp[i + 1] + dp[i - 1]) % M;
				}
				else if (s[i - 1] == '2'&& s[i] <= '6'){
					//21 22 23 24 25 26
					dp[i + 1] = (dp[i + 1] + dp[i - 1]) % M;
				}
				else if(s[i - 1] == '*'){
					if(s[i] <= '6'){
						dp[i + 1] = (dp[i + 1] + dp[i - 1] * 2) % M;
					}
					else{
						dp[i + 1] = (dp[i + 1] + dp[i - 1]) % M;
					}
				}
			}
		}
		return (int)dp.back();
	
	}