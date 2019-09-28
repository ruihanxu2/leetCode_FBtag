class Solution {
public:
	string addStrings(string num1, string num2) {
		int n1 = num1.size();
		int n2 = num2.size();
		int carry = 0;
		string res;
		for(int i = n1 - 1, j = n2 - 1; i >= 0 || j >=0; i--, j--){
			if(i >= 0) carry += num1[i] - '0';
			if(j >= 0) carry += num2[j] - '0';
			res += (carry%10 + '0');
			carry/=10;
		}
		if(carry > 0) res += (carry + '0');
		reverse(res.begin(), res.end());
		return res;
	}
};