class Solution {
public:
	string removeOuterParentheses(string S) {
		string res;
		int left = 0;
		int right = 0;
		int count = 0;
		for(; right < S.size(); right++){
			if(S[right] == ')'){
				count--;
				if(count == 0){
					res+=S.substr(left+1, right - left - 1);
					left = right + 1;
				}
			}
			else if(S[right] == '('){
				count++;
			}
		}
		return res;
		
	}
};
//
//Input: "(()())(())(()(()))"
//Output: "()()()()(())"