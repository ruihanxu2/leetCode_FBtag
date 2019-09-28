class Solution {
private:
	vector<string> parse(string& log){
		istringstream iss(log);
		string tmp;
		vector<string> res;
		while(getline(iss, tmp, ':')){
			res.emplace_back(tmp);    
		}
		return res;
	}
public:
	vector<int> exclusiveTime(int n, vector<string>& logs) {
		vector<int> res(n, 0);
		stack<int> s; //index;
		int pre = 0;
		for(auto& log : logs){
			vector<string> cur = parse(log);
			int id = stoi(cur[0]);
			if(cur[1] == "start"){
				
				int startTime = stoi(cur[2]);
				if(!s.empty()){
					res[s.top()] += startTime - pre;
				}
				pre = startTime;
				s.emplace(id);
			}
			else{
				int endTime = stoi(cur[2]) + 1;
				res[s.top()] += endTime - pre;
				pre = endTime;
				s.pop();
				
			}
		}
		return res;
		
	}
};