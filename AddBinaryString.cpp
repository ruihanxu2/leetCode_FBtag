class Solution {
public:
	string addBinary(string a, string b) {
		int na = a.size();
		int nb = b.size();
		string res = "";
		int carry = 0;
		for(int i = na - 1, j = nb - 1; i >=0 || j >= 0 || carry; i--, j--){
			if(i >= 0) carry += a[i] - '0';
			if(j >= 0) carry += b[j] - '0';
			// 0, 1, 2, 3
			char cur = carry % 2 +'0';
			res+=cur;
			carry /= 2;
		}
		reverse(res.begin(), res.end());
		return res;
	}
};