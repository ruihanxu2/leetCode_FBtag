class Solution {
	map<vector<int>, int> memo;
	vector<int> target;
	vector<vector<int> > stickers;
	vector<int> convert(string s){
		vector<int> res(26, 0);
		for(auto c : s){
			res[c - 'a']++;
		}
		return res;
	}
	vector<int> subVector(vector<int>& target, vector<int>& s){
		vector<int> res(26, 0);
		for(int i = 0; i < 26; i++){
			res[i] = max(res[i], (target[i] - s[i]));
		}
		return res;
		
	}
	
	int dfs(vector<int> target){
		
		if(memo.count(target)){
			return memo[target];
		}
		memo[target] = 999999;
		for(auto& s : stickers){
			vector<int> next = subVector(target, s);
			if(memo.count(next)){
				memo[target] = min(memo[target], memo[next] + 1);
			}
			else{
				memo[target] = min(memo[target], dfs(next) + 1);
			}
		}
		return memo[target];
		
	}
public:
	
	
	int minStickers(vector<string>& stickers_, string target_) {
		target = convert(target_);
		for(auto& s : stickers_){
			stickers.emplace_back(convert(s));
		}
		memo[vector<int>(26, 0)] = 0;
		int res = dfs(target);
		return res == 999999 ? -1 : res;
		
		
	}
};
//------------------optimized
class Solution {
	map<vector<int>, int> memo;
	vector<int> target;
	vector<vector<int> > stickers;
	vector<int> convert(string s){
		vector<int> res(26, 0);
		for(auto c : s){
			res[c - 'a']++;
		}
		return res;
	}
	vector<int> subVector(vector<int>& target, vector<int>& s){
		vector<int> res(26, 0);
		for(int i = 0; i < 26; i++){
			res[i] = max(res[i], (target[i] - s[i]));
		}
		return res;
		
	}
	
	int dfs(vector<int> target){
		
		if(memo.count(target)){
			return memo[target];
		}
		memo[target] = 999999;
        // optimize: at least can get one letter
        int first;
        for(int i = 0; i < 26; i++){
            if(target[i]!=0){
                first = i;
                break;
            }
        }
		for(auto& s : stickers){
            if(s[first] == 0) continue;
			vector<int> next = subVector(target, s);
			if(memo.count(next)){
				memo[target] = min(memo[target], memo[next] + 1);
			}
			else{
				memo[target] = min(memo[target], dfs(next) + 1);
			}
		}
		return memo[target];
		
	}
public:
	
	
	int minStickers(vector<string>& stickers_, string target_) {
		target = convert(target_);
		for(auto& s : stickers_){
			stickers.emplace_back(convert(s));
		}
		memo[vector<int>(26, 0)] = 0;
		int res = dfs(target);
		return res == 999999 ? -1 : res;
		
		
	}
};




//----------------same idea but optimized to not tle;

class Solution {
	unordered_map<string, int> memo;
	vector<int> target;
	vector<vector<int> > stickers;
	
	vector<int> convert(string s){
		vector<int> res(26, 0);
		for(auto c : s){
			res[c - 'a']++;
		}
		return res;
	}
	vector<int> subVector(vector<int>& target, vector<int>& s){
		vector<int> res(26, 0);
		for(int i = 0; i < 26; i++){
			res[i] = max(res[i], (target[i] - s[i]));
		}
		return res;
		
	}
	
	int dfs(string target){
		vector<int> targetFreq = convert(target);
		if(memo.count(target)){
			return memo[target];
		}
		memo[target] = 999999;
		for(auto& s : stickers){
			// optimization
			if(s[target[0] - 'a'] == 0) continue;
			string next;
			
			for(int i = 0; i < 26; i ++){
				if(targetFreq[i] > s[i]) next+=string(targetFreq[i] - s[i], 'a' + i);
			}
			
			if(memo.count(next)){
				memo[target] = min(memo[target], memo[next] + 1);
			}
			else{
				memo[target] = min(memo[target], dfs(next) + 1);
			}
		}
		return memo[target];
		
	}
public:
	
	
	int minStickers(vector<string>& stickers_, string target_) {
		target = convert(target_);
		for(auto& s : stickers_){
			stickers.emplace_back(convert(s));
		}
		memo[""] = 0;
		int res = dfs(target_);
		return res == 999999 ? -1 : res;
		
		
	}
};