//--------------只买一次卖一次
int maxProfit(vector<int>& prices) {
	int res = 0;
	int minPrice = INT_MAX;
	for(int i = 0; i < prices.size(); i++){
		res = max(res, prices[i] - minPrice);
		minPrice = min(minPrice, prices[i]);
	}
	return res;
}

//--------------多次买卖--只要能赚钱就是一次买卖：允许同一天卖了再买
int maxProfit(vector<int>& prices) {
	int res = 0;
	for(int i = 1 ; i < prices.size(); i++){
		if(prices[i] > prices[i - 1]){
			res+=prices[i] - prices[i - 1];
		}
	}
	return res;
}
// 不允许同一天卖了再买。。只是手法不同结果一样
int maxProfit(vector<int>& prices) {
	if(prices.size() == 0) return 0;
	int i = 0;
	int res = 0;
	int low = prices[0];
	int high = prices[0];;
	while(i < prices.size() - 1){
		while(i < prices.size() - 1 && prices[i] >= prices[i + 1]){
			i++;
		}
		low = prices[i];
		while(i < prices.size() - 1 && prices[i] <= prices[i + 1]){
			i++;
		}
		high = prices[i];
		res += high - low;
	}
	return res;
}


//最多两次交易
class Solution {
public:
	int maxProfit(vector<int>& price) {
		int n = price.size();
		if(n == 0) return 0;
		vector<int> dp1(n, 0);
		int maxBeforeSell = 0 - price[0];
		for(int i = 1; i < n; i++){
			maxBeforeSell = max(maxBeforeSell, 0 - price[i-1]);
			dp1[i] = max(dp1[i-1], maxBeforeSell + price[i]);
		}
		vector<int> dp2(n, 0);
		maxBeforeSell = 0 - price[0];
		for(int i = 1; i < n; i++){
			maxBeforeSell = max(maxBeforeSell, dp1[i-1] - price[i-1]);
			dp2[i] = max(dp2[i-1], maxBeforeSell + price[i]);
		}
		return dp2[n-1];
		
	}
};

//K次交易

class Solution2 {
public:
	int maxProfit(int k, vector<int>& prices) {
		
		int n = prices.size();
		if(n == 0) return 0;
		if (k>n/2){ // simple case
			int ans = 0;
			for (int i=1; i<n; ++i){
				ans += max(prices[i] - prices[i-1],0);
			}
			return ans;
		}
		vector<vector<int> > dp(k + 1, vector<int>(n, 0));
		for(int i = 1; i <= k; i++){
			for(int j = 1; j < n; j++){
				int maxBeforeSell = -prices[0]; // 0 之前挣了0元，然后把0买了，当前的盈利是 -price[0]
				for(int k = 1; k <= j; k++){
					maxBeforeSell = max(maxBeforeSell,dp[i-1][k-1] - prices[k]);
					dp[i][j] = max(dp[i][j-1], prices[j] + maxBeforeSell);
				}
			}
		}
		return dp[k][n-1];
		
	}
};

class Solution {
public:
	int maxProfit(int k, vector<int>& prices) {
		
		int n = prices.size();
		if(n == 0) return 0;
		if (k>n/2){ // simple case
			int ans = 0;
			for (int i=1; i<n; ++i){
				ans += max(prices[i] - prices[i-1],0);
			}
			return ans;
		}
		vector<vector<int> > dp(k + 1, vector<int>(n, 0));
		for(int i = 1; i <= k; i++){
			int maxBeforeSell = -prices[0]; // 0 之前挣了0元，然后把0买了，当前的盈利是 -price[0]
			for(int j = 1; j < n; j++){
				
				maxBeforeSell = max(maxBeforeSell,dp[i-1][j-1] - prices[j]);
				dp[i][j] = max(dp[i][j-1], prices[j] + maxBeforeSell);

			}
		}
		return dp[k][n-1];
		
	}
};