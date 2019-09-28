// two pass
int longestValidParentheses(string str) {
	// three cases 
	// l > r
	// l == r
	// r > l
	// -> deal with 2, 3
	// <- deal with 1, 3
	int left = 0;
	int right = 0;
	int res = 0;
	for(auto c:str){
		if(c == '('){
			left++;
		}
		else{
			right++;
			if(right == left){
				res = max(res, left + right);
			}
			else if(right > left){
				left = 0;
				right = 0;
			}
		}
	}
	left = 0;
	right = 0;
	reverse(str.begin(), str.end());
	for(auto c:str){
		if(c == ')'){
			right++;
		}
		else{
			left++;
			if(right == left){
				res = max(res, left + right);
			}
			else if(left>right){
				left = 0;
				right = 0;
			}
		}
	}
	return res;
}


//stack----------------------
// put a fake left brackest on the very beginning to deal with ()()
int longestValidParentheses(string s) {
	stack<int> stk;
	stk.emplace(-1);
	int res = 0;
	for(int i = 0; i < s.size(); i++){
		if(s[i] == '('){
			stk.emplace(i);
		}
		else{
			stk.pop();
			if(stk.empty()){
				stk.emplace(i);
			}
			else{
				res = max(res, i - stk.top());
			}
		}
	}
	return res;
}

//dp---------------------------
dp is longest ending at this pos
must get a len at ')'
two conditions
...() dp[i] = dp[i-2]+2
((())) dp[i] = dp[i-1] + 2 {if (s[i - dp[i-1] - 2] is '('} + dp[i - dp[i-1] - 2] //if ()(()) 

int longestValidParentheses(string s) {
	int n = s.size();
	vector<int> dp(n + 1,0);
	for(int i = 2; i <= n; i++){
		if(s[i-1] ==')'){
			if(s[i-2] == '('){
				dp[i] = dp[i-2] + 2;
			}
			else{
				// s[i - 2] == )
				if(i - dp[i-1] - 2 >= 0 && s[i - dp[i-1] - 2] == '('){
					dp[i] = dp[i-1] + 2 + dp[i - dp[i-1] - 2];
				}
			}
		}
	}
	return *max_element(dp.begin(), dp.end());
}

