class Solution {
public:
	int minAddToMakeValid(string S) {
		int left = 0;
		int res = 0;
		for(auto c : S){
			if(c == '('){
				left++;
			}
			else if(c == ')'){
				if(left == 0) res++;
				else left --;
			}
		}
		return left + res;
	}
};