class Solution_ {
public:
	bool isPalindrome(int x) {
		string s = to_string(x);;
		string tmp = s;
		reverse(tmp.begin(), tmp.end());
		return s == tmp;
	}
};

class Solution__ {
public:
	bool isPalindrome(int x) {
		if(x < 0) return false;
		int org = x;
		long rev = 0;
		while(x > 0){
			rev = rev * 10 + x % 10;
			x /= 10;
		}
		return org == rev;
		
	}
};


class Solution {
public:
	bool isPalindrome(int x) {
		if(x < 0) return false;
		if(x % 10 == 0 && x!= 0) return false; //!!!important, try 10
		int half = 0;
		while(x > half){
			half = half * 10 + x % 10;
			x /= 10;
		}
		// same len( == or !=)
		// half has one more digit 12321 12 123
		return x == half || x == half / 10;
	}
};