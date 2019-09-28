// expand from center
class Solution {
public:
	int expandFromCenter(string& s, int l, int r){
		int res = 0;
		while(l >= 0 && r < s.size() && s[l] == s[r]){
			res++;
			l--;
			r++;
		}
		return res;
	}
	string longestPalindrome(string s) {
		int start = 0; 
		int len = -1;
		if(s.size() == 0 || s.size() == 1) return s;
		for(int i = 0; i < s.size(); i++){
			int len1 = expandFromCenter(s, i, i)  * 2 - 1;
			int len2 = expandFromCenter(s, i, i + 1) * 2;
			if(len1 > len){
				start = i - (len1 - 1) / 2;
				len = len1;
				
			}
			if(len2 > len){
				start = i - (len2 - 1) / 2;
				len = len2;
			}
		}
		return s.substr(start, len);
	}
};

// Manacher
class Solution {
public:
	string longestPalindrome(string s) {
		string t = "*#";//*为的是让t字符串出了指针
		for (int i = 0; i < s.size(); ++i) {
			t += s[i];
			t += "#";
		}
		vector<int> p(t.size(),0);
		int mx = 0, id = 0, resLen = 0, resCenter = 0;//max是最远边界
		for (int i= 1; i < t.size(); ++i) {
			p[i] = mx > i ? min(p[2 * id - i], mx - i) : 1;//p[2 * id - i]边界内    mx-1 边界上 
			while (t[i + p[i]] == t[i - p[i]]) ++p[i];//在p[i]+t位置检查一下是否下字符一个相等，
			if (mx <= i + p[i]) {
				mx = i + p[i];
				id = i;//到达边界max，的点
			}
			if (resLen < p[i]) {
				resLen = p[i];
				resCenter = i;
			}
		}
		return s.substr((resCenter - resLen) / 2, resLen - 1);
		
	}
	
};