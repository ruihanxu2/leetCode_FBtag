class Solution {
public:
	int countSubstrings(string s) {
		int res=0;
		int n = s.size();
		vector<vector<bool>> dp(n, vector<bool>(n,false));
		
		for(int i=0;i<n;i++){
			for(int j=i;j>=0;j--){
				dp[i][j]= (s[i]==s[j]&&(i-j<3||dp[i-1][j+1]));
				if(dp[i][j]) res++;
			}
		}
		return res;
	}
};


class Solution {
public:
	int countSubstrings(string s) {
		int n = s.size();
		int ans = n;    
		
		for(int i=0;i<n;i++){
			ans += SubstringCountHelper(s, i, i+1);
			ans += SubstringCountHelper(s, i-1, i+1);
		}
		
		return ans;
	}
	
	int SubstringCountHelper(string &s, int i, int j){
		int count = 0;
		while(i>=0&&j<s.size()){
			if(s[i]!=s[j]) break;
			count++;
			i--;
			j++;
		}
		return count;
	}
};


class Solution {
public:
	int countSubstrings(string s) {
	
		string t;
		
		t += "\$";
		t += "\#";
		
		for(int i = 0 ; i < s.size() ; i++)
		{
			t += s[i];
			t += "\#";
		}
		t += "\^";
		//cout << t << endl;
		
		int C = 0, R = 0;
		vector<int> radix(t.size(),0);
		
		for(int i = 1 ; i < t.size()-1 ; i++)
		{
			if(R>i) radix[i] = min(R-i,radix[2*C-i]);
			while(t[i+radix[i]] == t[i-radix[i]])   
			{
				
				radix[i]++;
			}
			//cout << i << " " << radix[i] << endl;
			if(i+radix[i] > R)
			{
				C = i;
				R =radix[i];
			}
		}
		int out = 0;
		for(int d : radix)  out += (d/2);
		
		
		return out;
	}
};