// (**( where * can be nothing, left bracket or right bracket
class Solution {
public:
	bool checkValidString(string s) {
		int lb = 0;
		int ub = 0;
		for(auto& c : s){
			if(c == '('){
				lb++;
				ub++;
			}
			else if(c ==')'){
				lb--;
				ub--;
			}
			else{
				// *
				lb--;
				ub++;
			}
			
			if(ub < 0) return false;
			lb = max(lb, 0); // (**(
		}
		
		return lb == 0;
	}
};
