class Solution {
public:
	int reverse(int x) {
		int res = 0;
		
		while(x != 0){
			if( res > INT_MAX / 10 || (res == INT_MAX / 10 && x%10 > 7) ) return 0;
			if( res < INT_MIN / 10 || (res == INT_MIN / 10 && x%10 < -8) ) return 0;
			res = res * 10 + x % 10;
			x/=10;
		}
		return res;
	}
	
	int reverse1(int x) {
		long res = 0;
		while(x!= 0){
			int pop = x%10;
			x/=10;
			res = res*10 + pop;
		}
		if(res > INT_MAX || res < INT_MIN) return 0;
		return res;
	}
	
	int reverse2(int x) {
		long res = 0;
		long mul = 1;
		stack<int> s;
		while(x != 0){
			s.emplace(x%10);
			x/=10;
		}
		while(!s.empty()){
			res+=s.top()*mul;
			s.pop();
			mul*=10;
		}
		if(res > INT_MAX || res < INT_MIN) return 0;
		return res;
	}
};