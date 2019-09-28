class Solution {
	int minimumRemoved = INT_MAX;
	unordered_set<string> res;
	void helper(string& s, string& cur, int pos, int leftCount, int rightCount, int removeCount){
		if(pos == s.size()){
			if(leftCount == rightCount){
				if(removeCount > minimumRemoved) return;
				if(removeCount < minimumRemoved){
					minimumRemoved = removeCount;
					res.clear();
				}
				res.insert(cur);
			}
			return;
		}
		
		// always make sure that things are correct on the fly
		
		// remove
		char c = s[pos];
		if(c != '(' && c!=')'){
			cur+=c;
			helper(s, cur, pos + 1, leftCount, rightCount, removeCount);
			cur.pop_back();
		}
		else{
			// remove, can do any time
			helper(s, cur, pos + 1, leftCount, rightCount, removeCount + 1);
			
			//keep, need to make sure leftcount >= rightCount
			cur+=c;
			
			if(c == '('){
				helper(s, cur, pos + 1, leftCount + 1, rightCount, removeCount);
			}
			else{
				// )
				if(rightCount < leftCount){
					helper(s, cur, pos + 1, leftCount, rightCount + 1, removeCount);
				}
			}
			cur.pop_back();
			
			
			
		}
		
	}
public:
	vector<string> removeInvalidParentheses(string s) {
		string cur;
		helper(s, cur, 0, 0, 0, 0);
		return vector<string>(res.begin(), res.end());
	}
};

// ---------------------------------------------------------
class Solution_ {
private:
	unordered_set<string> res;
   
	void backtrack(int pos, int left, int right, int ltr, int rtr, string& cur, string& s){
		//base
		if(pos == s.size()){
			if(ltr == 0 && rtr == 0){
				res.insert(cur);
			}
			return;
		}
		
		
		
		// remove
		if(s[pos] == '(' && ltr > 0){
			backtrack(pos + 1, left, right, ltr-1, rtr, cur, s);
		}
		else if(s[pos] == ')' && rtr > 0){
			backtrack(pos + 1, left, right, ltr, rtr-1, cur, s);
		}
		
		//keep
		// cur will always be valid(left >= right)
		// the very end, is ltr == 0 && rtr == 0, then left == right
		cur+=s[pos];
		if(s[pos]!='(' && s[pos]!=')'){
			backtrack(pos + 1, left, right, ltr, rtr, cur, s);
		}
		else if(s[pos] == '('){
			backtrack(pos + 1, left +1, right, ltr, rtr, cur, s);
		}
		else if(s[pos] == ')' && left > right){
			backtrack(pos + 1, left, right + 1, ltr, rtr, cur, s);
		}
		cur.pop_back();
		
		
	}
public:
	vector<string> removeInvalidParentheses(string s) {
		int ltr = 0, rtr = 0;
		for(auto& c : s){
			if(c =='('){
				ltr++;
			}else if(c == ')'){
				if(ltr == 0){
					rtr++;
				}
				else{
					ltr--;
				}
			}
		}
		string cur;
		backtrack(0, 0, 0, ltr, rtr, cur, s);
		vector<string> rtn;
		for(auto s : res){
			rtn.emplace_back(s);
		}
		return rtn;
		
	}
};