class Solution {
public:
	int myAtoi(string s) {
		int i = 0, n = s.size();
		int res = 0;
		while(i < n && s[i] == ' '){i++;}
		int sign = 1;
		if(s[i] == '+' || s[i] == '-'){
			sign = 1 - 2*(s[i] == '-');
			i++;
		}
		
		while(isdigit(s[i])){
			if(res > INT_MAX/10 || res == INT_MAX/10 && (s[i] - '0') > 7){
				return sign == 1? INT_MAX : INT_MIN;
			}
			res = res*10 + (s[i++] - '0');
		}
		return sign*res;
	}
};