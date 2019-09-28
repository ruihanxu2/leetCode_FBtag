class Solution {
	string num;
	int target; 
	vector<string> res;
	vector<string> cur;
public:
	void dfs(long curVal, long prevOp, long curOp, int pos){
		if(pos == num.size()){
			if(curVal == target && curOp == 0){
				// found
				string tmp;
				for(int i = 1; i < cur.size(); i++){
					tmp += cur[i];
				}
				res.emplace_back(tmp);
			}
			return;
		}
		
		
		curOp = curOp * 10 + (num[pos] - '0');
	
		// NoOp
		if(curOp != 0) dfs(curVal, prevOp, curOp, pos + 1);
		
		
		string curOpStr = to_string(curOp);
		//add
		cur.emplace_back("+");
		cur.emplace_back(curOpStr);
		dfs(curVal + curOp, curOp, 0, pos + 1);
		cur.pop_back();
		cur.pop_back();
		
		if(!cur.empty()){
		//minus
			cur.emplace_back("-");
			cur.emplace_back(curOpStr);
			dfs(curVal - curOp, -curOp, 0, pos + 1);
			cur.pop_back();
			cur.pop_back();
			
		//multi
			cur.emplace_back("*");
			cur.emplace_back(curOpStr);
			dfs(curVal - prevOp + prevOp * curOp,  prevOp * curOp , 0, pos + 1);
			cur.pop_back();
			cur.pop_back();
		}
	}
	vector<string> addOperators(string num, int target) {
		this->num = num;
		this->target = target;
		dfs(0, 0, 0, 0);
		return res;
	}
};